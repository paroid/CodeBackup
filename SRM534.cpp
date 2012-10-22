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
#define max(a,b) ((a)>(b)?(a):(b))//NOTES:MAX(
#define min(a,b) ((a)<(b)?(a):(b))//NOTES:MIN(
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE( 
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH( 
#define MP(X,Y) make_pair(X,Y)//NOTES:MP( 
typedef long long int64;//NOTES:int64 
typedef unsigned long long uint64;//NOTES:uint64 
#define two(X) (1<<(X))//NOTES:two( 
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL( 


using namespace std;

class EllysCheckers {
public:
	string getWinner(string);
};

string EllysCheckers::getWinner(string board) {
	int l=LENGTH(board);
    bool win=false,ini=!(l&1);
    for(int i=0;i<n-1;i++){
        if(board[i]=='o')
            win^=ini;
        ini=!ini;
    }
    return win?"YES":"NO";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!


