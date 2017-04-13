#include<stdio.h>
struct node
{
	node *next[26];
}z[100000];
int dfs(char *s,node *a)
{
	if(!a)return 0;
	if(!*s)return 1;
	if(*s!='(')return dfs(s+1,a->next[*s-'a']);
	int r=0;
	char *t=s+1;
	while(*t!=')')t++;
	t++;
	for(s++;*s!=')';s++)r+=dfs(t,a->next[*s-'a']);
	return r;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int l,d,n;
	scanf("%d%d%d",&l,&d,&n);
	int m=1;
	while(d--)
	{
		char s[16];
		scanf("%s",s);
		node *a=z;
		for(int i=0;s[i];i++)
		{
			if(!a->next[s[i]-'a'])a->next[s[i]-'a']=z+(m++);
			a=a->next[s[i]-'a'];
		}
	}
	for(int x=1;x<=n;x++)
	{
		static char s[421];
		scanf("%s",s);
		printf("Case #%d: %d\n",x,dfs(s,z));
	}
}
