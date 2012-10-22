#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

int dp[60008],amount[7],sum;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int ser=1;
    while(1){
        sum=0;
        for(int i=1;i<=6;i++){
            cin>>amount[i];
            sum+=i*amount[i];
        }
        if(!sum)
            break;
        cout<<"Collection #"<<ser++<<":"<<endl;
        if(sum&1)
            cout<<"Can't be divided.\n"<<endl;
        else{
            sum>>=1;
            memset(dp,-999999,sizeof(dp));
            dp[0]=0;
            for(int i=1;i<=6;i++){
                if(i*amount[i]>=sum)
                    for(int j=i;j<=sum;j++)
                        dp[j]=max(dp[j],dp[j-i]+i);
                else{
                    int k=1;
                    while(k<amount[i]){
                        for(int j=sum;j>=i*k;j--)
                            dp[j]=max(dp[j],dp[j-i*k]+i*k);
                        amount[i]-=k;
                        k<<=1;
                    }
                    if(amount[i])
                        for(int j=sum;j>=i*amount[i];j--)
                            dp[j]=max(dp[j],dp[j-i*amount[i]]+i*amount[i]);
                }
            }
            if(dp[sum]>0)
                cout<<"Can be divided.\n"<<endl;
            else
                cout<<"Can't be divided.\n"<<endl;
        }

    }

    return 0;
}

