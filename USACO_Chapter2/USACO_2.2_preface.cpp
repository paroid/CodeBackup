/*
ID:chenke61
PROG:preface
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

char s[]={'I','V','X','L','C','D','M'};
int num[9],n,cnt[10][3]={
	1,0,0,
	2,0,0,
	3,0,0,
	1,1,0,
	0,1,0,
	1,1,0,
	2,1,0,
	3,1,0,
	1,0,1,
	14,5,1
};

int exp(int n){
	int res=1;
	while(n--) res*=10;
	return res;
}

void solve(int n,int bit=0){
	int pre=n/exp(bit+1);
	for(int i=0;i<3;i++)
		num[i+bit*2]+=exp(bit)*pre*cnt[9][i];
	int cur=(n%exp(bit+1))/exp(bit);
	for(int i=0;i<cur-1;i++)
		for(int j=0;j<3;j++)
			num[j+bit*2]+=exp(bit)*cnt[i][j];
	int rem=n%exp(bit)+1;
	for(int i=0;i<3;i++)
		num[i+bit*2]+=rem*cnt[cur-1][i];
	if(n/exp(bit+1))
		solve(n,bit+1);
}

int main(){
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	solve(n,0);
	for(int i=0;i<7;i++)
		if(num[i]){
			fout<<s[i]<<" "<<num[i]<<endl;
		}



	return 0;
}





