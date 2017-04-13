#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,a[50][50],mi;
int check(int now,int row)
{
	int i,j;
	for (i=row+1;i<n;i++)
	{
		if (a[now][i]==1)return 0;
	}
	return 1;
}
void swap(int r1,int r2)
{
	int tmp,i;
	for (i=0;i<n;i++)
	{
		tmp=a[r1][i];
		a[r1][i]=a[r2][i];
		a[r2][i]=tmp;
	}
}
char s[50][50];
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k;
	int cas,cc=0,ans;
	scanf("%d",&cas);
	while (cas--)
	{
		ans=0;
		scanf("%d",&n);
		mi=INT_MAX;
		for (i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			for (j=0;j<n;j++)
			{
				a[i][j]=s[i][j]-'0';
			}
		}
		for (i=0;i<n;i++)
		{
			for (j=i;j<n;j++)
			{
				if (check(j,i))
				{
					ans+=j-i;
					for (k=j;k>i;k--)
					{
						swap(k,k-1);
					}
					break;
				}
			}
		}
		printf("Case #%d: %d\n",++cc,ans);
	}
}
	
