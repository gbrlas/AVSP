//



#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <math.h>


using namespace std;


template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)


int f[20][600];
int cnt[20][600];

int n = 19, m;
char mm[600];
char wel[] = "welcome to code jam";

int main(){
    int t;
    scanf("%d\n", &t);
    FOR (tt, 1, t+1)
    {
        gets(mm);
        m = strlen(mm);
        //OUT(mm);
        REP (i, n)
        {
            REP (j, m)
            {
                f[i][j] = cnt[i][j] = 0;
            }
        }

        if (wel[0] == mm[0])    cnt[0][0] = f[0][0] = 1;
        FOR (j, 1, m)
        {
            if (wel[0] == mm[j]) cnt[0][j]++;

            f[0][j] = cnt[0][j] % 10000;
        }

        FOR (i, 1, n)
        {
            FOR (j, i, m)
            {
                if (wel[i] == mm[j])
                {
                    cnt[i][j]++;
                }
                FOR (k, i-1, j)
                {
                     f[i][j] += (cnt[i][j] - cnt[i][k]) * f[i-1][k] % 10000;
                     f[i][j] %= 10000;
                }
            }
        }
        int ans = 0;
         REP (j, m)
        {
            ans = (ans + f[n-1][j]) % 10000;
        }

        //out(f, n, m);

        printf("Case #%d: %04d\n", tt, ans);
    }
    return 0;
}

