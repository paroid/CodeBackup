/*
ID:chenke61
PROG:dualpal
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
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	/*ifstream fin("in");
	ofstream fout("out");*/
	
	char sq[40];
	int s,n,cnt,b;
	fin>>n>>s;
	for(int i=s+1;n;i++){
		cnt=0;
		for(int b=2;b<=10;b++){
			con(i,b,sq);
			if(pal(sq))
				cnt++;
			if(cnt==2){
				fout<<i<<endl;
				n--;
				break;
			}
		}
	}

	return 0;
}

