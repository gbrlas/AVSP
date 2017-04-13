#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define MAXN 40
using namespace std;
int hash (vector <int> v)
  {
  int N = v.size(), ret = 0;
  for (int i = 0; i < N; i++)
    ret = ret * (N + 1) + v[i];
  return ret;
  }
bool geras (vector <int> v)
  {
  int N = v.size();
  for (int i = 0; i < N; i++)
    if (v[i] > i + 1)
      return false;
  return true;
  }
int main ()
  {
  int i, j, k, l, T, N, ats;
  vector <int> v;
  set <int> buvo;
  queue <pair <vector <int>, int > > q;
  char cstr[MAXN + 1];
  scanf("%d", &T);
  for (i = 0; i < T; i++)
    {
    v.clear();
    buvo.clear();
    scanf("%d\n", &N);
    for (j = 0; j < N; j++)
      {
      scanf("%s", cstr);
      for (k = 0, l = -1; k < N; k++)
        if (cstr[k] == '1')
          l = k;
      v.push_back(l + 1);
      }
    if (!geras(v))
      {
      buvo.insert(hash(v));
      while (!q.empty())
        q.pop();
      q.push(make_pair(v, 0));
      k = N;
      while (k == N)
        {
        v = q.front().first;
        j = q.front().second;
        q.pop();
        for (k = 1; k < N; k++)
          if (v[k] < v[k - 1])
            {
            swap(v[k], v[k - 1]);
            l = hash(v);
            if (buvo.find(l) == buvo.end())
              {
              buvo.insert(l);
              q.push(make_pair(v, j + 1));
              if (geras(v))
                {
                ats = j + 1;
                break;
                }
              }
            swap(v[k], v[k - 1]);
            }
        }
      }
      else
      ats = 0;
    printf("Case #%d: %d\n", i + 1, ats);
    }
  return 0;
  }
