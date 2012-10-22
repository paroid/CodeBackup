#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
long long plist[78500],pcount=0;
const int maxTest=240;

long long random(long long n){
    return (long long)((double)rand()/RAND_MAX*n+0.5);
}

long long mod_exp(long long a,long long b,long long n){
    long long ans;
    if(b==1) 
        return a%n;
    ans=mod_exp(a,b/2,n);
    if(b%2==0) return ans*ans%n;
    else return ans*ans%n*a%n;
}

bool miller_rabbin(long long n){
    if(n==1 || (n!=2&&!(n%2)) || (n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return false;
    for(long i=1;i<=maxTest;i++){
        long long a=random(n-2)+1;
        if(mod_exp(a,n-1,n)!=1)
            return false;
    }
    return true;
}

int prime(int n){
    int i;
    if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return 0;
    for (i=0;plist[i]*plist[i]<=n;i++)
        if (!(n%plist[i]))
            return 0;
    return n>1;
}

void initprime(){
    int i;
    for (plist[pcount++]=2,i=3;i<1000000;i++)
        if (miller_rabbin(i))
            plist[pcount++]=i;
}

long long BigGCD(long long x,long long y){
    if(y>x)
        return BigGCD(y,x);
    if(!y)
        return x;
    if(x&1)
        if(y&1)
            return BigGCD(y,x-y);
        else
            return BigGCD(x,y>>1);
    else if(y&1)
        return BigGCD(x>>1,y);
    else
        return BigGCD(x>>1,y>>1)<<1;
}

class FractionInDifferentBases {
    public:
        long long getNumberOfGoodBases(long long, long long, long long, long long);
};

long long FractionInDifferentBases::getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
    if(!P || Q==1)
        return 0;
    if(P>Q)
        P%=Q;
    long long gcd=BigGCD(P,Q);
    Q/=gcd;
    if(Q==1)
        return 0;
	srand(time(0));
    initprime();
    cout<<pcount<<endl;
    int i=0;
    long long factor=1;
    if(miller_rabbin(Q))
        factor=Q;
    else
        while(Q!=1 && i<pcount){
            //cout<<"Q: "<<Q<<" "<<plist[i]<<endl;
            if(!(Q%plist[i])){
                factor*=plist[i];
            }
            ++i;
        }
    cout<<"over"<<endl;
    long long res=0;
    for(long long base=A;base<=B;++base){
        if(base%factor)
            ++res;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

