#include <cstdio>
#include <cstring>

int k,ans,perm[100];
char s[100000],ns[100000];
bool used[100];

void search(int d)
{
	if(d==k)
	{
		for(int i=0;s[i]!='\0';++i) ns[i/k*k+perm[i%k]-1]=s[i];
		int r=1;
		for(int i=1;s[i]!='\0';++i)
			if(ns[i]!=ns[i-1])
				++r;
		ans<?=r;
	}
	else
		for(int i=1;i<=k;++i)
			if(!used[i])
			{
				used[i]=true;
				perm[d]=i;
				search(d+1);
				used[i]=false;
			}
}

int main()
{
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		memset(used,false,sizeof(used));
		scanf("%d\n%s",&k,s);
		ans=10000000;
		search(0);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}

