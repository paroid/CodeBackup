/*
ID:chenke61
PROG:msquare
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

typedef struct _node {
    int stat,pre;
    short op;
} node;

node que[403220];
bool hash[2100000];
int target,tmp,head,tail,n;
char S[4]={' ','A','B','C'};

int A(int in){
    return (in>>12)|((in&07777)<<12);
}

int B(int in){
    return ((in&07770000)<<3|(in&070000000)>>9)|((in&0777)<<3|(in&07000)>>9);
}

int C(int in){
    return (in&070077007)|(in&070)<<3|(in&0700)<<12|(in&0700000)>>12|(in&07000000)>>3;
}

int main(){
    ifstream fin("msquare.in");
      ofstream fout("msquare.out");

    for(int i=0;i<8;i++){
        fin>>tmp;
        if(i&4)
            target|=(tmp-1)<<((11-i)*3);
        else 
            target|=(tmp-1)<<(i*3);
    }

    que[0].pre=-1;
    que[0].op=0;
    que[0].stat=045673210;

    if(que[0].stat==target){
        fout<<0<<endl<<endl;
        return 0;
    }
    tail=0;
    n=1;
    hash[que[0].stat&007777777]=true;
    while(1){
        head=tail;
        tail=n;
        for(int i=head;i<tail;i++){
            int tt;
            if(que[i].op==-1)
                continue;
            que[n].pre=i;
            que[n].op=1;
            que[n].stat=A(que[i].stat);
            if(que[n].stat==target)
               break;
            tt=que[n].stat&007777777;
            if(hash[tt])
               que[n].op=-1;
            hash[tt]=true;
            n++;
            que[n].pre=i;
            que[n].op=2;
            que[n].stat=B(que[i].stat);
            if(que[n].stat==target)
               break;
            tt=que[n].stat&007777777;
            if(hash[tt])
               que[n].op=-1;
            hash[tt]=true;
            n++;
            que[n].pre=i;
            que[n].op=3;
            que[n].stat=C(que[i].stat);
            if(que[n].stat==target)
               break;
            tt=que[n].stat&007777777;
            if(hash[tt])
               que[n].op=-1;
            hash[tt]=true;
            n++;
        }
        if(que[n].stat==target){
            char ans[80];
            int i=0;
            while(n){
                ans[i++]=S[que[n].op];
                n=que[n].pre;
            }
            fout<<i<<endl;
            for(int j=i-1;j>=0;j--)
                fout<<ans[j];
            fout<<endl;
            break;
        }
    }

    return 0;
}






