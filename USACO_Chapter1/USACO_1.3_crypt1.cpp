/*
ID:chenke61
PROG:crypt1
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;

bool test(int n,bool *st){
	if(!n) return false;
	while(n){
		if(!st[n%10])	return  false;
		n/=10;
	}
	return true;
}

int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	bool st[10];
	int n,d[10],a,b,cnt=0;
	memset(st,0,sizeof(st));
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>d[i];
		st[d[i]]=1;
	}
	for(int a1=0;a1<n;a1++)
		for(int a2=0;a2<n;a2++)
			for(int a3=0;a3<n;a3++)
				for(int b1=0;b1<n;b1++)
					for(int b2=0;b2<n;b2++){
						int mul=(d[a1]*100+d[a2]*10+d[a3])*(d[b1]*10+d[b2]);
						if(mul<1000 || mul>9999) continue;
						if(!test(mul,st))	continue;
						mul=(d[a1]*100+d[a2]*10+d[a3])*d[b1];
						if(mul<100 || mul>999) continue;
						if(!test(mul,st))	continue;
						mul=(d[a1]*100+d[a2]*10+d[a3])*d[b2];
						if(mul<100 || mul>999)	continue;
						if(!test(mul,st))	continue;
						cnt++;
						//fout<<(d[a1]*100+d[a2]*10+d[a3])<<" x "<<(d[b1]*10+d[b2])<<" = "<<(d[a1]*100+d[a2]*10+d[a3])*(d[b1]*10+d[b2])<<endl;
					}

	fout<<cnt<<endl;

	return 0;
}

