#include <fstream>

#include<stdio.h>
#include <string.h>
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("b.txt","w",stdout);

	int t , z , i , j , n , k;
	char c[110][110];
	double wp[110] , owp[110] , oowp[110] , w[110] , l[110] , owpt[110];
	scanf("%d" , &t);
	for(z = 1; z <= t; z++)
	{
		scanf("%d" , &n);
		for(i = 0; i < n; i++)
		{
			w[i] = 0;
			l[i]=0;
			wp[i]=0;
			owp[i]=0;
			oowp[i]=0;
			owpt[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",c[i]);
		}
		for(i=0;i<n;i++)
		{

			for(j=0;j<n;j++)
			{
				if(c[i][j] =='0')
				{

					l[i]+=1;
				}
				else if(c[i][j]=='1')
				{
					w[i]+=1;
				}
			}
			wp[i] = w[i]/(w[i]+l[i]);
		}

		double op;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				owpt[j] = 0;
			}
			op=0;
			for(j=0;j<n;j++)
			{
				if(c[i][j]!='.')
				{
					for(k=0;k<n;k++)
					{
						w[k]=0;
						l[k]=0;
					}
					op+=1;
					for(k=0;k<n;k++)
					{
						if(k!=i)
						{
							if(c[j][k]=='1')
							{
								w[j]+=1;
							}
							else if(c[j][k]=='0')
							{
								l[j]+=1;
							}
						}
					}
					owpt[j]=w[j]/(w[j]+l[j]);
				}
			}
			for(j=0;j<n;j++)
			{
				owp[i]+=owpt[j];
			}
			owp[i]=owp[i]/op;
		}
		for(i=0;i<n;i++)
		{
			op=0;
			for(j=0;j<n;j++)
			{
				if(c[i][j]!='.')
				{
					op+=1;
					oowp[i]+=owp[j];
				}
			}
			oowp[i] = oowp[i]/op;
		}

		printf("Case #%d:\n",z);
		for(i=0;i<n;i++)
		{
			printf("%lf\n",0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
		}
	}

	return 0;
}
