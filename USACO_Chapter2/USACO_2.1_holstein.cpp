/*
ID:chenke61
PROG:holstein
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

int o[25],d[15][25],sum[25],ans[15],sol[15],ml=26,m,n;


bool check(){
	for(int i=0;i<m;i++)
		if(sum[i]<o[i])
			return false;
	return true;
}

void dfs(int cur){
	if(cur>=ml)
		return;
	if(check()){
		for(int i=0;i<cur;i++)
			ans[i]=sol[i]+1;
		ml=cur;
		return;
	}
	for(int i=cur?sol[cur-1]+1:0;i<n;i++){
		sol[cur]=i;
		for(int j=0;j<m;j++)
			sum[j]+=d[i][j];
		dfs(cur+1);
		for(int j=0;j<m;j++)
			sum[j]-=d[i][j];
	}
}



int main(){
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>m;
	for(int i=0;i<m;i++)
		fin>>o[i];

	fin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			fin>>d[i][j];

	dfs(0);
	fout<<ml;
	for(int i=0;i<ml;i++)
		fout<<" "<<ans[i];
	fout<<endl;

	return 0;
}



