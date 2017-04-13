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

#define MAXL 20
#define MAXD 5005
#define MAXN 505

int L, D, N;
int next[MAXD * MAXL][26];
int cnt[MAXD * MAXL];
int last;
char s[1000];
char word[MAXD][MAXL];

void add(int root, char *s)
{
   int j = root;
   for (int i = 0; s[i] != 0; i++)
   {
      if (!next[j][s[i] - 'a'])
         next[j][s[i] - 'a'] = ++last;
      j = next[j][s[i] - 'a'];
   }
   cnt[j]++;
}

int go(int v, char *s)
{
   int res = 0;
   if (s[0] == 0)
   {
      res += cnt[v];
   }
   else if (s[0] == '(')
   {
      int t = 0;
      while (s[t] != ')')
         t++;
      for (int i = 1; i < t; i++)
         if (next[v][s[i] - 'a'])
            res += go(next[v][s[i] - 'a'], s + t + 1);
   }
   else
   {
      assert(isalpha(s[0]));
      if (next[v][s[0] - 'a'])
         res += go(next[v][s[0] - 'a'], s + 1);
   }
   return res;
}

int main()
{
   scanf("%d%d%d", &L, &D, &N);
   for (int i = 0; i < D; i++)
   {
      scanf("%s", word[i]);
      add(0, word[i]);
   }
   for (int i = 0; i < N; i++)
   {
      scanf("%s", s);
      printf("Case #%d: %d\n", i + 1, go(0, s));
   }
   return 0;
}
