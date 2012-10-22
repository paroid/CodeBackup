/*
ID:chenke61
PROG:beads
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
char la[360];
int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n,cnt,max=0,mid;
	fin>>n>>la;
	cnt=0;
	for(int i=0;i<n;i++){
		char p=la[i];
		cnt=1;
		int j=(i+1)%n;
		while((la[j]==p||la[j]=='w'||p=='w')&& cnt<n){
			if(p=='w')
				p=la[j];
			cnt++;
			j=(j+1)%n;
		}
		p=la[(n+i-1)%n];
		j=(n+i-1)%n;
		while((la[j]==p||la[j]=='w'||p=='w')&& cnt<n){
			if(p=='w')
				p=la[j];
			cnt++;
			j=(j-1+n)%n;
		}
		if(cnt==n){
			max=n;
			break;
		}
		if(cnt>max)
			max=cnt;
	}
	fout<<max<<endl;
	return 0;
}

