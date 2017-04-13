#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
class Dir
{
  public:
  char* name;
  set <Dir> nodes;
  Dir() {}
  Dir(char* kname)
  {
    name = new char[strlen(kname) + 1];
    strcpy(name, kname);
  }
  bool operator<(const Dir& d2) const
  {
    return strcmp(name, d2.name) < 0;
  }
};
int skaityk(set<Dir>* pSet)
{
  getchar();
  char str[101], c = 0, i = 0;
  int ret = 0;
  while (c != '\n')
  {
    pair <set<Dir>::iterator, bool> pora;
    while ((c = getchar()) != '\n' && c != '/')
    {
      str[i++] = c;
    }
    str[i] = 0;
    pora = pSet->insert(Dir(str));
    memcpy(pSet, &((pora.first)->nodes), sizeof(pSet));
    if (pora.second)
      ret++;
  }
  return ret;
}
int main()
{
  int T, t, N, M, i, ats;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    Dir root;
    ats = 0;
    scanf("%d %d\n", &N, &M);
    for (i = 0; i < N; i++)
      skaityk(&(root.nodes));
    for (i = 0; i < M; i++)
      ats += skaityk(&(root.nodes));
    printf("Case #%d: %d\n", t, ats);
  }
}
