#include <iostream>

using namespace std;

int lenlen,len[111],num,n,sum;
char exp[1111],word[111][111];
int path[111];

int d[26];

int eval()
{
	int cur=1,r=0;
	for(int i=0;i<lenlen;++i)
		if(exp[i]=='+')
		{
			r=(r+cur)%10009;
			cur=1;
		}
		else
		{
			cur=cur*d[exp[i]-'a']%10009;
		}
	r=(r+cur)%10009;
	return r;
}

void dfs(int id)
{
	if(id==num)
	{
		sum=(sum+eval())%10009;
	}
	else
	{
		for(int i=0;i<n;++i)
		{
			path[id]=i;
			for(int j=0;j<len[i];++j) ++d[word[i][j]-'a'];
			dfs(id+1);
			for(int j=0;j<len[i];++j) --d[word[i][j]-'a'];
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int zz;
	scanf("%d",&zz);
	for(int z=1;z<=zz;++z)
	{
		int K;
		scanf("%s %d\n%d",exp,&K,&n);
		lenlen=strlen(exp);
		for(int i=0;i<n;++i)
		{
			scanf("\n%s",word[i]);
			len[i]=strlen(word[i]);
		}
		printf("Case #%d:",z);
		for(num=1;num<=K;++num)
		{
			sum=0;
			for(int i=0;i<26;++i) d[i]=0;
			dfs(0);
			printf(" %d",sum);
		}
		putchar('\n');
	}
	return 0;
}

