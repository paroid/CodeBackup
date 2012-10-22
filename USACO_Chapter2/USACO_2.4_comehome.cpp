/*
ID:chenke61
PROG:comehome
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
#define MAXN 52
const long long inf=1000000;

long long mat[MAXN][MAXN],minn[26],p,dist;
char a,b;
bool st[26];

void dijkstra(int s=25,int n=52){
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		minn[i]=inf,v[i]=0;
	for (minn[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||minn[i]<minn[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&minn[k]+mat[k][i]<minn[i])
				minn[i]=minn[k]+mat[k][i];
	}
}

char con(char c){
	if(c>'Z')
		return c-'a'+26;
	return c-'A';
}

int main(){
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	fin>>p;
	for(int i=0;i<52;i++)
		memset(mat[i],inf,sizeof(mat[i]));

	while(p--){
		fin>>a>>b>>dist;
		int aa=con(a),bb=con(b);
		mat[aa][bb]=mat[bb][aa]=min(dist,mat[aa][bb]);
	}
	
	dijkstra();
	int name=32,ans=inf;
	for(int i=0;i<25;i++)
		if(minn[i]<ans){
			ans=minn[i];
			name=i;
		}
	fout<<char(name+'A')<<" "<<ans<<endl;

	return 0;
}





