/*
ID:chenke61
PROG:concom
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

int con[102][102],que[10200][2],n,maxx,len;
bool st[102][102];


int main(){
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	int i,j;
	for(int k=0;k<n;k++){
		fin>>i>>j;
		maxx=max(maxx,max(i,j));
		fin>>con[i][j];
		if(con[i][j]>50){
			st[i][j]=1;
			que[len][0]=i;
			que[len++][1]=j;
		}
	}
	int head=0;
	while(head<len){
		int a=que[head][0],b=que[head][1];
		for(int i=1;i<=maxx;i++){
			con[a][i]+=con[b][i];
			if(a!=i && !st[a][i] && con[a][i]>50){
				st[a][i]=1;
				que[len][0]=a;
				que[len][1]=i;
				len++;
			}
		}
		head++;
	}
	for(int i=1;i<=maxx;i++)
		for(int j=1;j<=maxx;j++)
			if(st[i][j] && i!=j)
				fout<<i<<" "<<j<<endl;

	return 0;
}






