/*
I Will Win Not Immediately But Definitely.. -Aniruddha Sharma
*/
 
// Name:- Aniruddha Sharma
 
// Problem:- Problem A. Magic Trick

// Link:- https://code.google.com/codejam/contest/2974486/dashboard
 
// Site:- Google CodeJam
 
#include<iostream>
#include<map>
#include<vector>
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
int main()
{
	int t,i,j,k,num,arr[4][4],brr[4][4];
	cin>>t;
	for(i=1;i<=t;i++)
	{
		int count[17]={0};
		cin>>num;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				cin>>arr[j][k];
			}
		}
		for(k=0;k<4;k++)
		{
			count[arr[num-1][k]]++;
		}
		
		cin>>num;
		//cout<<num<<endl;
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				cin>>brr[j][k];
			}
		}
		int flag=0,ans;
		for(k=0;k<4;k++)
		{
			if(count[brr[num-1][k]]==1)
			{
				ans=brr[num-1][k];
				flag++;
			}
		}
		
		if(flag==1)
		{
			cout<<"Case #"<<i<<": "<<ans<<endl;
		}
		else if(flag>1)
		{
			cout<<"Case #"<<i<<": Bad magician!\n";
		}
		else
		{
			cout<<"Case #"<<i<<": Volunteer cheated!\n";
		}
	}
	return(0);
}