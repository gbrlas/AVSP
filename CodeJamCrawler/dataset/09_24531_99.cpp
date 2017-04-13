#include <iostream>
#define FOR(i,a,b) for(long i = a; i <= b; i++)
using namespace std;
long test,m,n,f[600][30];
char s[600];
const char p[20] = "welcome to code jam";
void solve()
{
    test++;
    cout << "Case #" << test << ": ";
    gets(s);
    n = strlen(s);
    FOR(i,0,n) f[i][0] = 1;
    FOR(i,1,n)
    FOR(j,1,m)
    if (s[i-1] == p[j-1]) f[i][j] = (f[i-1][j] + f[i-1][j-1]) % 10000;
    else f[i][j] = f[i-1][j];
    long x = f[n][m],num = 0;
    while (x)
    {
         num++;
         x = x/10;
    };
    FOR(i,1,4-num) cout << "0";
    if (f[n][m]) cout << f[n][m] << endl;
    else cout << endl;
};
int main()
{
//    freopen("TESTc.in","r",stdin);
//    freopen("TEST.OUT","w",stdout);
    m = strlen(p);
    long ntest;
    scanf("%ld\n",&ntest);
    while (ntest--) solve();    
    return 0;
};
