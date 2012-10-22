/*
ID:chenke61
PROG:fact4
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

/*ifstream fin("in");
  ofstream fout("out");*/

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define MAXN 10000
int lastdigit(char* buf){
	const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
	int len=strlen(buf),a[MAXN],i,c,ret=1;
	if (len==1)
		return mod[buf[0]-'0'];
	for (i=0;i<len;i++)
		a[i]=buf[len-1-i]-'0';
	for (;len;len-=!a[len-1]){
		ret=ret*mod[a[1]%2*10+a[0]]%5;
		for (c=0,i=len-1;i>=0;i--)
			c=c*10+a[i],a[i]=c/5,c%=5;
	}
	return ret+ret%2*5;
}


int main(){
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");

	char n[12];
	fin>>n;
	fout<<lastdigit(n)<<endl;

	return 0;
}






