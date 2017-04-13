#include <iostream>
#define oo 1000000002
#define FOR(i,a,b) for(long i = a; i <= b; i++)
using namespace std;
long n,m,sl,a[103][103],f[103][103],lab[10003],test = 0;
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};
long visit(long i,long j)
{
     if (f[i][j] != -1) return f[i][j];
     f[i][j] = 0;
     long val = oo;
     FOR(k,0,3) val = min(val,a[i+dx[k]][j+dy[k]]);
     FOR(k,0,3)
     if (a[i+dx[k]][j+dy[k]] == val)
        {
            f[i][j] = visit(i + dx[k],j + dy[k]);
            break;
        };
     return f[i][j];
};
void solve()
{
     test ++;
     cout << "Case #" << test << ":" << endl;
     scanf("%ld%ld",&m,&n);
     FOR(i,1,m)
        FOR(j,1,n) scanf("%ld",&a[i][j]);
     FOR(i,0,n+1)
         {
              a[0][i] = oo;
              a[m+1][i] = oo;
         };
     FOR(i,0,m+1)
         {
              a[i][0] = oo;
              a[i][n+1] = oo;   
         };
     sl = 0;
     bool ok;
     FOR(i,1,m)
     FOR(j,1,n)
        {
             f[i][j] = -1;  
             ok = true;
             FOR(k,0,3)
                 if (a[i+dx[k]][j+dy[k]] < a[i][j]) 
                    {
                        ok = false;
                        break;
                    };
             if (ok) 
                {
                     sl++;
                     f[i][j] = sl;
                };
        };
     FOR(i,1,m)
     FOR(j,1,n) if (f[i][j] == -1) f[i][j] = visit(i,j);
     memset(lab,0,sizeof(lab));
     sl = 0;
     FOR(i,1,m)
     FOR(j,1,n)
     {
         if (!lab[f[i][j]])
            {
                sl++;
                lab[f[i][j]] = sl;
            };
     };
     FOR(i,1,m)
         {
             FOR(j,1,n) cout << (char) (lab[f[i][j]] + 96) << " ";
             cout << endl;
         };
};
int main()
{
//    freopen("TEST2.IN","r",stdin);
//    freopen("CODEJAM09_B.OUT","w",stdout);
    long ntest;
    scanf("%ld",&ntest);
    while (ntest--) solve();
    return 0;
};
