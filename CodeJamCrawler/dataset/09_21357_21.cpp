#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;

#define sz(c) ((int) (c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MAXN 45

int N;
char a[MAXN][MAXN];
int len[MAXN];

int main()
{
   int T;
   scanf("%d\n", &T);
   for (int tt = 0; tt < T; tt++)
   {
      scanf("%d\n", &N);
      for (int i = 0; i < N; i++)
         gets(a[i]);
      int res = 0;
      memset(len, 0, sizeof(len));
      for (int i = 0; i < N; i++)
      {
         for (int j = N - 1; j >= 0 && a[i][j] == '0'; j--)
            len[i]++;
         len[i] = N - len[i];
      }
      for (int i = 0; i < N; i++)
         if (len[i] > i + 1)
         {
            int j = i + 1;
            while (len[j] > i + 1)
               j++;
            while (j != i)
            {
               swap(len[j], len[j - 1]);
               j--;
               res++;
            }
         }
      printf("Case #%d: %d\n", tt + 1, res);
   }
   return 0;
}
