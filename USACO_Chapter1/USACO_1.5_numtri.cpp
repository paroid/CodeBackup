/*
ID:chenke61
PROG:numtri
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

int d[1000][1000];

int main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	/*ifstream fin("in");
	ofstream fout("out");*/

	int n;
	fin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			fin>>d[i][j];

	for(int i=n-2;i>=0;i--)
		for(int j=0;j<=i;j++)
			d[i][j]+=max(d[i+1][j],d[i+1][j+1]);
		
	fout<<d[0][0]<<endl;

	return 0;
}



