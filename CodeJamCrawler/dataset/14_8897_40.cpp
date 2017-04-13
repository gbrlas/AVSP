#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int T;
int n,m;
const int N=10010;
int a[N];
bool check[N];
struct Node
{
  int key,no;
  bool operator < (const Node &A) const
  {
    return key<A.key||key==A.key&&no<A.no;
  }
};
set <Node> s;

int main()
{
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++) scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      s.clear();
      for (int i=1;i<=n;i++)
	{
	  Node tmp;
	  tmp.key=a[i];
	  tmp.no=i;
	  s.insert(tmp);
	}
      int ans=0;
      memset(check,0,sizeof(check));
      for (int i=n;i>=1;i--)
	{
	  if (check[i]) continue;
	  ans++;
	  Node tmp;
	  tmp.key=a[i]; tmp.no=i;
	  set <Node>::iterator it=s.find(tmp);
	  s.erase(it);
	  int l=m-a[i];
	  tmp.key=l;
	  it=s.lower_bound(tmp);
	  if (it==s.begin()) continue;
	  it--;
	  check[it->no]=1;
	  s.erase(it);
	}
      printf("Case #%d: %d\n",ii,ans);
    }
  return 0;
}
