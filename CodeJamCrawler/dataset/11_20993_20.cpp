#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("ansA-large_1.txt","w",stdout);
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("ansA-small.txt","w",stdout);

	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		long long N;
		int PD,PG;
		cin>>N>>PD>>PG;
		bool ans=false;
		
		for(int j=1;j<=100&&j<=N;j++)
		{
			if((j*PD)%100==0)
			{
				ans=true;
				break;
			}
		}
		if((PD!=0&&PG==0)||(PD<100&&PG==100))
			ans=false;
		cout<<"Case #"<<i<<": ";
		if(ans)
		{
			cout<<"Possible"<<endl;
		}
		else
			cout<<"Broken"<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
