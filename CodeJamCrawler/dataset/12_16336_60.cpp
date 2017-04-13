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

bool valid(int& a, int& b, int& c, int& p);
bool surp(int a, int b, int c);

int main() {
	//freopen("d.in",  "r", stdin);
	//freopen("d.out", "w", stdout);
	
	int test, sc, count, n, s, prom, p, norm, sorp;
	cin>> test;
	REP(t, test){
	    cin>> n>> s>> p;
	    count = 0;
	    while(n--){
	        cin>> sc;
	        norm = sorp = 0;
	        FOR(a, 11)
	            FOR(b, 11)
	                FOR(c, 11)
	                    if(a + b + c == sc && valid(a, b, c, p)){
	                        if(!surp(a, b, c)) ++norm;
	                        else if(s > 0) ++sorp;
	                    }
	        if(norm > 0) ++count;
	        else if(sorp > 0){
	            ++count;
	            --s;
	        }
	    }
	    cout<< "Case #"<< t<< ": "<< count<< endl;
	}
    return 0;
}

bool valid(int& a, int& b, int& c, int& p){
    if(abs(a -b) > 2 || abs(a - c) > 2 || abs(b - c) > 2) return false;
    if(a < p && b < p && c < p) return false;
    return true;
}

bool surp(int a, int b, int c){
    int aux;
    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }
    if(b > c){
        aux = c;
        c = b;
        b = aux;
    }
    if(a > b){
        aux = a;
        a = b;
        b = aux;
    }
    c -= a;
    if(c == 2) return true;
    return false;
}
