#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

#define sz(c) ((int) (c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MAXN 1000

const char w[] = "welcome to code jam";
const int len = 19;

int N;
char s[MAXN];
int dp[len][MAXN];

#define mod(x) ((x) % 10000)

int main()
{
   scanf("%d\n", &N);
   for (int t = 0; t < N; t++)
   {
      gets(s);
      memset(dp, 0, sizeof(dp));
      for (int i = 0; i < len; i++)
      {
         int t = 0;
         if (!i)
            t = 1;
         for (int j = 0; s[j] != 0; j++)
         {
            if (s[j] == w[i])
               dp[i][j] = mod(dp[i][j] + t);
            if (i)
               t = mod(t + dp[i - 1][j]);
         }
      }
      int res = 0;
      for (int i = 0; s[i] != 0; i++)
         res = mod(res + dp[len - 1][i]);
      printf("Case #%d: %04d\n", t + 1, res);
   }
   return 0;
}
