#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

char str[51000];
char temp[51000];
int perm[20];
int k;
int solve()
{
	int l = strlen(str);
	for (int i=0;i<l;i+=k)
	{
		for (int j=0;j<k;j++)
			temp[i+j]=str[i+perm[j]];
	}
	temp[l]=0;
	int res=0;
	for (int i=1;i<=l;i++)
		if (temp[i]!=temp[i-1])
			res++;
	return res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t,it;
	scanf("%d",&t);
	for (it=0;it<t;it++)
	{		
		scanf("%d",&k);
		scanf("%s",str);
		for (int i=0;i<k;i++)
			perm[i]=i;
		int ans=1000000;
		do
		{
			int t = solve();
			if (t<ans)
				ans=t;
		}
		while(next_permutation(perm,perm+k));

		printf("Case #%d: %d\n",it+1,ans);
	}
	return 0;
}
