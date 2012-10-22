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

class CheatingQuiz {
public:
	vector <int> howMany(string);
};

vector <int> CheatingQuiz::howMany(string answers) {
    int count[3],n=answers.length(),m=0;
    vector <int> res;
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++)
        count[answers[i]-'A']++;
    for(int i=0;i<3;i++)
        if(count[i])
            m++;
    for(int i=0;i<n;i++){
        res.push_back(m);
        count[answers[i]-'A']--;
        if(!count[answers[i]-'A'])
            m--;
    }
    return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

