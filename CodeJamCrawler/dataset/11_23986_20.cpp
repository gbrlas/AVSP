#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


#define FOR(i,x,y) for(int i=x;i<=y;i++)
int main()
{
	freopen("input2.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);

	FOR(tests,1,t)
	{
		int N;
		scanf("%d",&N);
		printf("Case #%d:\n",tests);
		double WP[109],OWP[109],OOWP[109],CNT[109];
		FOR(j,1,N)
			WP[j]=OWP[j]=OOWP[j]=CNT[j]=0;
		double sum=0;
		string tmp[109];
		FOR(i,1,N)
		{
			int cnt=0;
			int cntwin=0;
			
			cin>>tmp[i];

			FOR(j,1,N)
			{				
				if (tmp[i][j-1]!='.')
					cnt++;
				if (tmp[i][j-1]=='1')
					cntwin++;
			}
			CNT[i]=cnt;
			WP[i]=double(cntwin)/double(cnt);
			sum+=WP[i];
		}	

		FOR(i,1,N)
		{
			FOR(j,1,N)
			{
				if (tmp[i][j-1]=='1')
				{
					OWP[i]+=((WP[j]*CNT[j])/(CNT[i]*(CNT[j]-1)));
				}
				if (tmp[i][j-1]=='0')
				{
					OWP[i]+=((WP[j]*CNT[j]-1)/(CNT[i]*(CNT[j]-1)));
				}
			}
			//printf("%lf\n",OWP[i]);

		}
		FOR(i,1,N)
		{
			double sum=0;
			FOR(j,1,N)
				if(tmp[i][j-1]!='.')
					sum+=OWP[j];
			OOWP[i]=(sum)/double(CNT[i]);
			//printf("%lf\n",OOWP[i]);
		}
		FOR(i,1,N)
			printf("%.7lf\n",0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i]);


	}
}


/*
1
4
.11.
0.00
01.1
.10.
*/