#include <iostream>
#include <set>
using namespace std;
int P[101][101];
int main()
{
	ios_base::sync_with_stdio(0);
	int zest;
	cin>>zest;
	int x,y;
	set <int> S;
	int tmp;
	bool czy, czywogole;
	for(int aa=1; aa<=zest; aa++)
	{
		S.clear();
		cin>>x>>y;
		for(int n=0; n<x; n++)
		{
			for(int a=0; a<y; a++)
			{
				cin>>P[n][a];
				if(S.count(P[n][a])==0)
				{
					S.insert(P[n][a]);
				}
			}
		}
		while(S.size()!=0)
		{
			tmp=*S.begin();
			S.erase(S.begin());
			for(int n=0; n<x; n++)
			{
				czy=1;
				czywogole=0;
				for(int a=0; a<y; a++)
				{
					if(P[n][a]!=-1 && P[n][a]!=tmp)
					{
						czy=0;
						break;
					}
					if(P[n][a]==tmp)
					{
						czywogole=1;
					}
				}
				if(czy==1 && czywogole==1)
				{
					for(int a=0; a<y; a++)
					{
						P[n][a]=-1;
					}
				}
			}
			for(int a=0; a<y; a++)
			{
				czy=1;
				czywogole=0;
				for(int n=0; n<x; n++)
				{
					if(P[n][a]!=-1 && P[n][a]!=tmp)
					{
						czy=0;
						break;
					}
					if(P[n][a]==tmp)
					{
						czywogole=1;
					}
				}
				if(czy==1 && czywogole==1)
				{
					for(int n=0; n<x; n++)
					{
						P[n][a]=-1;
					}
				}
			}
		}
		czy=1;
		for(int n=0; n<x; n++)
		{
			for(int a=0; a<y; a++)
			{
				
				if(P[n][a]!=-1)
				{
					czy=0;
				}
			}
		}
		cout<<"Case #"<<aa<<": ";
		if(czy)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
