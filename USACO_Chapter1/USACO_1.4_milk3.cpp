/*
ID:chenke61
PROG:milk3
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

bool st[21][21],ans[21];
int a,b,c;

void dfs(int x,int y,int z){
	if(st[x][y])
		return;
	st[x][y]=1;
	if(!x) ans[z]=1;
	if(x>0 && y<b) dfs(max(0,x-b+y),min(b,y+x),z);
	if(x>0 && z<c) dfs(max(0,x-c+z),y,min(c,z+x));
	if(y>0 && x<a) dfs(min(a,x+y),max(0,y-a+x),z);
	if(y>0 && z<c) dfs(x,max(0,y-c+z),min(c,y+z));
	if(z>0 && x<a) dfs(min(a,x+z),y,max(0,z-a+x));
	if(z>0 && y<b) dfs(x,min(b,y+z),max(0,z-b+y));
}

int main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>a>>b>>c;
	dfs(0,0,c);
	bool first=true;
	for(int i=0;i<=c;i++)
		if(ans[i]){
			if(first){
				first=false;
				fout<<i;
			}
			else
				fout<<" "<<i;
		}
	fout<<endl;

	return 0;
}



