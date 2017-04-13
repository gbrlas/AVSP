#include<iostream>
#include<algorithm>
using namespace std;
int N;
int C[1005];
int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-small-attempt0.out","w",stdout);
	int T,i,Case=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int isequal=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&C[i]);
			isequal^=C[i];
		}
		if(isequal)
		{
			printf("Case #%d: NO\n",++Case);
			continue;
		}
		sort(C+1,C+1+N);
		int sum=0;
		for(i=2;i<=N;i++)
			sum+=C[i];
		printf("Case #%d: %d\n",++Case,sum);
	}
	return 0;
}