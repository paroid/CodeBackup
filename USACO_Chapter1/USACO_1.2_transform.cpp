/*
ID:chenke61
PROG:transform
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

void swap(char &a,char &b){
	if(&a==&b)	return;
	a^=b^=a^=b;
}
bool equal(char a[10][10],char b[10][10],int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=b[i][j])	return false;
	return true;
}

void copy(char s[10][10],char d[10][10],int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=s[i][j];
	return;
}

void ref(char s[10][10],int n){
	for(int j=0;j<n/2;j++)
		for(int i=0;i<n;i++)
			swap(s[i][j],s[i][n-j-1]);
}

void rot(char s[10][10],int n){
	char t[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			t[j][n-1-i]=s[i][j];
	copy(t,s,n);
	return;
}

int main(){
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	int n;
	char s[10][10],d[10][10],t[10][10];
	fin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>s[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>d[i][j];	
	copy(s,t,n);
	rot(t,n);
	if(equal(t,d,n)){
		fout<<1<<endl;
		return 0;
	}
	rot(t,n);
	if(equal(t,d,n)){
		fout<<2<<endl;
		return 0;
	}
	rot(t,n);
	if(equal(t,d,n)){
		fout<<3<<endl;
		return 0;
	}
	copy(s,t,n);
	ref(t,n);
	if(equal(t,d,n)){
		fout<<4<<endl;
		return 0;
	}
	int time=3;
	while(time--){
		rot(t,n);
		if(equal(t,d,n)){
			fout<<5<<endl;
			return 0;
		}
	}
	if(equal(s,d,n)){
		fout<<6<<endl;
		return 0;
	}
	fout<<7<<endl;
	return 0;
}

