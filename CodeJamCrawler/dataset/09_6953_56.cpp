#include <cstdio>
#include <string>
#include <set>
using namespace std;
set <string> aibe;
struct Node
  {
  double p;
  string s;
  Node * t;
  Node * n;
  };
void skaityk (Node & n)
  {
  char c;
  while ((c = getchar()) != '(');
  scanf("%lf", &n.p);
  while ((c = getchar()) != ')')
    if (c >= 'a' && c <= 'z')
      break;
  if (c != ')')
    {
    while (c >= 'a' && c <= 'z')
      {
      n.s += c;
      c = getchar();
      }
    n.t = new Node;
    n.n = new Node;
    skaityk(*(n.t));
    skaityk(*(n.n));
    while ((c = getchar()) != ')');
    }
  }
double gyvunas (Node & n, double prad)
  {
  if (n.s.empty())
    return prad * n.p;
    else
    {
    if (aibe.find(n.s) == aibe.end())
      return gyvunas(*(n.n), prad * n.p);
      else
      return gyvunas(*(n.t), prad * n.p);
    }
  }
int main ()
  {
  int i, N, L, A, n, j;
  char cstr[11], c;
  Node medis;
  scanf("%d", &N);
  for (i = 0; i < N; i++)
    {
    scanf("%d\n", &L);
    skaityk(medis);
    scanf("%d", &A);
    printf("Case #%d:\n", i + 1);
    for (j = 0; j < A; j++)
      {
      scanf("%s %d", cstr, &n);
      aibe.clear();
      while (n > 0)
        {
        scanf("%s", cstr);
        aibe.insert(string(cstr));
        n--;
        }
      printf("%.7lf\n", gyvunas(medis, 1));
      }
    medis.s.clear();
    }
  return 0;
  }
