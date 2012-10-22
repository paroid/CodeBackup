/*
ID:chenke61
PROG:rect1
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

typedef struct _rect {
    int x1,y1,x2,y2,color;
    int area(){
        return (x2-x1)*(y2-y1);
    }
} rect;

rect rec[1000],tmp[99999],ori[1000];
int now,tail,newst,n,col[2502];

bool ReCross(rect a,rect b){
    return (max(a.x1,b.x1)<min(a.x2,b.x2)&&(max(a.y1,b.y1)<min(a.y2,b.y2)));
}
bool cross(int a,int b,int c,int d){
    return (b>c)&&(a<d);
}
rect add(int x1,int y1,int x2,int y2,int color){
    rect res;
    res.x1=x1;
    res.y1=y1;
    res.x2=x2;
    res.y2=y2;
    res.color=color;
    return res;
}

void cut(rect newRec){
    tmp[0]=newRec;
    tail=0;
    newst=1;
    for(int i=0;i<n;i++){
        now=tail;
        tail=newst;
        for (int j=now;j<tail;j++){
            if(ReCross(rec[i],tmp[j])){
                int a=max(rec[i].x1,tmp[j].x1);
                int b=min(rec[i].x2,tmp[j].x2);
                if(tmp[j].x1<a)
                    tmp[newst++]=add(tmp[j].x1,tmp[j].y1,a,tmp[j].y2,tmp[j].color);
                if(b<tmp[j].x2)
                    tmp[newst++]=add(b,tmp[j].y1,tmp[j].x2,tmp[j].y2,tmp[j].color);
                int c=max(rec[i].y1,tmp[j].y1);
                int d=min(rec[i].y2,tmp[j].y2);
                if(tmp[j].y1<c)
                    tmp[newst++]=add(a,tmp[j].y1,b,c,tmp[j].color);
                if(d<tmp[j].y2)
                    tmp[newst++]=add(a,d,b,tmp[j].y2,tmp[j].color);
            }
            else
                tmp[newst++]=tmp[j];
        }
    }
    for(int i=tail;i<newst;i++)
        rec[n++]=tmp[i];
}


int main(){
	ifstream fin("rect1.in");
	ofstream fout("rect1.out");

    int A,B,N;
    fin>>A>>B>>N;
    for(int i=0;i<N;i++)
        fin>>ori[i].x1>>ori[i].y1>>ori[i].x2>>ori[i].y2>>ori[i].color;
    n=0;
    rec[n++]=ori[--N];
    N--;
    while(N>=0)
        cut(ori[N--]);
	cut(add(0,0,A,B,1));
    for(int i=0;i<n;i++)
        col[rec[i].color]+=rec[i].area();
    for(int i=1;i<=2500;i++)
        if(col[i])
            fout<<i<<" "<<col[i]<<endl;

    return 0;
}






