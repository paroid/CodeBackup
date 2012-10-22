/*
ID:chenke61
PROG:milk
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <fstream>
using namespace std;

struct far{
	int price,total;
};

far p[5001];

int cmp(const void *a,const void *b){
	return (*(far *)a).price-(*(far *)b).price;
}

int main(){
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	/*ifstream fin("in");
	ofstream fout("out");*/

	int n,m,cost=0;
	fin>>n>>m;
	for(int i=0;i<m;i++)
		fin>>p[i].price>>p[i].total;
	qsort(p,m,sizeof(far),cmp);
	
	for(int i=0;n>0;i++){
		if(p[i].total<n){		
			cost+=p[i].price*p[i].total;
			n-=p[i].total;
		}
		else{
			cost+=p[i].price*n;
			break;
		}
	}
	fout<<cost<<endl;

	return 0;
}

