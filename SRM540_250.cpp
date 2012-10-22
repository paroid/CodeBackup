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

class RandomColoringDiv2 {
    public:
        int getCount(int, int, int, int, int, int, int, int);
};

int RandomColoringDiv2::getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
    return (min(startR+d2,maxR-1)-max(startR-d2,0)+1)*(min(startG+d2,maxG-1)-max(startG-d2,0)+1)*(min(startB+d2,maxB-1)-max(startB-d2,0)+1)-(d1?((min(startR+d1-1,maxR-1)-max(startR-d1+1,0)+1)*(min(startG+d1-1,maxG-1)-max(startG-d1+1,0)+1)*(min(startB+d1-1,maxB-1)-max(startB-d1+1,0)+1)):0);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!


