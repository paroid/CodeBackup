/*
ID:chenke61
PROG:maze1
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

/*ifstream fin("in");
  ofstream fout("out");*/

#define min(a,b) ((a)<(b)?(a):(b))

int head,len,que[4000][2],minn[100][38],maxx,x[2],y[2];
int h,w;
bool st[100][38];
char mat[212][80];

void bfs(){
	while(head<len){
		int x=que[head][0],y=que[head][1];
		if(x>0 && mat[2*x][2*y+1]==' ' && !st[x-1][y]){
			minn[x-1][y]=min(minn[x][y]+1,minn[x-1][y]);
			que[len][0]=x-1;
			que[len++][1]=y;
			st[x-1][y]=1;
		}
		if(x<h-1 && mat[2*x+2][2*y+1]==' ' && !st[x+1][y]){
			minn[x+1][y]=min(minn[x][y]+1,minn[x+1][y]);
			que[len][0]=x+1;
			que[len++][1]=y;
			st[x+1][y]=1;
		}
		if(y>0 && mat[2*x+1][2*y]==' ' && !st[x][y-1]){
			minn[x][y-1]=min(minn[x][y]+1,minn[x][y-1]);
			que[len][0]=x;
			que[len++][1]=y-1;
			st[x][y-1]=1;
		}
		if(y<w-1 && mat[2*x+1][2*y+2]==' ' && !st[x][y+1]){
			minn[x][y+1]=min(minn[x][y]+1,minn[x][y+1]);
			que[len][0]=x;
			que[len++][1]=y+1;
			st[x][y+1]=1;
		}
		head++;
	}
}

int main(){
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	fin>>w>>h;
	char tmp;
	for(int i=0;i<2*h+1;i++){
		for(int j=0;j<2*w+1;j++){
			do{
				tmp=fin.get();
			}while(tmp!=' ' && tmp!='+' && tmp!='-' && tmp!='|');
			mat[i][j]=tmp;
		}
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			minn[i][j]=40000;
	head=len=maxx=0;
	for(int i=0;i<h && maxx<2;i++){
		if(mat[2*i+1][0]==' '){
			x[maxx]=i;
			y[maxx++]=0;
		}
		if(mat[2*i+1][2*w]==' '){
			x[maxx]=i;
			y[maxx++]=w-1;
		}
	}
	for(int i=0;i<w && maxx<2;i++){
		if(mat[0][2*i+1]==' '){
			x[maxx]=0;
			y[maxx++]=i;
		}
		if(mat[2*h][2*i+1]==' '){
			x[maxx]=h-1;
			y[maxx++]=i;
		}
	}

	que[len][0]=x[0];
	que[len++][1]=y[0];
	st[x[0]][y[0]]=1;
	minn[x[0]][y[0]]=1;

	bfs();
	for(int i=0;i<h;i++)
		memset(st[i],0,sizeof(st[i]));
	head=len=0;
	que[len][0]=x[1];
	que[len++][1]=y[1];
	st[x[1]][y[1]]=1;
	minn[x[1]][y[1]]=1;
	bfs();
	maxx=0;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(minn[i][j]>maxx)
				maxx=minn[i][j];
	fout<<maxx<<endl;

	return 0;
}





