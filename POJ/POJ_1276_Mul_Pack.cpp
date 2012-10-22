#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

int dp[100008],price[11],amount[11],cash,n;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    while(cin>>cash){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>amount[i]>>price[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(price[i]*amount[i]>=cash)
                for(int j=price[i];j<=cash;j++)
                    dp[j]=max(dp[j],dp[j-price[i]]+price[i]);
            else{
                int k=1;
                while(k<amount[i]){
                    for(int j=cash;j>=price[i]*k;j--)
                        dp[j]=max(dp[j],dp[j-price[i]*k]+price[i]*k);
                    amount[i]-=k;
                    k<<=1;
                }
                if(amount[i])
                    for(int j=cash;j>=price[i]*amount[i];j--)
                        dp[j]=max(dp[j],dp[j-price[i]*amount[i]]+price[i]*amount[i]);
            }
        }
        cout<<dp[cash]<<endl;
    }

    return 0;
}

