/*
ID:chenke61
PROG:ariprog
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

int set[32000];
bool st[125006];

void init(int m){
	int k=0;
	memset(st,0,sizeof(st));
	for(int i=0;i<=m;i++)
		for(int j=i;j<=m;j++){
			st[i*i+j*j]=1;
			k++;
		}
	for(int i=0,s=0;i<k;){
		while(!st[s]) s++;
		set[i++]=s;
		s++;
	}
}

int main(){
	ifstream fin("ariprog.in");
	  ofstream fout("ariprog.out");
	/*ifstream fin("in");
	ofstream fout("out");*/

	int n,m,a;
	fin>>n>>m;
	init(m);

	bool no=true;
	for(int b=1;b<=2*m*m;b++){
		for(int i=0;;i++){
			a=set[i];
			if(a+(n-1)*b>2*m*m)
				break;
			bool ok=true;
			for(int p=1;p<n;p++)
				if(!st[a+b*p]){
					ok=false;
					break;
				}
			if(ok){
				no=false;
				fout<<a<<" "<<b<<endl;
			}
		}
	}
	if(no)
		fout<<"NONE"<<endl;
	

	return 0;
}



