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

class CountingSeries {
	public:
		long long countThem(long long, long long, long long, long long, long long);
};

long long power(long long a,int b){
	long long res=1;
	while(b--)	res*=a;
	return res;
}

long long CountingSeries::countThem(long long a, long long b, long long c, long long d, long long upperBound) {
	long long Count=0,tmp;
	if(upperBound-a>=0)
		Count+=(upperBound-a)/b+1;
	if(d==1){
		if(c<=upperBound && (c<a || (c-a)%b))		Count++;
	}
	else
		for(int i=0;(tmp=c*power(d,i))<=upperBound;i++)
			if(tmp<a || (tmp-a)%b)	Count++;
	return Count;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!



