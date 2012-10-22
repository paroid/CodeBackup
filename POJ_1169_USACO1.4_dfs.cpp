#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <math.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

void swap(int &a,int &b){
    if(&a == &b)	return;
    a^=b^=a^=b;		
    return;
}

int a[4],b[4],st[4],pos[4],mini=0xffffff,ans[1000];

void update(int x,int y){
    if(x*y < mini){
        mini=x*y;
        memset(ans,0,sizeof(ans));
    }
    if(x*y == mini){
        ans[x]=1;
        ans[y]=1;
    }
    return;
}

void pack(int a1,int a2,int b1,int b2,int c1,int c2,int d1,int d2){
    int x,y;
    x=a1+b1+c1+d1;
    y=max(max(a2,b2),max(c2,d2));
    update(x,y);

    x=max(a1,b1+c1+d1);
    y=a2+max(max(b2,c2),d2);
    update(x,y);

    x=max(a1,b1+c1)+d1;
    y=max(max(b2,c2)+a2,d2);
    update(x,y);

    x=a1+b1+max(c1,d1);
    y=max(max(c2+d2,b2),a2);
    update(x,y);

    x=max(max(a1+b1,c1+d1),a1+d1);
    y=max(max(a2+c2,b2+d2),b2+c2);
    update(x,y);
    return;
}

void trans(int n){
    if(4 == n){
        pack(a[pos[0]],b[pos[0]],a[pos[1]],b[pos[1]],a[pos[2]],b[pos[2]],a[pos[3]],b[pos[3]]);		
    }
    else{
        for(int i=0;i<4;i++){
            if(!st[i]){
                st[i]=1;
                pos[n]=i;
                trans(n+1);
                st[i]=0;
            }
        }
    }
}

void rot(int d){
    if(4 == d){
        memset(st,0,sizeof(st));
        trans(0);
    }
    else{
        rot(d+1);
        swap(a[d],b[d]);
        rot(d+1);
        swap(a[d],b[d]);
    }
}


int main(){
    ifstream cin("in");
    ofstream cout("out");

    memset(ans,0,sizeof(ans));
    for(int i=0;i<4;i++)
        cin>>a[i]>>b[i];

    rot(0);

    int up=sqrt(double(mini));
    cout<<mini<<endl;
    for(int i=1;i<=up;i++)
        if(ans[i]){
            cout<<i<<" "<<mini/i<<endl;
        }


    return 0;
}



