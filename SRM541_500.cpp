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

class AntsMeet {
public:
	int countAnts(vector <int>, vector <int>, string);
};
char ord[4002][4002];
bool flag[52];
int AntsMeet::countAnts(vector <int> x, vector <int> y, string direction) {
    int n=x.size(),res=0,t=4002;
    for(int i=0;i<n;++i){
        ++ord[x[i]=(x[i]+1000)<<1][y[i]=(y[i]+1000)<<1];
        flag[i]=true;
    }
    while(t--){
        for(int i=0;i<n;++i){
            if(!flag[i])
                continue;
            --ord[x[i]][y[i]];
            switch(direction[i]){
                case 'N':
                    if(++y[i]>4000)
                        flag[i]=false;
                    break;
                case 'S':
                    if(--y[i]<0)
                        flag[i]=false;
                    break;
                case 'W':
                    if(--x[i]<0)
                        flag[i]=false;
                    break;
                case 'E':
                    if(++x[i]>4000)
                        flag[i]=false;
                    break;
            }
            if(flag[i])
                ++ord[x[i]][y[i]];
        }
        for(int i=0;i<n;++i){
            if(!flag[i])
                continue;
            if(ord[x[i]][y[i]]>1 || !ord[x[i]][y[i]]){
                ++res;
                ord[x[i]][y[i]]=0;
                flag[i]=false;
            }
        }
    }
    return n-res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

