#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("ansD.txt","w",stdout);

	int T,i;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		int N;cin>>N;
		int ans=0;
		for(int j=1;j<=N;j++)
		{
			int tem;
			cin>>tem;
			if(tem!=j)
				ans++;
		}
		double final=ans;
		cout<<"Case #"<<i<<": ";
		cout<<fixed<<setprecision(8)<<final<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}