/*
ID:chenke61
PROG:subset
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

long long f[40][782],n,sum;


int main(){
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	sum=n*(n+1)/2;
	if(sum&1){
		fout<<0<<endl;
		return 0;
	}
	sum>>=1;
	f[1][0]=1;
	f[1][1]=1;

	for(int i=2;i<=n;i++)
		for(int j=0;j<=sum;j++)
			if(i<=j)
				f[i][j]=f[i-1][j]+f[i-1][j-i];
			else
				f[i][j]=f[i-1][j];

	fout<<f[n][sum]/2<<endl;


	return 0;
}





