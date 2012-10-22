/*
ID:chenke61
PROG:nocows
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

int f[205][102],n,k;
const int mod=9901;
int dp(int i,int j){
	if(f[i][j]!=-1)
		return f[i][j];
	int res=0;
	for(int k=1;k<=i-2;k++)
		res=(res+dp(k,j-1)*dp(i-1-k,j-1))%mod;
	return f[i][j]=res;
}

int main(){
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n>>k;
	memset(f,-1,sizeof(f));

	for(int i=1;i<=k;i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
		f[i][1]=0;

	fout<<(dp(n,k)-dp(n,k-1)+mod)%mod<<endl;

	return 0;
}






