/*
ID:chenke61
PROG:sort3
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

int d[1002],n,cnt[3],miss,sw;
bool st[1002];

int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	for(int i=0;i<n;i++){
		fin>>d[i];
		cnt[d[i]-1]++;
	}
	for(int i=0;i<cnt[0]+cnt[1];i++){
		if(i<cnt[0]){
			if(d[i]==1)
				st[i]=1;
			else{
				miss++;
				int up=(d[i]==2?cnt[0]+cnt[1]:n);
				int sr=(d[i]==2?cnt[0]:cnt[0]+cnt[1]);				
				for(int j=sr;j<up;j++)
					if(!st[j] && d[j]==1){
						st[j]=1;
						st[i]=1;
						sw++;
						miss--;
						break;
					}
			}
		}
		else{
			if(d[i]==2)
				st[i]=1;
			else if(d[i]>2){
				for(int j=cnt[1]+cnt[0];j<n;j++)
					if(!st[j] && d[j]==2){
						st[i]=1;
						st[j]=1;
						sw++;
						break;
					}
			}
		}
	}

	/*fout<<cnt[0]<<' '<<cnt[1]<<" "<<cnt[2]<<endl;
	  for(int i=0;i<n;i++)
	  fout<<st[i]<<" ";
	  fout<<endl;
	  fout<<miss<<" "<<sw<<endl;*/
	fout<<(miss*2+sw)<<endl;

	return 0;
}



