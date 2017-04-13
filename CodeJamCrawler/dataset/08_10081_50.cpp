#include<stdio.h>
#include<string.h>
void main()
{
	int n;
	int t,i,j,tt;
	int na,nb;
	char ch,cha[100];
	int go[1000][2],to[1000][2];
	int cara,carb;
	int sum=0,time;
	int re[1000],ci,k=1;
	freopen("B-large.in","r",stdin);
	freopen("test1.txt","w",stdout);
	scanf("%d",&n);
	while(k<=n)
	{
		scanf("%d",&t);
		scanf("%d%d",&na,&nb);
		ch=getchar();
		memset(go,0,sizeof(go));
		memset(to,0,sizeof(to));
		memset(re,0,sizeof(re));
		cara=0;carb=0;
		sum=0;
		for(i=0;i<na;i++)
		{
			gets(cha);
			go[i][0]=((cha[0]-'0')*10+(cha[1]-'0'))*60+(cha[3]-'0')*10+cha[4]-'0';
			to[i][0]=((cha[6]-'0')*10+(cha[7]-'0'))*60+(cha[9]-'0')*10+cha[10]-'0';
			go[i][1]=0;
			to[i][1]=0;
		}
		for(i=na;i<nb+na;i++)
		{
			gets(cha);
			go[i][0]=((cha[0]-'0')*10+(cha[1]-'0'))*60+(cha[3]-'0')*10+cha[4]-'0';
			to[i][0]=((cha[6]-'0')*10+(cha[7]-'0'))*60+(cha[9]-'0')*10+cha[10]-'0';
			go[i][1]=1;
			to[i][1]=1;
		}
		for(i=0;i<na+nb-1;i++)
		{
			for(j=i+1;j<na+nb;j++)
			{
				if(go[i][0]>go[j][0])
				{
					tt=go[i][0];go[i][0]=go[j][0];go[j][0]=tt;
					tt=to[i][0];to[i][0]=to[j][0];to[j][0]=tt;
					tt=go[i][1];go[i][1]=go[j][1];go[j][1]=tt;
					tt=to[i][1];to[i][1]=to[j][1];to[j][1]=tt;
				}
			}
		}
		while(1)
		{
			for(i=0;i<na+nb;i++)
			{
				if(re[i]==0)
				{
					ci=to[i][1];
					time=to[i][0]+t;
					re[i]=1;
					break;
				}
			}
			if(i==na+nb)
				break;
			if(ci==0)
				cara++;
			else
				carb++;
			for(i=0;i<na+nb;i++)
			{
				if(re[i]==0&&to[i][1]==1-ci&&go[i][0]>=time)
				{
					ci=to[i][1];
					time=to[i][0]+t;
					re[i]=1;
				}
			}
		}
		printf("Case #%d: %d %d\n",k,cara,carb);
		k++;

	}
}