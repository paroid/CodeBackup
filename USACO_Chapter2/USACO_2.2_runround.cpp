/*
ID:chenke61
PROG:runround
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

long long n;
bool st[10];
bool check(long long m){
	char d[12];
	sprintf(d,"%lld",m);
	int len=strlen(d);
	memset(st,0,sizeof(st));
	for(int i=0;i<len;i++)
		if(d[i]=='0' || st[d[i]-'0'])
			return false;
		else
			st[d[i]-'0']=1;
	memset(st,0,sizeof(st));
	for(int i=0,j=0;i<len;i++){
		int cur=d[j]-'0';
		j=(j+cur)%len;
		if(st[j])
			return false;
		st[j]=1;
	}
	return true;
}


int main(){
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	while(!check(++n)) ;
	fout<<n<<endl;

	return 0;
}





