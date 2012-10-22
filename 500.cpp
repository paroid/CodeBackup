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

class DucksAlignment {
public:
	int minimumTime(vector <string>);
};

int DucksAlignment::minimumTime(vector <string> grid) {
    int m=grid.size(),n=grid[0].length(),ans=-1,tans,mid,x[60],y[60],duck=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(grid[i][j]=='o'){
                x[duck]=i;
                y[duck++]=j;
            }
        }
    sort(x,x+duck);
    sort(y,y+duck);
    mid=x[duck/2];
    tans=0;
    for(int i=0;i<duck;i++)
        tans+=abs(x[i]-mid);
    int tcmin=-1;
    for(int k=0;k<=n-duck;k++){
        int cc=0;
        for(int i=0;i<duck;i++){
            cc+=abs(y[i]-(k+i));
        }
        if(tcmin==-1 || cc<tcmin)
            tcmin=cc;
    }
    tans+=tcmin;
    mid=y[duck/2];
    ans=0;
    for(int i=0;i<duck;i++)
        ans+=abs(y[i]-mid);
    tcmin=-1;
    for(int k=0;k<=m-duck;k++){
        int cc=0;
        for(int i=0;i<duck;i++)
            cc+=abs(x[i]-(k+i));
        if(tcmin==-1 || cc<tcmin)
            tcmin=cc;
    }
    ans+=tcmin;
    if(ans>tans)
        ans=tans;
    return ans;

}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!


