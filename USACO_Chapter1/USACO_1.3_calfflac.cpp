/*
ID:chenke61
PROG:calfflac
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

char o[20005],p[20005];
short pos[20005],s,e,mmax=0;

void pal(int l,int r,int n){
	while(l>=0 && r<n && p[l]==p[r]){
		l--;
		r++;
	}
	if(r-l-1>mmax){
		s=pos[l+1];
		e=pos[r-1];
		mmax=r-l-1;
	}
	return;
}

int main(){
	ifstream fin("calfflac.in");
	  ofstream fout("calfflac.out");
	/*ifstream fin("in");
	ofstream fout("out");*/
	int lt=0,l=0;
	while(!fin.eof()){
		o[lt++]=fin.get();
		if(o[lt-1]>='A' && o[lt-1]<='Z'){
			p[l++]=o[lt-1]+'b'-'B';
			pos[l-1]=lt-1;
		}
		else if(o[lt-1]>='a' && o[lt-1]<='z'){
			p[l++]=o[lt-1];
			pos[l-1]=lt-1;
		}

	}
	for(int i=0;i<l;i++){
		pal(i,i+1,l);
		pal(i-1,i+1,l);
	}
/*
	for(int i=0;i<lt;fout<<o[i++]);
	fout<<endl;
	for(int i=0;i<l;fout<<p[i++]);
	fout<<endl;*/
	fout<<mmax<<endl;
	for(int i=s;i<=e;fout<<o[i++]);
	fout<<endl;
	return 0;
}

