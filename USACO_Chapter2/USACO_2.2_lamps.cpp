/*
ID:chenke61
PROG:lamps
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

int on[104],off[104],s[8],ans[8],cnt,c,n;

bool check(){
	for(int i=1;i<=on[0];i++)
		if(!s[(on[i]-1)%6])
			return false;
	for(int i=1;i<=off[0];i++)
		if(s[(off[i]-1)%6])
			return false;
	return true;
}

void change(int tp){
	switch(tp){
		case 1:
			for(int i=0;i<6;i++)
				s[i]=!s[i];
			break;
		case 2:
			for(int i=0;i<6;i+=2)
				s[i]=!s[i];
			break;
		case 3:
			for(int i=1;i<6;i+=2)
				s[i]=!s[i];
			break;
		case 4:
			s[0]=!s[0];
			s[3]=!s[3];
			break;
		case 14:
			change(1);
			change(4);
			break;
		case 24:
			change(2);
			change(4);
			break;
		case 34:
			change(3);
			change(4);
			break;
	}
}

int conv(){
	int p=1,res=0;
	for(int i=5;i>=0;i--){
		res+=s[i]*p;
		p<<=1;
	}
	return res;
}

void solve(int ca){
	switch(ca){
		case 0:
			if(check())
				ans[cnt++]=conv();
			break;
		case 1:
			change(1);
			if(check())
				ans[cnt++]=conv();
			change(1);
			break;
		case 2:
			change(2);
			if(check())
				ans[cnt++]=conv();
			change(2);
			break;
		case 3:
			change(3);
			if(check())
				ans[cnt++]=conv();
			change(3);
			break;
		case 4:
			change(4);
			if(check())
				ans[cnt++]=conv();
			change(4);
			break;
		case 14:
			change(14);
			if(check())
				ans[cnt++]=conv();
			change(14);
			break;
		case 24:
			change(24);
			if(check())
				ans[cnt++]=conv();
			change(24);
			break;
		case 34:
			change(34);
			if(check())
				ans[cnt++]=conv();
			change(34);
			break;
	}
}

void so(int val){
	memset(s,0,sizeof(s));
	int i=5;
	while(val){
		s[i--]=val%2;
		val>>=1;
	}
}

int main(){
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n>>c;
	// I still don't know why the n has been changed during the process
	int nn=n;
	for(int i=1;;i++){
		fin>>on[i];
		if(on[i]==-1)
			break;
		on[0]++;
	}
	for(int i=1;;i++){
		fin>>off[i];
		if(off[i]==-1)
			break;
		off[0]++;
	}
	memset(s,1,sizeof(s));
	switch(c){
		case 0:
			solve(0);
			break;
		case 1:
			for(int i=0;i<=4;i++)
				solve(i);
			break;
		case 2:
			for(int i=0;i<=3;i++){
				solve(i);
				if(i)
					solve(10*i+4);
			}
			break;
		default:
			for(int i=0;i<=4;i++){
				solve(i);
				if(i && i<4)
					solve(10*i+4);
			}
	}
	if(!cnt){
		fout<<"IMPOSSIBLE"<<endl;
		return 0;
	}

	sort(ans,ans+cnt);
	int pre=-1;
	for(int i=0;i<cnt;i++){
		if(ans[i]!=pre){
			so(ans[i]);
			for(int j=0;j<nn;j++){
				fout<<s[j%6];
			}
			fout<<endl;
			pre=ans[i];
		}
	}
	return 0;
}





