/*
ID:chenke61
PROG:contact
LANG:C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;

/*ifstream fin("in");
  ofstream fout("out");*/

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 100002


typedef struct _ans {
    int len,val,freq;
} ans;


bool cmp(const ans &a,const ans &b){
    return a.freq!=b.freq?(a.freq>b.freq):(a.len!=b.len?(a.len<b.len):(a.val<b.val));
}

void conb(int n,int l,char *s){
    int i=l-1;
    s[l]='\0';
    while(n){
        s[i--]=int(n&1)+'0';
        n>>=1;
    }
    while(i>=0)
        s[i--]='0';
}
int ma(int n){
    int res=1;
    while(--n)
        res<<=1;
    return res;
}

int raw[12][10000],p,a,b,n,l,cnt;
bool seq[200008];
char c,res[24];

int main(){
    ifstream fin("contact.in");
    ofstream fout("contact.out");

    fin>>a>>b>>n;
    int i,j;

    while(fin>>c){
        if(c=='0')
            seq[l++]=0;
        else if(c=='1')
            seq[l++]=1;
    }

    for (int k = a; k <=b; k++) {
        if(l<k)
            continue;
        p=0;
        int mask=ma(k);
        for (i = 0; i < k; i++)
            p=p<<1|seq[i];
        if(!raw[k-1][p])
            cnt++;
        raw[k-1][p]++;
        while(i<l){
            p=((p&(~mask))<<1)|seq[i++];
            if(!raw[k-1][p])
                cnt++;
            raw[k-1][p]++;
        }
    }
    ans *dat=new ans[cnt];
    p=0;
    for (i = a-1; i < b; i++) {
        for (j = 0; j < 4096; j++) {
            if(raw[i][j]){
                dat[p].len=i+1;
                dat[p].val=j;
                dat[p++].freq=raw[i][j];
            }
        }
    }

    sort(dat,dat+cnt,cmp);
    i=0;
    while(n-- && i<cnt){
        p=dat[i].freq;
        fout<<p<<endl;
        j=0;
        while(i<cnt && dat[i].freq==p){
            if(j%6) fout<<" ";
            conb(dat[i].val,dat[i].len,res);
            fout<<res;
            if(j%6==5)
                fout<<endl;
            i++;
            j++;
        }
        if(j%6)
            fout<<endl;

    }

    return 0;
}

