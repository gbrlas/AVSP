#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t, N, i, j, k, T, ans1, ans2;
	double a1[1000], a2[1000];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%lf",&a1[i]);
		sort(a1,a1+N);
		for(i=0;i<N;i++)
			scanf("%lf",&a2[i]);
		sort(a2,a2+N);
		
		i=0;
		j=0;
		for(;i<N && j<N;)
		{
			if(a1[i]<a2[j])
			{
				i++;
				j++;
			}
			else
				j++;
		}
		ans2=(N-i);
		i=N-1;
		j=N-1;
		ans1=0;
		for(;i>=0 && j>=0;)
		{
			if(a1[i]<a2[j])
				j--;
			else
			{
				ans1++;
				i--;
				j--;
			}

		}
		printf("Case #%d: %d %d\n",t,ans1,ans2);
	}
	return 0;
}



