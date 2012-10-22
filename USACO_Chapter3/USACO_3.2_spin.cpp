/*
ID:chenke61
PROG:spin
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

int angle[360],speed[5],num[5],wedge[5][5][2],t;

bool test(){
    for(int i=0;i<360;i++)
        if(angle[i]>=5)
            return true;
    return false;
}


int main(){
    ifstream fin("spin.in");
    ofstream fout("spin.out");

    for(int i=0;i<5;i++){
        fin>>speed[i]>>num[i];
        for(int j=0;j<num[i];j++){
            fin>>wedge[i][j][0]>>wedge[i][j][1];
            for(int k=wedge[i][j][0];k<=wedge[i][j][0]+wedge[i][j][1];angle[(k++)%360]++);
        }
    }
    for(t=0;t<360;t++){
        if(test()){
            fout<<t<<endl;
            break;
        }
        memset(angle,0,sizeof(angle));
        for(int i=0;i<5;i++)
            for(int j=0;j<num[i];j++){
                wedge[i][j][0]=(wedge[i][j][0]+speed[i])%360;
                for(int k=wedge[i][j][0];k<=wedge[i][j][0]+wedge[i][j][1];angle[(k++)%360]++);
            }
    }
    if(t==360)
        fout<<"none"<<endl;

    return 0;
}






