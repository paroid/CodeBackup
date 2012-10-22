#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 58
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct{
    int id,val;
}st;
st stam[100],ans[5],tans[5];
int n,type,cnt,way,req,maxval;
bool tie;

int cmp(const void *a,const void *b){
    return (*(st *)a).val-(*(st *)b).val;
}
int ct(int t){
    int res=1;
    for(int i=1;i<t;i++){
        res++;
        for(int j=0;j<i;j++)
            if(tans[i].id==tans[j].id){
                res--;
                break;
            }
    }
    return res;
}

void dfs(int p,int cur,int sum,int m){
    if(sum==req){
        way++;
        int tt=ct(cur);
        if(tt==type && cur==cnt && maxval==m)
            tie=1;
        if(tt>type || (tt==type && cur<cnt) || (tt==type && cur==cnt && maxval<m)){
            type=tt;
            cnt=cur;
            maxval=m;
            for(int i=0;i<cnt;i++)
                ans[i]=tans[i];
            tie=0;
        }
        return;
    }
    if(cur>3)
        return;
    for(int i=p;i<n;i++){
        if(sum+stam[i].val<=req){
            tans[cur]=stam[i];
            dfs(i,cur+1,sum+stam[i].val,max(stam[i].val,m));
        }
    }
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int tmp;
    while(cin>>tmp){
        n=0;
        stam[n].id=n;
        stam[n++].val=tmp;
        while(cin>>tmp){
            if(!tmp)
                break;
            stam[n].id=n;
            stam[n++].val=tmp;
        }
        qsort(stam,n,sizeof(st),cmp);
        while(cin>>req){
            if(!req)
                break;
            way=tie=type=maxval=0;
            cnt=5;
            dfs(0,0,0,0);
            cout<<req<<" ";
            if(!way)
                cout<<"---- none"<<endl;
            else{
                cout<<"("<<type<<"):";
                if(tie)
                    cout<<" tie";
                else
                    for(int i=0;i<cnt;i++)
                        cout<<" "<<ans[i].val;
                cout<<endl;
            }
        }
    }

    return 0;
}

