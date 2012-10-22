/*
ID:chenke61
PROG:sprime
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

const int maxTest=240;

long long random(long long n){
	return (long long)((double)rand()/RAND_MAX*n+0.5);
}

long long mod_exp(long long a,long long b,long long n){
	long long ans;
	if(b==1) 
		return a%n;
	ans=mod_exp(a,b/2,n);
	if(b%2==0) return ans*ans%n;
	else return ans*ans%n*a%n;
}

bool miller_rabbin(long long n){
	if(n==1 || (n!=2&&!(n%2)) || (n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return false;
	for(long i=1;i<=maxTest;i++){
		long long a=random(n-2)+1;
		if(mod_exp(a,n-1,n)!=1)
			return false;
	}
	return true;
}

void sprime(int pre,int d,ofstream &fout){
	for(int i=1;i<=9;i++){
		int res=pre*10+i;
		if(miller_rabbin(res))
			if(d==1)
				fout<<res<<endl;
			else
				sprime(res,d-1,fout);
	}
}

int main(){
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	int n;
	fin>>n;
	sprime(0,n,fout);

	return 0;
}



