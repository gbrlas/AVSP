#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int c;
	for(c=1;c<=t;c++)
	{
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		int res[n][m];
		int i,j;
		for(i=0;i<n;i++) for(j=0;j<m;j++) 
		{
			cin>>arr[i][j];
			if(arr[i][j]==2) res[i][j]=1;
			else res[i][j]=0;
		}
		
		int flag;
		//rowwise
		for(i=0;i<n;i++) 
		{
		flag=0;
		for(j=0;j<m;j++) if(arr[i][j]==2) flag=1;
		if(flag==0)
		for(j=0;j<m;j++) if(arr[i][j]==1) res[i][j]=1;
		}
		
		//colwise
		for(j=0;j<m;j++) 
		{
		flag=0;
		for(i=0;i<n;i++) if(arr[i][j]==2) flag=1;
		if(flag==0)
		for(i=0;i<n;i++) if(arr[i][j]==1) res[i][j]=1;
		}
		
		int check=1;
		//check the res matrix
		for(i=0;i<n;i++) for(j=0;j<m;j++) if(res[i][j]==0) {check=0;break;} 
		if(check==1) cout<<"Case #"<<c<<": YES"<<endl;
		else cout<<"Case #"<<c<<": NO"<<endl;
		
	}
}
