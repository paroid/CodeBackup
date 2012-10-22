/*
ID:chenke61
PROG:barn1
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;

int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	int c,s,m,cost=0,d[201],max[50];
	fin>>m>>s>>c;
	for(int i=0;i<c;i++)
		fin>>d[i];
	sort(d,d+c);
	/*for(int i=0;i<c;i++)
	  fout<<d[i]<<" ";
	  fout<<endl;*/
	cost=d[c-1]-d[0]+1;
	for(int i=0;i<c-1;i++)
		d[i]=d[i+1]-d[i]-1;
	sort(d,d+c-1);
	/*for(int i=0;i<c-1;i++)
	  fout<<d[i]<<" ";
	  fout<<endl;*/
	//fout<<cost<<endl;
	for(int i=0;i<m-1 && i<c-1;i++)
		cost-=d[c-2-i];
	fout<<cost<<endl;

	return 0;
}

