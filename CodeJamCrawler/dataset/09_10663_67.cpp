#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int SZ = 1024;
const int N = (1 << 24);

char buff[SZ];
int bases[16][N];

int f(int b, int val)
{
  if (val == 1)
  {
    bases[b][val] = 1;
  }
  if (!bases[b][val])
  {
    bases[b][val] = -1;
    int nval = 0, t = val;
    while (t)
    {
      nval += (t % b) * (t % b);
      t /= b;
    }
    bases[b][val] = f(b, nval);
  }
  return bases[b][val];
}

int main(int argc, char *argv[])
{
  int casesNumber = 0;
  scanf("%d", &casesNumber);
  fgets(buff, SZ, stdin);
  for (int i = 2; i <= 10; ++ i)
    for (int j = 2; j < N; ++ j)
      f(i, j);
  for (int __tc = 0; __tc < casesNumber; ++ __tc)
  {
    vector <int> bas;
    fgets(buff, SZ, stdin);
    int p = 0, l = strlen(buff);
    while (p + 1 < l)
    {
      int off, x;
      sscanf(buff + p, "%d%n", &x, &off);
      p += off;
      bas.push_back(x);
    }
    int sz = bas.size();
    for (int i = 2; i < N; ++ i)
    {
      int j;
      for (j = 0; j < sz; ++ j)
        if (bases[bas[j]][i] == -1)
          break;
      if (j == sz)
      {
        printf("Case #%d: %d\n", __tc + 1, i);
        break;
      }
    }
  }
  return 0;
}
