#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

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
	srand(time(0));
	long long n;

	/*for(int i=0;i<20;i++)
		cout<<random(50)<<endl;*/

	//while(scanf("%lld",&n)==1)
	for(long long i=999999999;;i++)
	  if(miller_rabbin(i)){
		  cout<<i<<endl;
          break;
      }


	return 0;
}


