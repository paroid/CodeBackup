/*
ID:chenke61
PROG:kimbits
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

/*ifstream fin("in");
  ofstream fout("out");*/

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

unsigned int N,L,I,ZL,dp[33][33];
short ans[38];

int count(int i,int j){
    if(dp[i][j])
        return dp[i][j];
    return dp[i][j]=count(i-1,j)+count(i-1,j-1);
}


string conv(int n){
    string res,tmp;
    int l;
    while(n){
        tmp+=(n&1)?"1":"0";
        n>>=1;
    }
    l=tmp.length();
    for(int i=0;i<N-l;i++)
        res+="0";
    for(int j=l-1;j>=0;j--)
        res+=tmp[j];
    return res;
}

int main(){
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");

    fin>>N>>L>>I;
    long long cnt=0,i=0,low=1<<L;
    for(int i=0;i<33;i++)
        dp[i][0]=dp[0][i]=1;

    if(N==L)
        fout<<conv(I-1)<<endl;
    else if(I==1)
        fout<<conv(0)<<endl;
    else{
        for(int i=N-1;i>=0;i--){
            if(count(i,L)<I){
                ans[i]=1;
                I-=count(i,L--);
            }
        }
        for(int i=N-1;i>=0;i--)
            fout<<ans[i];
        fout<<endl;
    }


    return 0;
}






