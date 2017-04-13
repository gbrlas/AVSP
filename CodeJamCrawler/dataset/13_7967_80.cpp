// includes {
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
// }
using namespace std;
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define sqr(a) (a)*(a)
#define inrange(lb,i,ub) ((lb) <= (i) && (i) <= (ub))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};


bool fsquare[1001];
int sum[1001];

inline int rev_number(int n)
{
    int m=0;
    while(n>0)
        m = (m*10) + (n%10), n /= 10;
    return m;
}

inline bool is_fsquare(int n)
{
    int root = sqrt(n);
    return ( root*root == n ) && ( rev_number(n) == n ) && ( rev_number(root) == root );
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int cont, tc, TC, A, B;

	fsquare[0] = false, sum[0] = 0;
	REP(cont,1000)
        fsquare[cont] = is_fsquare(cont);
    REP(cont,1000)
        sum[cont] = sum[cont-1] + ( fsquare[cont] ? 1 : 0 );
    //REP(cont,1000) if( fsquare[cont] ) cout << cont << endl;

    scanf("%d", &TC);
    REP(tc,TC)
    {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", tc, sum[B]-sum[A-1]);
    }

    fclose(stdout);
    return 0;
}
