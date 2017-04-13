#include<string.h>
#include<stdio.h>
//#include<algorithm>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

double WP(int,int);
double OWP(int,int);
double OOWP(int,int);
char fix[101][101];

int main()
{  	 
	int n,t,i,j;
	double rip;
	freopen("A-large.in","r",stdin);
	freopen("A-large-sol.txt","w",stdout);
	scanf("%d\n",&t);

	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		printf("Case #%d:\n",i+1);
		rip=0;
		for(j=0;j<n;j++)
		{
			scanf("%s",fix[j]);
		}
		for(j=0;j<n;j++)
		{
			rip=(0.25*WP(j,n))+(0.5*OWP(j,n))+(0.25*OOWP(j,n));
			printf("%lf\n",rip);
		}
	}
}

double WP(int j,int n)
{
	int i,tot=0,win=0;
	for(i=0;i<n;i++)
		if(fix[j][i] == '1' || fix[j][i] == '0')
		{
			tot++;
			if(fix[j][i] == '1')
				win++;
		}
//	printf("\t%lf\t",((double)(win))/((double)(tot)));
	return ((double)(win))/((double)(tot));
}

double OWP(int j,int n)
{
	int i,k,tot,win,totOps=0;
	double wp[100],sum;
	for(i=0;i<n;i++)
	{
		tot=0;
		win=0;
		wp[i]=0;
		if(i != j && (fix[i][j] == '1' || fix[i][j] == '0'))
		{
			totOps++;
			for(k=0;k<n;k++)
			{
				if((fix[i][k] == '1' || fix[i][k] == '0') && k!=j)
				{
					tot++;
					if(fix[i][k] == '1')
						win++;
				}
			}
		}
		if(tot != 0)
			wp[i] = ((double)(win))/((double)(tot));
	}
	sum=0;
	for(i=0;i<n;i++)
		sum+=wp[i];
	
	return sum/(double)(totOps);
}

double OOWP(int j,int n)
{
	double sum=0;
	int i,tot=0;
	for(i=0;i<n;i++)
		if(i!=j && (fix[i][j] == '0' || fix[i][j] == '1'))
		{
			sum+=OWP(i,n);
			tot++;
		}
	if(tot == 0)
		return 0;
	else
		return sum/(double)(tot);
}
