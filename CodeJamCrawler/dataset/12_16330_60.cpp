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

int main() {
	//freopen("d.in",  "r", stdin);
	//freopen("d.out", "w", stdout);
	
	map<char, char> dic;
    dic['a'] = 'y'; dic['b'] = 'h'; dic['c'] = 'e'; dic['d'] = 's';
    dic['e'] = 'o'; dic['f'] = 'c'; dic['g'] = 'v';
    dic['h'] = 'x'; dic['i'] = 'd'; dic['j'] = 'u'; dic['k'] = 'i';
    dic['l'] = 'g'; dic['m'] = 'l'; dic['n'] = 'b'; dic['o'] = 'k';
    dic['p'] = 'r'; dic['q'] = 'z'; dic['r'] = 't'; dic['s'] = 'n';
    dic['t'] = 'w'; dic['u'] = 'j'; dic['v'] = 'p'; dic['w'] = 'f';
    dic['x'] = 'm'; dic['y'] = 'a'; dic['z'] = 'q';
    
    int test, rec, tam;
    string pal;
    cin>> test;
    getline(cin, pal);
    REP(t, test){
        getline(cin, pal);
        rec = 0;
        tam = pal.sz;
        while(rec < tam){
            if(pal[rec] >= 'a' && pal[rec] <= 'z')
                pal[rec] = dic[pal[rec]];
            ++rec;
        }
        cout<< "Case #"<< t<< ": "<< pal<< endl;
    }
    return 0;
}
