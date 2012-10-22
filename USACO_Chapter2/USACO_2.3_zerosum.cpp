/*
ID:chenke61
PROG:zerosum
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


int n;
char ans[20],cal[20];

void dfs(int cur,ofstream &fout){
	if(cur==n-1){
		int len=n*2-1;
		ans[len]='\0';
		strcpy(cal,ans);
		for(int i=0;i<len;i++){
			if(cal[i]>='0' && cal[i]<='9')
				cal[i]-='0';
			else if(cal[i]==' '){
				cal[i-1]=cal[i-1]*10+cal[i+1]-'0';
				cal[i+1]='0';
				cal[i]='+';
			}
		}
		int res=cal[0];
		for(int i=0;i<n-1;i++)
			res=(cal[2*i+1]=='+'?res+cal[2*i+2]:res-cal[2*i+2]);
		if(!res)
			fout<<ans<<endl;
		return;
	}
	if(!cur || ans[2*cur-1]!=' '){
		ans[2*cur+1]=' ';
		dfs(cur+1,fout);
	}
	ans[2*cur+1]='+';
	dfs(cur+1,fout);
	ans[2*cur+1]='-';
	dfs(cur+1,fout);
}


int main(){
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	for(int i=1;i<=n;i++)
		ans[2*i-2]=i+'0';

	dfs(0,fout);

	return 0;
}






