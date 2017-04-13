#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int T;
int n,m;
struct Trie
{
  int next[26];
  void init()
  {
    for (int i=0;i<26;i++) next[i]=0;
  }
}Tr[5000000];
int Tnum;
int root[5];
string s[10];
int no[10];
int ans1,ans2;

void Solve()
{
  Tnum=0;  
  int num[5];
  memset(num,0,sizeof(num));
  for (int i=1;i<=m;i++)
    num[no[i]]++;
  for (int i=1;i<=n;i++) if (num[i]==0) return;
  for (int i=1;i<=n;i++) {root[i]=++Tnum; Tr[Tnum].init();}
  for (int i=1;i<=m;i++)
    {
      int r=root[no[i]];
      int len=s[i].length();
      for (int j=0;j<len;j++)
	{
	  if (Tr[r].next[s[i][j]-'A']==0)
	    {
	      Tr[r].next[s[i][j]-'A']=++Tnum;
	      Tr[Tnum].init();
	    }
	  r=Tr[r].next[s[i][j]-'A'];
	}
    }
  if (ans1<Tnum)
    {
      ans1=Tnum;
      ans2=1;
    }
  else
    if (ans1==Tnum) ans2++;
}

void dfs(int now)
{
  if (now==m+1)
    {
      Solve();
      return;
    }
  for (int i=1;i<=n;i++)
    {
      no[now]=i;
      dfs(now+1);
    }
}

int main()
{
  cin >>T;
  for (int ii=1;ii<=T;ii++)
    {
      cin >>m >>n;
      for (int i=1;i<=m;i++) cin >>s[i];
      ans1=0; ans2=0;
      dfs(1);
      printf("Case #%d: %d %d\n",ii,ans1,ans2);
    }
  return 0;

}
