/*
ID:chenke61
PROG:stamps
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

int maxval,n,k,*f,stam[52];


int main(){
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");

    fin>>k>>n;
    for (int i = 0; i < n; i++) {
        fin>>stam[i];
        maxval=max(maxval,stam[i]);
    }
    sort(stam,stam+n);
    f=new int[k*maxval+3];
    memset(f,300,4*(k*maxval+3));
    f[0]=0;
    f[maxval*k]=k;
    for(int val=1;val<=k*maxval+1;val++){
        for(int i=0;i<n;i++){
            if(val<stam[i])
                break;
            f[val]=min(f[val],f[val-stam[i]]+1);
        }
        if(f[val]>k){
            fout<<val-1<<endl;
            break;
        }
    }


    return 0;
}






