/*
ID:chenke61
PROG:fracdec
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

int a,b,r,w,len,d,frac,tmp,cir[100000],pre;

int pp(int n,int k){
    int res=0;
    while(n && !(n%k)){
        res++;
        n/=k;
    }
    return res;
}

int le(int n){
    int res=0;
    while(n){
        n/=10;
        res++;
    }
    return res;
}

void solve(){
    if(a>=b){
        d=a/b;
        a%=b;
    }
    //fout<<"d= "<<d<<endl;
    w=pp(b,2)-pp(a,2);
    w=max(r,pp(b,5)-pp(a,5));
    //fout<<"rl= "<<r<<endl;
    frac=int(a*pow(10,w));
    r=frac%b;
    frac/=b;
    /*fout<<"frac= "<<frac<<endl;
      fout<<"r= "<<r<<endl;*/
    len=0;
    tmp=r;
    while(1){
        tmp*=10;
        cir[len++]=tmp/b;
        /*fout<<cir<<" - "<<cir%b<<endl;*/
        if(tmp%b==r){
            //cir/=b;
            break;
        }
        tmp%=b;
    }
}

int main(){
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");

    fin>>a>>b;
    solve();
    fout<<d<<".";
    pre=le(d);
    if(!pre)
        pre++;
    pre+=w+2;
    if(frac || !r)
        fout<<setw(w)<<setfill('0')<<frac;
    if(r){
        fout<<"(";
        for(int i=0;i<len;i++){
            if(!((i+pre)%76))
                fout<<endl;
            fout<<cir[i];
        }
        if(!(len+pre)%76)
            fout<<endl;
        fout<<")";
    }
    fout<<endl;

    return 0;
}





