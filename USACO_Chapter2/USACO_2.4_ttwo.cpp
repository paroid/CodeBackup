/*
ID:chenke61
PROG:ttwo
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

int ax,ay,ad,bx,by,bd,t;
bool mat[10][10],st[160008];
char tmp;

int hash(int d1,int x1,int y1,int d2,int x2,int y2){
	return  d1*40000+d2*10000+x1*1000+y1*100+x2*10+y2;
}

void mov(){
	int x,y;
	x=!ad?ax-1:(ad==2?ax+1:ax);
	y=ad==1?ay-1:(ad==3?ay+1:ay);
	if(x>=0 && x<10 &&y>=0 && y<10 && !mat[x][y]){
		ax=x;
		ay=y;
	}
	else 
		ad=(ad+3)%4;
	x=!bd?bx-1:(bd==2?bx+1:bx);
	y=bd==1?by-1:(bd==3?by+1:by);
	if(x>=0 && x<10 && y>=0 && y<10 && !mat[x][y]){
		bx=x;
		by=y;
	}
	else
		bd=(bd+3)%4;
}

bool test(){
	if(ax==bx && ay==by)
		return true;
	return false;
}

int main(){
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			fin>>tmp;
			if(tmp=='F'){
				ax=i;
				ay=j;
				mat[i][j]=0;
			}
			else if(tmp=='C'){
				bx=i;
				by=j;
				mat[i][j]=0;
			}
			else if(tmp=='.')
				mat[i][j]=0;
			else 
				mat[i][j]=1;
		}
	st[hash(ad,ax,ay,bd,bx,by)]=1;
	while(1){
		mov();
		t++;
		if(test()){
			fout<<t<<endl;
			break;
		}
		int res=hash(ad,ax,ay,bd,bx,by);
		if(st[res]){
			fout<<0<<endl;
			break;
		}
		st[res]=1;
	}
	return 0;
}






