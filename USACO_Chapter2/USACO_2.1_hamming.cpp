/*
ID:chenke61
PROG:hamming
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

char di[257][257];
int n,b,d,ans[64];

int diff(int a,int b){
	int c=a^b,res=0;
	while(c){
		res++;
		c&=(c-1);
	}
	return res;
}

void init(int b){
	b=1<<b;
	for(int i=0;i<b;i++)
		for(int j=0;j<i;j++)
			di[i][j]=di[j][i]=diff(i,j);			
}

bool check(int cur,int pre){
	for(int i=0;i<pre;i++)
		if(di[ans[i]][cur]<d)
			return false;
	return true;
}
bool dfs(int cur){
	if(cur==n)
		return true;
	for(int i=cur?ans[cur-1]+1:0;;i++){
		if(!check(i,cur))
			continue;
		ans[cur]=i;
		if(dfs(cur+1))
			return true;
	}
	return false;
}

int main(){
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n>>b>>d;
	init(b);
	dfs(0);
	for(int i=0;i<n;i++){
		if(i%10)	fout<<" ";
		fout<<ans[i];
		if(i%10==9)
			fout<<endl;
	}
	if(n%10)
		fout<<endl;
	return 0;
}



