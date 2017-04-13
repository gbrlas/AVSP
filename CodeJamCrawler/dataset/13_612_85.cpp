//shivi..coding is adictive!!
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<functional>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
using namespace std;
int arr[200][200];
int row[200];
int col[200];
void work()
{
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			cin>>arr[i][j];
	
	int maxi=0,i,j;
	for(int i=0;i<N;++i)
	{
		maxi=0;
		for(int j=0;j<M;++j)
			if(arr[i][j]>maxi)maxi=arr[i][j];
		row[i]=maxi;
	}
	
	for( i=0;i<M;++i)
	{
		maxi=0;
		for(j=0;j<N;++j)
			if(arr[j][i]>maxi)maxi=arr[j][i];
		col[i]=maxi;
	}
	
	
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			if(arr[i][j]<row[i] && arr[i][j]<col[j])
			{cout<<"NO\n";return;}
		}
		
	}
	
	cout<<"YES\n";
	
			
}
int main()
{
	int t,i=1;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<i++<<": ";
		work();
	}
}
