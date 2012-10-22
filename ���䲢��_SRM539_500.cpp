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

class Over9000Rocks {
    public:
        int countPossibilities(vector <int>, vector <int>);
};

typedef struct _sec {
    int a,b;
    int getLength(){
        return b-a+1;
    }
    void copyFrom(se obj){
        a=obj.a;
        b=obj.b;
    }
    void form(int a,int b){
        this.a=a;
        this.b=b;
    }
} se;
bool cmp(se a,se b){
    return a.a<b.a;
}
int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
    int n=lowerBound.size(),res=0,t=0,tc=0;
    int k=1<<n;
    se sec[32768],ans[32768];
    for(int i=0;i<k;++i){
        int a=0,b=0,p=i;
        for(int j=0;j<n;++j){
            if(p&1){
                a+=lowerBound[j];
                b+=upperBound[j];
            }
            p>>=1;
        }
        a=a>9000?a:9001;
        if(b>=a){
            sec[t].a=a;
            sec[t++].b=b;
        }
    }
    sort(sec,sec+t,cmp);
    for(int i=0;i<t;++i){
        if(tc && sec[i].a<=ans[tc-1].b)
            ans[tc-1].b=max(ans[tc-1].b,sec[i].b);
        else{
            ans[tc].a=sec[i].a;
            ans[tc++].b=sec[i].b;
        }
    }
    for(int i=0;i<tc;++i)
        res+=ans[i].b-ans[i].a+1;
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

