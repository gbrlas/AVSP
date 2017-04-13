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


int a[100][100];
int Z[101][200]; // Z[numero][fila o N+columna], filas o columnas en base 0
int main() {
	#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int N,M,T,tc;
	int i,j,k,max_a;
	bool yes;

	scanf("%d", &T);
	REP(tc,T)
	{
        scanf("%d %d", &N, &M);

        max_a = 0;
        FOR(i,N) FOR(j,M)
        {
            scanf("%d", &a[i][j]);
            max_a = max(a[i][j],max_a);
        }

        memset(Z, 0, sizeof Z);
        FOR(i,N) FOR(j,M)
        {
            for(k=max_a; k>=a[i][j]; k--)
            {
                Z[k][i]++;
                Z[k][N+j]++;
            }
        }

        yes = true;
        FOR(i,N) FOR(j,M)
        {
            int& h = a[i][j];
            int& row = Z[h][i];
            int& col = Z[h][N+j];

            if( row!=M && col!=N )
            {
                yes = false;
                break;
            }
        }
        //for(i=1; i<=max_a; i++) cout << freq[i] << " "; puts("");

        printf("Case #%d: %s\n", tc, ( yes ? "YES" : "NO" ) );
	}

    fclose(stdout);
    return 0;
}
