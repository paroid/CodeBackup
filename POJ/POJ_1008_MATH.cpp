#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

#define MAXN 200002

string month[20]={"","pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string Tmon[21]={"","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
string tmp;
int n,d,y;

int finA(string s){
    for(int i=1;i<20;i++)
        if(month[i]==s)
            return i;
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    scanf("%d\n",&n);
    int cnt=0;
    cout<<n<<endl;
    while(cnt++<n){
        scanf("%d.",&d);
        cin>>tmp>>y;
        int sum=0,m;
        sum+=y*365;
        sum+=(finA(tmp)-1)*20;
        sum+=d+1;
        sum--;
        y=sum/260;
        sum++;
        sum%=260;
        if(!sum)
            sum=260;
        tmp=Tmon[!(sum%20)?20:sum%20];
        d=!(sum%13)?13:sum%13;
        cout<<d<<" "<<tmp<<" "<<y<<endl;
    }


    return 0;
}

