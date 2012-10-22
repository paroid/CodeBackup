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

class ImportantSequence {
    public:
        int getCount(vector <int>, string);
};

typedef struct _equ {
    long long a,b;
    void form(long long aa,long long bb){
        a=aa,b=bb;
    }
    void from(bool xs,long long val){
        a=xs?-1:(val<0?-val:0);
        b=xs?(val>0?val:0):-1;
    }
    bool cmpA(struct _equ b){
        if(a!=-1 && b.a!=-1)
            return a<b.a;
        if(a==-1)
            return 1;
        else
            return 0;
    }
    bool cmpB(struct _equ ob){
        if(b!=-1 && ob.b!=-1)
            return b<ob.b;
        if(b==-1)
            return 0;
        else
            return 1;
    }
    void intersec(struct _equ ob){
        a=cmpA(ob)?ob.a:a;
        b=cmpB(ob)?b:ob.b;
        //cout<<a<<" ... "<<b<<endl;
        if(b!=-1 && a>=b)
            a=0,b=1;
    }
    int getL(){
        return b==-1?-1:(b-a-1);
    }
} equ;


int ImportantSequence::getCount(vector <int> B, string operators) {
    equ ans,tem;
    ans.form(0,-1);
    int n=B.size();
    long long val=0;
    bool xs=0;
    for(int i=0;i<n;++i){
        if(operators[i]=='+')
            tem.from(xs=!xs,val=B[i]-val);
        else
            tem.from(xs,val=val-B[i]);

        ans.intersec(tem);
        /*cout<<"tem: ( "<<tem.a<<" , "<<tem.b<<" )"<<endl;
        cout<<"( "<<ans.a<<" , "<<ans.b<<" )  "<<xs<<"  "<<val<<endl;*/
    }
    return ans.getL();
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!


