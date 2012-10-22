/*
ID:chenke61
PROG:namenum
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

int len(long long n,bool &f){
	int res=0;
	while(n){
		res++;
		if(n%10<2){
			f=false;
			return 0;
		}
		n/=10;
	}
	return res;
}

long long con(char *w,int l){
	long long d=0;
	for(int i=0;i<l;i++){
		if(w[i]<'Q')
			d=d*10+(w[i]-'A')/3+2;
		else
			d=d*10+(w[i]-'A'-1)/3+2;
	}
	return d;
}
/*
int po(int n){
	int res=1;
	while(n--) res*=10;
	return res;
}*/

int main(){
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	/*ifstream fin("in");
	ofstream fout("out");*/
	ifstream dict("dict.txt");

	long long n;
	bool f=true,none=true;
	char w[20];
	fin>>n;
	int l=len(n,f);
	if(!f){
		fout<<"NONE"<<endl;
		return 0;
	}
	f=true;
	while(dict>>w){
		f=true;
		int ll=strlen(w);
		long long ww=con(w,ll);
		//fout<<ww<<endl;
		/*if(!strcmp(w,"KRISTOPHER"))
			fout<<ww<<endl;*/
		if(ll != l){
			/*if(ll>l && ww/po(ll-l)>n)
				break;
			if(ll<l && ww>n/po(ll-l))
				break;*/
			continue;
		}
		if(ww==n){
			none=false;
			fout<<w<<endl;
		}
	}
	if(none)
		fout<<"NONE"<<endl;

	return 0;
}

