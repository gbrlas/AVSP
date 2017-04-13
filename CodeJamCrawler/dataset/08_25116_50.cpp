#include<stdio.h>
#include<string.h>
int T;
int SetA[109],SetB[109],AriA[109],AriB[109];
bool g[209][209]={0};
int NA,NB;
bool v[209];
void dfs(int x)
{
	v[x]=1;
	for(int i=0;i<NA+NB;i++)
	{
		if(!v[i]&&g[x][i])
		{
			g[x][i]=0;
			dfs(i);
			break;
		}
	}
}
bool vis()
{
	int i;
	for(i=0;i<NA+NB;i++)
		if(!v[i])return 0;
	return 1;
}
int getroot(int x)
{
	for(int i=0;i<NA+NB;i++)
		if(!v[i]&&g[i][x])
			return getroot(i);
	return x;
}
int main()
{
	int pk,k;
/*	freopen("B-small-attempt2.in.txt","r",stdin);
	freopen("B-small.out.txt","w",stdout);*/
	scanf("%d",&pk);
	for(k=1;k<=pk;k++)
	{
		memset(g,0,sizeof g);
		memset(v,0,sizeof v);
		scanf("%d",&T);
		scanf("%d %d",&NA,&NB);
		int i,j;
		for(i=0;i<NA;i++)
		{
			int HH,MM;
			scanf("%d:%d",&HH,&MM);
			SetA[i]=HH*60+MM;
			scanf("%d:%d",&HH,&MM);
			AriA[i]=HH*60+MM;
		}
		for(i=0;i<NB;i++)
		{
			int HH,MM;
			scanf("%d:%d",&HH,&MM);
			SetB[i]=HH*60+MM;
			scanf("%d:%d",&HH,&MM);
			AriB[i]=HH*60+MM;
		}
		for(i=0;i<NA;i++)
			for(j=0;j<NB;j++)
			{
				if(AriA[i]+T<=SetB[j])g[i][j+NA]=1;
				if(AriB[j]+T<=SetA[i])g[j+NA][i]=1;
			}
		int CA=0,CB=0;
		while(!vis())
		{	
			for(i=0;i<NA+NB;i++)
			{
				if(!v[i])
				{
					int x=getroot(i);
					dfs(x);
					if(x<NA)CA++;
					else CB++;
				}
			}
		}
		/*while(!vis())
		{
		
			for(i=0;i<NA;i++)
			{
				for(j=0;j<NB;j++)
					if(g[j+NA][i])break;
				if(j>=NB&&!v[i])
				{
					dfs(i);
					CA++;
				}
			}
			for(j=0;j<NB;j++)
			{
				for(i=0;i<NA;i++)
					if(g[i][j+NA])break;
				if(i>=NA&&!v[j+NA])
				{
					dfs(j+NA);
					CB++;
				}
			}
		}*/
		printf("Case #%d: %d %d\n",k,CA,CB);
	}
	return 0;
}