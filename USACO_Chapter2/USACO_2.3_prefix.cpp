/*
ID:chenke61
PROG:prefix
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

const int prime=10000019;
bool hash[10000019];
char tmp[12],s[200005],ch;
int f[200005],n;

int main(){
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	while(fin>>tmp){
		if(!strcmp(tmp,"."))
			break;
		int len=strlen(tmp);
		long long res=0,p=1;
		for(int i=0;i<len;i++){
			res=(res+(tmp[i]-'A'+1)*p)%prime;
			p*=27;
		}
		//hash error check  
		//原数据会发生error
		/*if(hash[res])
		  fout<<"error"<<endl;*/
		hash[res]=1;
	}
	n=0;
	while(!fin.eof()){
		ch=fin.get();
		if(ch>='A' && ch<='Z')
			s[n++]=ch;
	}
	for(int i=n-1;i>=0;i--){
		int	max=0;
		long long res=0,p=1,tm;
		for(int j=i;j<i+10 && j<n;j++){
			res=(res+(s[j]-'A'+1)*p)%prime;
			p*=27;
			/*fout<<i<<"--"<<endl;
			  fout<<res<<endl;*/
			if(res>=0 && hash[res] && (tm=f[j+1]+j-i+1)>max){
				max=tm;
			}
		}
		f[i]=max;
	}
	/*for(int i=0;i<n;i++)
	  fout<<f[i]<<" ";
	  fout<<endl;*/
	fout<<f[0]<<endl;

	return 0;
}






