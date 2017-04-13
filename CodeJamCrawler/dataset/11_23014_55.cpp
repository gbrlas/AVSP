#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX 20

int arr[MAX];
int c[MAX];
int n;
int result;

void back(int cnt)
{
	if( cnt == n )
	{
		int x1,x2;
		int s1,s2;
		x1=x2=0;
		s1=s2=0;
		int cc;
		cc=0;
		for(int i=0;i<n;i++)
		{
			cc+=c[i];
			if( c[i] == 0 ) x1^=arr[i],s1+=arr[i];
			else x2^=arr[i],s2+=arr[i];
		}
		if( cc == n || cc == 0 ) return;
		if(x1 == x2 )
		{
			result=max(max(s1,s2),result);
		}
	}
	else
	{
		c[cnt]=0;
		back(cnt+1);
		c[cnt]=1;
		back(cnt+1);
		c[cnt]=0;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		result=-1;
		back(0);
		printf("Case #%d: ",t);
		if(result == -1 ) printf("NO\n");
		else printf("%d\n",result);
	}
	return 0;
}