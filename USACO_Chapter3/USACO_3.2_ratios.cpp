/*
ID:chenke61
PROG:ratios
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

int mat[3][4],bc[3][4];
long long A,B,C,D;

int cal(){
    return mat[0][0]*(mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2])-mat[1][0]*(mat[0][1]*mat[2][2]-mat[0][2]*mat[2][1])+mat[2][0]*(mat[0][1]*mat[1][2]-mat[0][2]*mat[1][1]);
}

int main(){
    ifstream fin("ratios.in");
      ofstream fout("ratios.out");

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++)
            fin>>mat[j][(i+3)%4];
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            bc[i][j]=mat[i][j];

    D=cal();
    for(int j=0;j<3;j++)
        mat[j][0]=bc[j][3],mat[j][2]=bc[j][2];
    A=cal();
    for(int j=0;j<3;j++)
        mat[j][1]=bc[j][3],mat[j][0]=bc[j][0];
    B=cal();
    for(int j=0;j<3;j++)
        mat[j][2]=bc[j][3],mat[j][1]=bc[j][1];
    C=cal();

    if(A*D<0 || B*D<0 || C*D<0){
        fout<<"NONE"<<endl;
        return 0;
    }
    for(int i=1;i<100;i++){
        if((A*i)%D || (B*i)%D || (C*i)%D)
            continue;
        fout<<A*i/D<<" "<<B*i/D<<" "<<C*i/D<<" "<<i<<endl;
        return 0;
    }
    fout<<"NONE"<<endl;
    return 0;
}






