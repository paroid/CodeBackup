#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

int dp[12881],cost[3404],val[3404],m,n;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>cost[i]>>val[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=m;j>=cost[i];j--)
            dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
    cout<<dp[m]<<endl;

    return 0;
}

