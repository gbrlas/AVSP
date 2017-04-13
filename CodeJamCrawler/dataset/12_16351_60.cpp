#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define REP(i,n)    for(int i=1;i<=(n);++i)
#define FOR(i,n)    for(int i=0;i<(n);++i)
#define FORE(i,e,n) for(int i=(e);i<(n);++i)

#define out(v) cout<<(v)<<endl
#define _(A,v) memset(A,v,sizeof(A))
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define inf INT_MAX

#define sz size()
#define pb push_back

typedef long long int lint;
typedef pair<int, int> PI;
typedef vector<int> VI;
typedef set<int> SI;

int main() {
	//freopen("d.in",  "r", stdin);
	//freopen("d.out", "w", stdout);
	
	int a = 10, b, n, m, test, dec = 10, m1, m2, c = 2;
	vector<SI> pairs(2000001);
	vector<int> un(7);
	set<int>::iterator it;
	SI pos;
	
	while(a < 2000001){
	    if(dec * 10 <= a){ dec *= 10; ++c;}
	    m1 = a;
	    m2 = 0;
	    while(m1 > 0){
	        un[c - (++m2)] = m1 % 10;
	        m1 /= 10;
	    }
	    FOR(i, c){
	        m1 = i;
	        m2 = un[m1];
	        while(m1 = (m1 + 1)  % c, m1 != i){
	            m2 *= 10;
	            m2 += un[m1];
	        }
	        if(a < m2) pairs[a].insert(m2);
	    }
	    ++a;
	}
	cin>> test;
	REP(t, test){
	    cin>> a>> b;
	    m1 = 0;
	    pos.clear();
	    if(b > 9 && a < b){
	        n = a;
	        while(n < b){
	            for(it = pairs[n].begin();it != pairs[n].end();++it)
	                if(*it <= b)
	                    ++m1;
	            ++n;
	        }
	    }
	    cout<< "Case #"<< t<< ": "<< m1<< endl;
	}
    return 0;
}
