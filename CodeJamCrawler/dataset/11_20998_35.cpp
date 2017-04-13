#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
string table[102];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large-ans.txt","w",stdout);


	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		
		double OWP[101]={};
		double OOWP[101]={};
		int N;
		cin>>N;
		for(int j=1;j<=N;j++)
		{
			cin>>table[j];
		}
		double WPs[101];
		for(int j=1;j<=N;j++)
		{
			int win=0,total=0;
			for(int k=0;k<table[j].size();k++)
			{
				
				if(table[j][k]!='.')
					total++;
				if(table[j][k]=='1')
					win++;
			}
			WPs[j]=(win*1.0)/total;
		}
		for(int j=1;j<=N;j++)
		{
			double WP_all=0,total=0;
			for(int k=0;k<table[j].size();k++)
			{
				double WP[101]={};
				for(int jj=1;jj<=N;jj++)
				{
					if(jj==j)
						continue;
					int win=0,total=0;
					for(int kk=0;kk<table[jj].size();kk++)
					{
						if(kk+1==j)
							continue;
						if(table[jj][kk]!='.')
							total++;
						if(table[jj][kk]=='1')
							win++;
					}
					WP[jj]=(win*1.0)/total;
				}
				// cal j,del j
				if(table[j][k]!='.')
				{
					total++;
					// 
					WP_all+=WP[k+1];
				}
			}
			OWP[j]=(WP_all)/total;
		}
		for(int j=1;j<=N;j++)
		{
			double OWP_all=0,total=0;
			for(int k=0;k<table[j].size();k++)
			{
				if(table[j][k]!='.')
				{
					total++;
					OWP_all+=OWP[k+1];
				}
			}
			OOWP[j]=(OWP_all)/total;
		}
		double ans[102];
		for(int j=1;j<=N;j++)
		{
			ans[j]=0.25*WPs[j]+0.5*OWP[j]+OOWP[j]*0.25;
		}
		cout<<"Case #"<<i<<":"<<endl;
		for(int j=1;j<=N;j++)
		{
			printf("%.8lf\n",ans[j]);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}