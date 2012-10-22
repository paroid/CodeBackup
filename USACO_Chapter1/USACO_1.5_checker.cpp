/*
ID:chenke61
PROG:checker
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

int cnt=0,cd=0,n,ans[14];
bool st[14];

void check(int cur,ofstream &fout){
	for(int i=1;i<=n;i++){
		if(cur==1 && i>(n+1)/2 && n!=6)  //cut 
			break;
		if(!st[i]){
			st[i]=1;
			bool ok=true;
			for(int j=1;j<cur;j++)
				if(abs(ans[j]-i)==abs(j-cur)){
					ok=false;
					break;
				}
			if(ok){
				if(cur==n){
					cnt++;
					if(ans[1]<=n/2) //note half
						cd++;
					if(cnt<=3){
						for(int j=1;j<n;j++)
							fout<<ans[j]<<" ";
						fout<<i<<endl;
					}
					st[i]=0;
					return;
				}
				else{
					ans[cur]=i;
					check(cur+1,fout);
				}
			}
			st[i]=0;
		}
	}
}


int main(){
	ifstream fin("checker.in");
	ofstream fout("checker.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	memset(st,0,sizeof(st));
	fin>>n;
	check(1,fout);
	if(n!=6)
		cnt+=cd;
	fout<<cnt<<endl;

	return 0;
}



