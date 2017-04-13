#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
const int N=5;
int a[N][N];
int num[17];
int l;

int main()
{
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      memset(num,0,sizeof(num));
      scanf("%d",&l);
      for (int i=1;i<=4;i++) for (int j=1;j<=4;j++) scanf("%d",&a[i][j]);
      num[a[l][1]]++; num[a[l][2]]++; num[a[l][3]]++; num[a[l][4]]++;
      scanf("%d",&l);
      for (int i=1;i<=4;i++) for (int j=1;j<=4;j++) scanf("%d",&a[i][j]);
      num[a[l][1]]++; num[a[l][2]]++; num[a[l][3]]++; num[a[l][4]]++;
      int b=0,ans;
      for (int i=1;i<=16;i++) if (num[i]==2) {b++; ans=i;}
      if (b==0)
	{
	  printf("Case #%d: Volunteer cheated!\n",ii);
	  continue;
	}
      if (b>1)
	{
	  printf("Case #%d: Bad magician!\n",ii);
	  continue;	  
	}
      if (b==1)
	{
	  printf("Case #%d: %d\n",ii,ans);
	  continue;	  
	}
    }
  return 0;
}
