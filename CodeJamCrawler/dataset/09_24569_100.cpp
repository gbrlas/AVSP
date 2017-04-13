#include <iostream>
#define oo 1000000001
#define DOWN(i,a,b) for(long i = a; i >= b; i--)
#define FOR(i,a,b) for(long i = a; i <= b; i++)

using namespace std;
long n,m,f[200][200];
bool d[200],w[200][200];
void solve()
{
     scanf("%ld%ld",&n,&m);
     memset(d,false,sizeof(d));
     long u;
     FOR(i,1,m) 
     {
         scanf("%ld",&u);
         d[u] = true;
     };
     memset(f,0,sizeof(f));
     memset(w,false,sizeof(w));
     DOWN(i,n,1)
     FOR(j,i+1,n)
     FOR(k,i,j)
     if (d[k]) w[i][j] = true;
     DOWN(i,n,1)
     {
         FOR(j,i+1,n)
             {
                if (!w[i][j])
                {
                   f[i][j] = 0;
                   continue;
                };
                f[i][j] = oo;
                FOR(k,i,j)
                   if (d[k]) f[i][j] = min(f[i][j],f[i][k-1] + f[k+1][j] 
                                                  + (j - i));
             };
     };
     cout << f[1][n] << endl;
};
int main()
{
    freopen("fish8.IN","r",stdin);
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
