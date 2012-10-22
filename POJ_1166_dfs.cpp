#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int c[9],mini=32,ans[28],mov[28]={0},use[9];
int r[9][9]={
	3,3,0,3,3,0,0,0,0,
	3,3,3,0,0,0,0,0,0,
	0,3,3,0,3,3,0,0,0,
	3,0,0,3,0,0,3,0,0,
	0,3,0,3,3,3,0,3,0,
	0,0,3,0,0,3,0,0,3,
	0,0,0,3,3,0,3,3,0,
	0,0,0,0,0,0,3,3,3,
	0,0,0,0,3,3,0,3,3
};

bool check(){
	for(int i=0;i<9;i++)
		if(c[i])
			return false;
	return true;
}

void turn(int p){
	for(int i=0;i<9;i++)
		c[i]=(c[i]+r[p][i])%12;
}

void dfs(int cur){
	if(cur>=mini)
		return;
	if(check()){
		mini=cur;
		for(int i=0;i<cur;i++)
			ans[i]=mov[i]+1;
		return;
	}
	for(int i=cur?mov[cur-1]:0;i<9;i++){
		if(use[i]>2)
			continue;
		turn(i);
		use[i]++;
		mov[cur]=i;
		dfs(cur+1);
		for(int j=0;j<3;j++)	turn(i);
		use[i]--;
	}
}


int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

	for(int i=0;i<9;i++){
		cin>>c[i];
        c[i]=!c[i]?12:c[i]*3;
    }
	memset(use,0,sizeof(use));
	dfs(0);

	for(int i=0;i<mini;i++){
		if(i) cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

	return 0;
}





