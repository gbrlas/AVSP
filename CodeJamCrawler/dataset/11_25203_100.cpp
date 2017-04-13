#include <stdio.h>
#include <memory.h>
int a[26][26],op[26][26],t,list[205],ans[205],n,s[26];
char x,y,z;
char getc()
{
	static char i;
	while (1)
	{
		scanf("%c",&i);
		if ((i>='A')&&(i<='Z')) return i;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (int ct=1;ct<=t;++ct)
	{
		for (int i=0;i<26;i++)
			for (int j=0;j<26;j++)
				a[i][j]=op[i][j]=0;
		for (scanf("%d",&n);n;--n)
		{
			x=getc();
			y=getc();
			z=getc();
			a[x-'A'][y-'A']=z-'A';
			a[y-'A'][x-'A']=z-'A';
		}
		for (scanf("%d",&n);n;--n)
		{
			x=getc();
			y=getc();
			op[x-'A'][y-'A']=1;
			op[y-'A'][x-'A']=1;
		}
		scanf("%d",list);
		for (n=1;n<=list[0];n++) list[n]=getc()-'A';
		memset(s,0,sizeof(s));
		ans[0]=0;
		for (n=1;n<=list[0];n++)
		{
			ans[++ans[0]]=list[n];
			s[list[n]]++;
			if ((ans[0]>1)&&(a[ans[ans[0]-1]][ans[ans[0]]]!=0))
			{
				s[ans[ans[0]]]--;
				s[ans[ans[0]-1]]--;
				ans[ans[0]-1]=a[ans[ans[0]-1]][ans[ans[0]]];
				s[ans[ans[0]-1]]++;
				--ans[0];
			}
			for (int i=0;i<26;i++)
				if ((s[i])&&(op[i][ans[ans[0]]]))
				{
					ans[0]=0;
					memset(s,0,sizeof(s));
				}
		}
		printf("Case #%d: [",ct);
		for (int i=1;i<ans[0];i++) printf("%c, ",ans[i]+'A');
		if (ans[0]>0) printf("%c",ans[ans[0]]+'A');
		printf("]\n");
	}
}