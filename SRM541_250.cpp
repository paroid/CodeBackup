#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AkariDaisukiDiv2 {
public:
	int countTuples(string);
};

int AkariDaisukiDiv2::countTuples(string S) {
    int res=0,l=S.length();
    string temp;
    for(int i=1;i<l-1;++i){
        for(int j=1;j<=(l-1-i)>>1;++j){
            int mark=res;
            temp=S.substr(i,j);
            int pos=i+j+1;
            while(pos+j<l && (pos=S.find(temp,pos)+1)>0 && pos+j-1<l)
                ++res;
            if(mark==res)
                break;
        }
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

