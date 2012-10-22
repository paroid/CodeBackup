#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define MAXN 8008


int ans[MAXN],pre[MAXN],c[MAXN],n;

int lowbit(int p){
    return p&(p^(p-1));
}

void modify(int p,int delta){
    while(p<=n){
        c[p]+=delta;
        p+=lowbit(p);
    }
}

int getsum(int p){
    int res=0;
    while(p){
        res+=c[p];
        p-=lowbit(p);
    }
    return res;
}

int binary_search(int e){
    int a=1,b=n,mid,sum;
    while(a<=b){
        mid=(a+b)/2;
        sum=getsum(mid);
        if(sum==e)
            break;
        else if(sum>e)
            b=mid-1;
        else
            a=mid+1;
    }
    while(getsum(mid-1)==e)
        mid--;
    return mid;
}


int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
        modify(i,1);
    for(int i=2;i<=n;i++)
        scanf("%d\n",&pre[i]);
    for(int i=n;i>0;i--){
        /*for(int j=1;j<=n;j++)
            cout<<getsum(j)<<" ";*/
        int s=binary_search(pre[i]+1);
        //cout<<"   ->"<<s<<endl;
        ans[i]=s;
        modify(s,-1);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);

    return 0;
}

