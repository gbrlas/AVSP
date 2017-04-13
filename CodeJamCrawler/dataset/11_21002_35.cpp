#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int ini[201][201];
int dif[201][201];
vector<pair<int ,int> > vec;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-ans-small.txt","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		memset(ini,0,sizeof(ini));
		memset(dif,0,sizeof(dif));
		vec.clear();
		//int pos[201];
		//int num[201];
		int C,D;
		cin>>C>>D;
		for(int j=1;j<=C;j++)
		{
			int a,b;
			cin>>a>>b;
			vec.push_back(make_pair(a,b));
		}
		sort(vec.begin(),vec.end());
		for(int j=0;j<C;j++)
		{
			for(int k=j;k<C;k++)
			{
				ini[j][k]=abs(vec[j].first-vec[k].first);
				if(vec[j].second>0&&vec[k].second>0)
				{
					int ans=0;
					for(int s=j;s<=k;s++)
					{
						ans+=vec[s].second;
					}
					dif[j][k]=(ans-1)*D;
				}
				else
					dif[j][k]=0;
			}
		}
		double ans=0;
		for(int j=0;j<C;j++)
		{
			for(int k=j;k<C;k++)
			{
				if(ans<(dif[j][k]-ini[j][k])/2.0)
					ans=(dif[j][k]-ini[j][k])/2.0;
			}
		}
		cout<<"Case #"<<i<<": ";
		printf("%.8lf\n",ans);
		
	}

	fclose(stdin);
	fclose(stdout);
}