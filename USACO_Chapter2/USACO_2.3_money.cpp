/*
ID:chenke61
PROG:money
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

long long f[10008],mo;
int co[26],n;


int main(){
	ifstream fin("money.in");
	ofstream fout("money.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n>>mo;
	for(int i=1;i<=n;i++)
		fin>>co[i];
	memset(f,0,sizeof(f));
	for(int i=0;i<=mo;i+=co[1])
		f[i]=1;
	for(int i=2;i<=n;i++){
		for(int j=co[i];j<=mo;j++)
			f[j]=f[j]+f[j-co[i]];		
	}
	fout<<f[mo]<<endl;

	return 0;
}






