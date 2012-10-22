/*
ID:chenke61
PROG:pprime
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


int main(){
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	srand(time(0));
	int ans[1000],a,b,n=0;

	fin>>a>>b;
	for(int d1=0;d1<=9;d1++)
		for(int d2=0;d2<=9;d2++)
			for(int d3=0;d3<=9;d3++)
				for(int d4=0;d4<=9;d4++){
					int res=d1*10000001+d2*1000010+d3*100100+d4*11000;
					if(!d1){
						res/=10;
						if(!d2){
							res/=10;
							if(!d3)		
								res/=10;
						}
					}
					if(a<=res && res<=b && miller_rabbin(res))
						ans[n++]=res;
					res=d1*1000001+d2*100010+d3*10100+d4*1000;
					if(!d1){
						res/=10;
						if(!d2){
							res/=10;
							if(!d3)		
								res/=10;
						}
					}
					if(a<=res && res<=b && miller_rabbin(res))
						ans[n++]=res;
				}

	sort(ans,ans+n);
	for(int i=0;i<n;i++)
		fout<<ans[i]<<endl;

	return 0;
}



