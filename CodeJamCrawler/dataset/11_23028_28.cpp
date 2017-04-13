#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>>st;

int GCD(int a,int b)
{
	if( b==0 ) return a;
	return GCD(b,a%b);
}

int main()
{
	int T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int n,m,l;
		int G=1;

		int arr[10001];
		
		scanf("%d %d %d",&n,&m,&l);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}

		sort(arr,arr+n);

		int result=-1;
		for(int i=m;i<=l;i++)
		{
			int flag = 0;
			for(int j=0;j<n;j++)
			{
				if( arr[j]%i != 0 && i%arr[j] != 0 )
				{
					flag=1;
					break;
				}
			}
			if( flag == 0 )
			{
				result=i;
				break;
			}
		}
		if( result!=-1)
			printf("Case #%d: %d\n",t+1,result);
		else
			printf("Case #%d: NO\n",t+1,result);
	}
	return 0;
}