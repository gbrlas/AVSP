#include <iostream>
#define oo 1000000001
#define DOWN(i,a,b) for(long i = a; i >= b; i--)
#define FOR(i,a,b) for(long i = a; i <= b; i++)

using namespace std;
long n,m,a[103],f[103][103],s[103],sl = 0;
bool d[10003],w[103][103];
void solve()
{
     scanf("%ld%ld",&n,&m);
     long u;
     memset(d,false,sizeof(d));
     FOR(i,1,m) 
     {
         scanf("%ld",&u);
         d[u] = true;
     };
     long sl = 1;
     memset(a,0,sizeof(a));
     FOR(i,1,n)
     {
         if (d[i]) sl++;
         else a[sl]++;
     };
     FOR(i,1,sl) s[i] = s[i-1] + a[i];
     DOWN(i,sl,1)
     {
         f[i][i] = 0;
         FOR(j,i+1,sl)
             {
                f[i][j] = oo;
                FOR(k,i,j-1)
                   f[i][j] = min (f[i][j],f[i][k] + f[k+1][j] + s[j]-s[i-1] + (j-i-1) );
             };
     };
     cout << f[1][sl] << endl;
};
int main()
{
    freopen("fish9.in","r",stdin);
    freopen("TEST.OUT","w",stdout);
    long ntest;
    scanf("%ld",&ntest);
    FOR(test,1,ntest)
    {
         cout << "Case #" << test << ": ";
         solve();
    };
    return 0;
};
