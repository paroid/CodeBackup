/*
ID:chenke61
PROG:palsquare
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

char digit(int n){
	if(n<10)	return '0'+n;
	return 'A'+n-10;
}

void con(int n,int b,char *d){
	int i=0;
	while(n){
		d[i++]=digit(n%b);
		n/=b;
	}
	d[i]='\0';
	return;
}

bool pal(char *d){
	int l=strlen(d);
	for(int i=0;i<l/2;i++)
		if(d[i] != d[l-1-i])
			return false;
	return true;
}


int main(){
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	/*ifstream fin("in");
	ofstream fout("out");*/
	
	char n[40],sq[40];
	int b;
	fin>>b;
	for(int i=1;i<=300;i++){
		con(i*i,b,sq);
		if(pal(sq)){
			//fout<<i<<"---";
			con(i,b,n);
			int len=strlen(n);
			for(int j=len-1;j>=0;j--)
				fout<<n[j];
			fout<<" ";
			fout<<sq<<endl;
		}
	}

	return 0;
}

