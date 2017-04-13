#include<stdio.h>
#include<algorithm>
using namespace std;
char s[50001];
int p[16];
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int N;
	scanf("%d",&N);
	for(int t=1;t<=N;t++)
	{
		int k;
		scanf("%d%s",&k,s);
		for(int i=0;i<k;i++)p[i]=i;
		int x=1;
		for(int i=1;s[i];i++)if(s[i]!=s[i-1])x++;
		while(next_permutation(p,p+k))
		{
			int y=1;
			for(int i=1;s[i];i++)if(s[i/k*k+p[i%k]]!=s[(i-1)/k*k+p[(i-1)%k]])y++;
			if(y<x)x=y;
		}
		printf("Case #%d: %d\n",t,x);
	}
}
