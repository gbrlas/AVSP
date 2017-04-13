#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#define mod 1000000009
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,i,j,k,n;
	double c,f,x,ans,curr_ans;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		
		cin>>c>>f>>x;
		//cout<<t<<" ";
		curr_ans=x/2;
		for(i=1;;i++)
		{
			ans=0;
			for(j=0;j<i;j++)
			{
				ans=ans+(c)/(2+j*f);
			}
			ans=ans+(x)/(2+j*f);
			if(ans<=curr_ans)
			{
				curr_ans=ans;
			}
			else
			{
				break;
			}
		}
		printf("Case #%d: %.7lf\n",k,curr_ans);
		
	}
	return 0;
}

