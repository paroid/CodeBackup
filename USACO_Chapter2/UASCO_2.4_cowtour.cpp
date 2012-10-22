/*
ID:chenke61
PROG:cowtour
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
#define MAXN 160
const double inf=10000000;

int n,pos[MAXN][2];
double mat[MAXN][MAXN],minn[MAXN][MAXN],maxx[MAXN],g[MAXN],ans=inf;
int grp[MAXN];

void floyd_warshall(){
    int i,j,k;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++){
            minn[i][j]=mat[i][j];
        }
    for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (minn[i][k]+minn[k][j]<minn[i][j])
                    minn[i][j]=minn[i][k]+minn[k][j];
}

double dist(int a,int b){
    return sqrt((pos[a][0]-pos[b][0])*(pos[a][0]-pos[b][0])+(pos[a][1]-pos[b][1])*(pos[a][1]-pos[b][1]));
}

int main(){
    ifstream fin("cowtour.in");
      ofstream fout("cowtour.out");

    fin>>n;
    for(int i=0;i<n;i++){
        fin>>pos[i][0]>>pos[i][1];
    }
    char tmp;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            mat[i][j]=mat[j][i]=i==j?0:inf;
            fin>>tmp;
            if(j<i && tmp=='1'){
                mat[i][j]=mat[j][i]=dist(i,j);
            }
        }
    floyd_warshall();

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(minn[i][j]!=inf)
                maxx[i]=max(maxx[i],minn[i][j]);

    /*for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
      fout<<setw(10)<<setiosflags(ios::fixed)<<setprecision(6)<<minn[i][j]<<" ";
      fout<<endl;
      }*/

    for(int i=0;i<n;i++){
        if(grp[i])
            continue;
        for(int j=0;j<n;j++){
            if(!grp[j] && minn[i][j]<inf){
                grp[j]=i;
                g[i]=max(g[i],maxx[j]);
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++){
            if(grp[i]!=grp[j]){
                double tt=maxx[i]+maxx[j]+dist(i,j);
                ans=min(ans,max(max(g[grp[i]],g[grp[j]]),tt));
            }
        }
    fout<<setiosflags(ios::fixed)<<setprecision(6)<<ans<<endl;

    return 0;
}





