/*
ID:chenke61
PROG:inflate
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
#define MAXN 10002
const int inf=-9999999;
int n,m,cost[MAXN],point[MAXN],dp[MAXN];


int main(){
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");

    fin>>m>>n;
    for(int i=0;i<n;i++)
        fin>>point[i]>>cost[i];
    dp[0]=0;
    for(int i=0;i<n;i++)
        for(int j=cost[i];j<=m;j++)
            dp[j]=max(dp[j],dp[j-cost[i]]+point[i]);

    fout<<dp[m]<<endl;

    return 0;
}






