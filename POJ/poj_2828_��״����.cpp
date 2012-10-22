#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define MAXN 200002


int ans[MAXN],pos[MAXN],val[MAXN],c[MAXN],n;

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

    while(scanf("%d\n",&n)!=EOF){
        for(int i=1;i<=n;i++)
            modify(i,1);
        for(int i=1;i<=n;i++)
            scanf("%d %d\n",&pos[i],&val[i]);
        for(int i=n;i>0;i--){
            /*for(int j=1;j<=n;j++)
              cout<<getsum(j)<<" ";*/
            int s=binary_search(pos[i]+1);
            //cout<<"   ->"<<s<<endl;
            ans[s]=val[i];
            modify(s,-1);
        }
        for(int i=1;i<=n;i++){
            printf("%d",ans[i]);
            if(i==n)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}

