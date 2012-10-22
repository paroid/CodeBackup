/*
ID:chenke61
PROG:agrinet
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
#define MAXN 100

const int inf=100000000;
int n,mat[MAXN][MAXN],grp[MAXN];

int prim(){
    int min[MAXN],ret=0;
    int v[MAXN],i,j,k;
    for (i=0;i<n;i++)
        min[i]=inf,v[i]=0;
    for (min[j=0]=0;j<n;j++){
        for (k=-1,i=0;i<n;i++)
            if (!v[i]&&(k==-1||min[i]<min[k]))
                k=i;
        for (v[k]=1,ret+=min[k],i=0;i<n;i++)
            if (!v[i]&&mat[k][i]<min[i])
                min[i]=mat[k][i];
    }
    return ret;
}



int main(){
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");

    fin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fin>>mat[i][j];
    fout<<prim()<<endl;

    return 0;
}






