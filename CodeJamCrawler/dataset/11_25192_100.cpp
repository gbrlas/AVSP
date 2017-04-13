#include <stdio.h>
#include <memory.h>
const int maxn=200;
int o[maxn],w[maxn],i,j,k,n,m,t,no[maxn],nw[maxn];
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
		memset(o,0,sizeof(o));
		memset(w,0,sizeof(w));
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			if (getc()=='O') scanf("%d",o+i);
			else scanf("%d",w+i);
		w[n+1]=o[n+1]=n+1;
		no[n+1]=n+1;
		nw[n+1]=n+1;
		for (i=n;i>=1;--i)
		{
			if (o[i]) no[i]=i; else no[i]=no[i+1];
			if (w[i]) nw[i]=i; else nw[i]=nw[i+1];
		}
		i=1;j=1;k=1;m=0;
		while (i<=n)
		{
			m++;
			if (j==o[i]) 
			{
				if (k<w[nw[i]]) k++;
				else if (k>w[nw[i]]) k--;
				i++;
			}
			else if (k==w[i])
			{
				if (j<o[no[i]]) j++;
				else if (j>o[no[i]]) j--;
				i++;
			} else
			{
				if (k<w[nw[i]]) k++;
				else if (k>w[nw[i]]) k--;
				if (j<o[no[i]]) j++;
				else if (j>o[no[i]]) j--;
			}
		}
		printf("Case #%d: %d\n",ct,m);
	}
}