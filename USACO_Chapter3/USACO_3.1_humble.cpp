/*
ID:chenke61
PROG:humble
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
#define MAXN 100002
int n,m,hum[MAXN],prefix[102],p[102];

int main(){
    ifstream fin("humble.in");
    ofstream fout("humble.out");

    fin>>n>>m;
    for(int i=0;i<n;i++)
        fin>>p[i];
    hum[0]=1;
    for(int i=1;i<=m;i++){
        int mini;
        for(int j=0;j<n;j++){
            while(p[j]*hum[prefix[j]]<=hum[i-1])
                prefix[j]++;
            if(!j || p[j]*hum[prefix[j]]<mini){
                mini=p[j]*hum[prefix[j]];
            }
        }
        hum[i]=mini;
    }

    fout<<hum[m]<<endl;

    return 0;
}






