#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;

int mat[51][51],cnt=0,s[2508],wall[51][51],m,n,maxx=0,x,y;
char dir;
void dfs(int i,int j,int mark){
	mat[i][j]=mark;
	s[mark]++;
	if(s[mark]>maxx)
		maxx=s[mark];
	if(i>1 && !mat[i-1][j] && !(wall[i][j]&2))	dfs(i-1,j,mark);
	if(j>1 && !mat[i][j-1] && !(wall[i][j]&1))	dfs(i,j-1,mark);
	if(i<n && !mat[i+1][j] && !(wall[i][j]&8))	dfs(i+1,j,mark);
	if(j<m && !mat[i][j+1] && !(wall[i][j]&4))	dfs(i,j+1,mark);
}


int main(){
	freopen("in","r",stdin);
    freopen("out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>wall[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(!mat[i][j])
				dfs(i,j,++cnt);
	}		

	cout<<cnt<<endl;
	cout<<maxx<<endl;

	return 0;
}



    

