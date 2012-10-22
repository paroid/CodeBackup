#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define MAXN 400002

int tree[MAXN];
int n,t,o;
bool flag[32];

void swap(int &a,int &b){
    if(&a==&b)  return;
    a^=b^=a^=b;
}

void paint(int p,int l,int r,int a,int b,int c){
    //cout<<"paint "<<l<<" "<<r<<" "<<a<<"-"<<b<<" -> "<<c<<endl;
    if(tree[p]==c)
        return;
    if(l==a && r==b)
        tree[p]=c;
    else{
        int m=(l+r)/2;
        if(tree[p]>0){
            tree[2*p]=tree[p];
            tree[2*p+1]=tree[p];
            tree[p]=-1;
        }
        if(b<=m)
            paint(2*p,l,m,a,b,c);
        else if(a>=m+1)
            paint(2*p+1,m+1,r,a,b,c);
        else{
            paint(2*p,l,m,a,m,c);
            paint(2*p+1,m+1,r,m+1,b,c);
        }
    }
}

void count(int p,int l,int r,int a,int b){
    //cout<<"count: "<<p<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    if(l<=a && r>=b && tree[p]>0)
        flag[tree[p]]=1;
    else{
        int m=(l+r)/2;
        if(b<=m)
            count(2*p,l,m,a,b);
        else if(a>=m+1)
            count(2*p+1,m+1,r,a,b);
        else{
            count(2*p,l,m,a,m);
            count(2*p+1,m+1,r,m+1,b);
        }
    }
}

int upperBound(int p){
    int tt=1;
    while(p>tt)
        tt<<=1;
    return tt;
}

int total(){
    int res=0;
    for(int i=1;i<=t;i++)
        if(flag[i])
            res++;
    return res;
}

/*void show(int u){
  for(int i=1;i<=u;i++)
  cout<<tree[i]<<" ";
  cout<<endl;
  }
*/
int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    //cin cout will TLE
    //cin>>n>>t>>o;
    scanf("%d %d %d\n",&n,&t,&o);
    int up=upperBound(n);
    paint(1,1,up,1,n,1);
    while(o--){
        char cmd;
        int i,j,k;
        //cin>>c;
        scanf("%c",&cmd);
        if(cmd=='C'){
            //cin>>i>>j>>k;
            scanf(" %d %d %d\n",&i,&j,&k);
            if(i>j)
                swap(i,j);
            paint(1,1,up,i,j,k);
        }
        else{
            memset(flag,0,sizeof(flag));
            //cin>>i>>j;
            scanf(" %d %d\n",&i,&j);
            if(i>j)
                swap(i,j);
            count(1,1,up,i,j);
            //cout<<total()<<endl;
            printf("%d\n",total());
        }
    }


    return 0;
}





