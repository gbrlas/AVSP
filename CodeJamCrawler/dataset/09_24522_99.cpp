#include <iostream>
#define FOR(i,a,b) for(long i = a; i<= b;i++)
using namespace std;
int num,n,sl,N,D,L,f[100][300];
char a[5003][100],s[200];
void solve()
{
     bool ok;
     num++;
     n = strlen(s);
     sl = 1;
     FOR(i,0,n-1)
     {
          if (s[i] == '(')
          {
              ok = true;
          } else
          if (s[i] == ')')
          {
              ok = false;
              sl++;
          } else
          {
              if (ok) f[sl][s[i]] = num;
              else {
                       f[sl][s[i]] = num;
                       sl++;
                   }; 
          };
     };
     long result = 0;
     FOR(i,1,D)
     {
          ok = true;     
          FOR(j,1,L)
              if (f[j][a[i][j]] != num)
                 {
                     ok = false;
                     break;
                 };
          if (ok) result++;
     };
     cout << result << endl;
};
int main()
{
//    freopen("ALIEN.IN","r",stdin);
//    freopen("ALIEN_LAN.OUT","w",stdout);
    scanf("%ld%ld%ld\n",&L,&D,&N);
    FOR(i,1,D)
       {
           gets(s);
           FOR(j,1,L) a[i][j] = s[j-1];
       };
    FOR(i,1,N)
       {
           gets(s);
           cout << "Case #" << i << ": ";
           solve();
       };
    return 0;
};
