#include <iostream>
#define FOR(i,a,b) for(long i = a; i <= b; i++)
#include <map>
using namespace std;
map<char,int> Map;
long n,a[100];
char p[100];

void solve()
{
     Map.clear();
     gets(p);
     n = strlen(p);
     Map[p[0]] = 1;
     a[0] = 1;
     long sl = -1;
     FOR(i,1,n-1)
     {
          if (Map.find(p[i]) != Map.end()) a[i] = Map[p[i]];
          else
          {
              sl++;
              if (sl == 1) sl++;
              Map[p[i]] = sl;  
              a[i] = sl;
          };
     };
     if (sl < 1) sl = 1;
     long long val = sl + 1;
     long long result = 0;
     FOR(i,0,n-1) result = result * val + a[i];
     cout << result << endl;
};
int main()
{
    freopen("fish3.in","r",stdin);
    freopen("TEST.OUT","w",stdout);
    long ntest;
    scanf("%ld\n",&ntest);
    FOR(test,1,ntest)
    {
         cout << "Case #" << test << ": ";
         solve();
    };
    return 0;
};
