#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int a[5][5],b[5][5],first,second,t,i,j,temp,flag[17],count,test;
	cin>>test;
	for(t=1;t<=test;t++)
	{
		memset(flag,0,sizeof flag);
		count=0;
		cin>>first;
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
			{
				cin>>a[i][j];
			}
		}
		for(j=1;j<=4;j++)
		{
			flag[a[first][j]]=1;
		}
		cin>>second;
		for(i=1;i<=4;i++)
		{
			for(j=1;j<=4;j++)
			{
				cin>>b[i][j];
			}
		}
		for(j=1;j<=4;j++)
		{
			if(flag[b[second][j]]==1)
			{
				temp=b[second][j];
				count++;
			}
				
		}
		if(count==1)
		{
			cout<<"Case #"<<t<<": "<<temp<<endl;
		}
		else if(count>1)
		{
			cout<<"Case #"<<t<<": "<<"Bad magician!"<<endl;
		}
		else
		{
			cout<<"Case #"<<t<<": "<<"Volunteer cheated!"<<endl;
		}
			
	}
	return 0;
}