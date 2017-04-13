#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int T;
int n;
const int N=1010;
double a[N],b[N];
set <double> aa,bb;

int main()
{
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
  cin >>T;
  for (int ii=1;ii<=T;ii++)
    {
      cin >>n;
      aa.clear(); bb.clear();
      for (int i=1;i<=n;i++) {cin >>a[i]; aa.insert(a[i]);}
      for (int i=1;i<=n;i++) {cin >>b[i]; bb.insert(b[i]);}
      sort(a+1,a+n+1); sort(b+1,b+n+1);
      int ans1=0;
      for (int i=1;i<=n;i++)
	{
	  set <double>::iterator it=bb.begin();
	  if (a[i]>*it)
	    {
	      ans1++;
	      bb.erase(it);
	    }
	  else
	    {
	      it=bb.end(); it--;
	      bb.erase(it);
	    }
	}
      for (int i=1;i<=n;i++) bb.insert(b[i]);
      int ans2=0;
      for (int i=1;i<=n;i++)
	{
	  set <double>::iterator it=bb.upper_bound(a[i]);
	  if (it==bb.end())
	    {
	      ans2++;
	      it=bb.begin();
	      bb.erase(it);
	    }
	  else
	    {
	      bb.erase(it);
	    }
	}
      printf("Case #%d: %d %d\n",ii,ans1,ans2);
    }
  return 0;
}
