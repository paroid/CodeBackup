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

class DropCoins {
public:
    int sum[32][32],m,n;
	int getMinimum(vector <string>, int);
    void calsum(vector <string> board);
    int getsum(int x1,int y1,int x2,int y2);
    int calans(int a,int b);
};

int DropCoins::calans(int a,int b){
    if(a>b)
        swap(a,b);
    return 2*a+b;
}

void DropCoins::calsum(vector <string> board){
    for(int i=0;i<32;i++)
        memset(sum[i],0,sizeof(sum[i]));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            sum[i][j]+=int(board[i-1][j-1]=='o');
        }
    }
}

int DropCoins::getsum(int x1,int y1,int x2,int y2){
    return sum[x1][y1]+sum[x2][y2]-sum[x2][y1]-sum[x1][y2];
}

int DropCoins::getMinimum(vector <string> board, int K) {
    int min=999999;
    m=board.size();
    n=board[0].length();
    calsum(board);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cout<<sum[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            for(int p=i+1;p<=m;p++)
                for(int q=j+1;q<=n;q++){
                    int res=getsum(i,j,p,q);
                    cout<<i<<"-"<<j<<"   "<<p<<"-"<<q<<"   ="<<res<<endl;
                    if(res==K){
                        int ans=0;
                        ans+=calans(i,m-p);
                        ans+=calans(j,n-q);
                        if(ans<min)
                            min=ans;
                    }
                }
    return min==999999?-1:min;

}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!


