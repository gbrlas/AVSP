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

char words[5001][20];

int L, D, N;
char p[1000];

int main(){
    while (EOF != scanf("%d %d %d\n", &L, &D, &N))
    {
        REP (i, D) gets(words[i]);

        FOR (i, 1, N+1)
        {
            gets(p);
            int len = strlen(p);
            //OUT(len);
            int cnt = 0;
            REP (j, D)
            {
                int ok = 0;
                int ii = 0;
                REP (k, L)
                {
                    if ('(' == p[ii])
                    {
                        ++ii;
                        while (')' != p[ii] && ii < len)
                        {
                            if (words[j][k] == p[ii])
                            {
                                ok++;
                            }
                            ++ii;
                        }
                    }
                    else
                    {
                        if (p[ii] == words[j][k])
                        {
                            ok++;
                        }
                    }
                    ++ii;
                }
                //OUT(ok);
                if (L == ok) cnt++;
            }
            printf("Case #%d: %d\n", i, cnt);
        }
    }
    return 0;
}
