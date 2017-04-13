#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int A[100007];
int N,M,NT,t,L,H;
int resflag,flag,ans;

int main()
{
	int i,j;
	char c;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>NT;
	for(t=1;t<=NT;t++)
	{
		cout<<"Case #"<<t<<": ";
		cin>>N>>L>>H;
		for(i=1;i<=N;i++) cin>>A[i];
		resflag = 0;
		for(ans=L;ans<=H;ans++)
		{
			flag = 0;
			for(i=1;i<=N;i++)
				if(A[i]%ans!=0 && ans%A[i]!=0)
				{
					flag = 1;
					break;
				}			
			if(flag==0)
			{
				resflag = 1;
				cout<<ans<<endl;
				break;
			}
		}
		if(resflag==0) 
		{ 
			cout<<"NO"<<endl; 
		}
	}

	return 0;
}

