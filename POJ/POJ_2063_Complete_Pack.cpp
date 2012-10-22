#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

int dp[50000],cost[41],val[41],m,n,t,y;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    cin>>t;
    while(t--){
        cin>>m>>y>>n;
        for(int i=1;i<=n;i++){
            cin>>cost[i]>>val[i];
            cost[i]/=1000;
        }
        while(y--){
            memset(dp,0,sizeof(dp));
            int tt=m/1000;
            for(int i=1;i<=n;i++)
                for(int j=cost[i];j<=tt;j++)
                    dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
            m+=dp[tt];
        }
        cout<<m<<endl;
    }

    return 0;
}

