// skaito nuo galo, kai perskaito nebe didžiausią, vietoj jo įdeda didesnį, likusius surikiuoja; jei perskaito visus, deda mažiausią, tada 0 ir likusius surikiuoja
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main ()
  {
  int i, T;
  char csk[22], c, l, j, max;
  multiset <char> ms;
  multiset <char> :: iterator it;
  scanf("%d\n", &T);
  for (i = 0; i < T; i++)
    {
    ms.clear();
    for (l = 0; (c = getchar()) != '\n'; l++)
      csk[l] = c;
    for (j = l - 1; j >= 0; j--)
      {
      ms.insert(csk[j]);
      if (csk[j] != *(ms.rbegin()))
        break;
      }
    if (j >= 0)
      {
      it = ms.upper_bound(csk[j]);
      csk[j++] = *it;
      ms.erase(it);
      while (j < l)
        {
        csk[j++] = *(ms.begin());
        ms.erase(ms.begin());
        }
      }
      else
      {
      l++;
      it = ms.upper_bound('0');
      csk[0] = *it;
      ms.erase(it);
      csk[1] = '0';
      for (j = 2, it = ms.begin(); it != ms.end(); it++, j++)
        csk[j] = *it;
      }
    csk[l] = 0;
    printf("Case #%d: %s\n", i + 1, csk);
    }
  return 0;
  }
