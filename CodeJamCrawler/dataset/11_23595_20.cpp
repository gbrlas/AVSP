#include<stdio.h>
int main()
{
	int t,z,win[100],los[100],i,j,n;
	double wp[100],owp[100],oowp[100];
	char s[101][101];
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			win[i]=los[i]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(s[i][j]=='1')
				{
					win[i]++;
					los[j]++;
				}
				else if(s[i][j]=='0')
				{
					los[i]++;
					win[j]++;
				}
			}
			wp[i]=win[i]*1.0/(win[i]+los[i]);
		}
		for(i=0;i<n;i++)
		{
			double sum=0;
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='1')
				{
					sum+=win[j]*1.0/(win[j]+los[j]-1);
				}
				else if(s[i][j]=='0')
				{
					sum+=(win[j]-1)*1.0/(win[j]+los[j]-1);
				}
			}
			owp[i]=sum/(win[i]+los[i]);
		}
		for(i=0;i<n;i++)
		{
			double sum=0;
			for(j=0;j<n;j++)
			{
				if(s[i][j]!='.')
				{
					sum+=owp[j];
				}
			}
			oowp[i]=sum/(win[i]+los[i]);
		}
		printf("Case #%d:\n",z);
		for(i=0;i<n;i++)
		{
			printf("%.16lf\n",wp[i]/4+owp[i]/2+oowp[i]/4);
		}
	}
	return 0;
}
