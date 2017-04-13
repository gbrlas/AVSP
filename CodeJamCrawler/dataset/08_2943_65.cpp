#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100100;
int prev[MAXN];
vector<int> ans;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t,it;
	scanf("%d",&t);
	for (it=0;it<t;it++)
	{		
		int n;
		scanf("%d",&n);
		prev[n]=n;
		int x=n;
		for (int i=n;i>=2;i--)
		{
			for (int j=0;j<i-1;j++)
				x=prev[x];
			prev[i-1]=prev[x];
			prev[x]=i-1;
			x=prev[x];
		}
		ans.clear();
		for (x=prev[1];x!=1;x=prev[x])
			ans.push_back(x);
		ans.push_back(1);
		reverse(ans.begin(),ans.end());
		printf("Case #%d: ",it+1);
		int k;
		scanf("%d",&k);
		for (int i=0;i<k;i++)
		{
			int a;
			scanf("%d",&a);
			printf("%d",ans[a-1]);
			if (i!=k-1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
