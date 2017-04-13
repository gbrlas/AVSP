#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <map>
#include <set>

using namespace std;

int main()
{
  freopen( "B-small-attempt1.in", "rt", stdin );
  freopen( "b.out", "wt", stdout );

  int n;
  scanf("%d", &n);
  for (int t = 0; t < n; ++t)
  {
    long long v;
    scanf("%lld", &v);

    char buf[200];
    sprintf(buf, "%lld", v);

    int len = strlen(buf);
    if (!next_permutation(buf, buf+len))
    {
      buf[len]='0';
      buf[len+1] = 0;
      assert(len+1 < sizeof(buf));
      len++;

      int k = count(buf, buf+len, '0');
      sort(buf, buf+len);

      char xx[200]={};
      xx[0] = buf[k];
      for (int i = 1; i <= k; ++i) xx[i] = '0';
      strcpy(&xx[k+1], &buf[k+1]);
      strcpy(buf, xx);
    }
    printf("Case #%d: %s\n", t+1, buf);
  }
}