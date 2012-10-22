/*
ID:chenke61
PROG:frac1
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

int n;
void amz(int x1,int y1,int x2,int y2,ofstream &fout){
	if(y1+y2>n)		return;
	amz(x1,y1,x1+x2,y1+y2,fout);
	fout<<x1+x2<<"/"<<y1+y2<<endl;
	amz(x1+x2,y1+y2,x2,y2,fout);
}

int main(){
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	/*ifstream fin("in");
	  ofstream fout("out");*/

	fin>>n;
	fout<<"0/1"<<endl;
	amz(0,1,1,1,fout);
	fout<<"1/1"<<endl;

	return 0;
}



