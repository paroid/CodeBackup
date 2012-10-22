/*
ID:chenke61
PROG:shopping
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

int f[6][6][6][6][6],p[108][8],s,b,m[1008];
int ori[100][8][2],aa,bb,n;

int dp(int a1,int a2,int a3,int a4,int a5){
    if(!a1 && !a2 && !a3 && !a4 && !a5)
        return 0;
    if(f[a1][a2][a3][a4][a5])
        return f[a1][a2][a3][a4][a5];
    int mm=9999999;
    for(int i=0;i<s;++i){
        if(a1>=p[i][1] && a2>=p[i][2] && a3>=p[i][3] && a4>=p[i][4] && a5>=p[i][5]){
            int tmp=dp(a1-p[i][1],a2-p[i][2],a3-p[i][3],a4-p[i][4],a5-p[i][5])+p[i][0];
            mm=min(tmp,mm);
        }
    }
    return f[a1][a2][a3][a4][a5]=mm;
}

bool check(int a){
    if(!a)
        return true;
    return m[a];
}


int main(){
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");


    fin>>s;
    for(int i=0;i<s;++i){
        fin>>n;
        for(int j=1;j<=n;++j){
            fin>>aa>>bb;
            ori[i][j][0]=aa;
            ori[i][j][1]=bb;
        }
        fin>>n;
        ori[i][0][0]=n;
    }
    fin>>b;
    for(int i=0;i<b;++i){
        fin>>aa>>bb>>n;
        p[i][0]=n;
        p[i][i+1]=bb;
        m[aa]=i+1;
    }
    n=b;
    for(int i=0;i<s;++i){
        if(check(ori[i][1][0]) && check(ori[i][2][0]) && check(ori[i][3][0]) && check(ori[i][4][0]) && check(ori[i][5][0])){
            for(int j=1;j<=5 && ori[i][j][0];++j){
                p[n][0]=ori[i][0][0];
                p[n][m[ori[i][j][0]]]=ori[i][j][1];
            }
            ++n;
        }
    }
    s=n;
    for(int i=0;i<5;++i){
        m[i]=p[i][i+1];
        if(i<b)
            p[i][i+1]=1;
    }
    fout<<dp(m[0],m[1],m[2],m[3],m[4])<<endl;


    return 0;
}






