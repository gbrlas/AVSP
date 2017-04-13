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

#define POSIBLE_CNTS 10
#define X_WON 1
#define O_WON 2
#define NO_WINNER 0
char mat[5][5];
int cnt[2][POSIBLE_CNTS];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("data.out", "w", stdout);
	#endif

	int tc, TC, i, j, k;
	int won; bool hasDot;

	cin >> TC; getchar();
	REP(tc,TC)
	{
        FOR(i,5) gets(mat[i]);
        won = NO_WINNER;
        hasDot = false;

        // Pasamos los valores de las filas
        memset(cnt, 0, sizeof cnt);
        FOR(i,4) FOR(j,4)
        {
            const char& c = mat[i][j];
            if( c=='.' ) hasDot=true;
            FOR(k,2)
            {
                char c2 = (k==0?'X':'O');
                if( c == c2 || c == 'T' )
                {
                    cnt[k][i]++;
                    cnt[k][4+j]++;
                    if( i==j )   cnt[k][8]++;
                    if( i==3-j ) cnt[k][9]++;
                }
            }
        }

        // Verificamos si alguien gano
        k = 0;
        while( k < 2 && won == NO_WINNER )
        {
            FOR(i,POSIBLE_CNTS)
            {
                if( cnt[k][i] == 4 )
                {
                    won = k+1;
                    break;
                }
            }
            k++;
        }

        // Salida
        printf("Case #%d: ", tc);
        if( won == X_WON )
            puts("X won");
        else if ( won == O_WON )
            puts("O won");
        else if ( hasDot )
            puts("Game has not completed");
        else
            puts("Draw");
	}

    fclose(stdout);
    return 0;
}
