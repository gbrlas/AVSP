#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
const double exp=0.0000000001;
using namespace std;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("gcjbl.txt","w",stdout);
	double c,f,x,sum,temp,ans;
	int ncases;
	cin>>ncases;
	for(int nc=1;nc<=ncases;nc++)
	{
		ans=0;
		sum=0;
		temp=2;
		cin>>c>>f>>x;
		int i;
		for(i=0;;i++)
		{
			if(x/(temp+(i+1)*f) - (x-c)/(temp+i*f) >= exp)
			{
				//cout<<"i: "<<i<<endl;
				break;
			}
		}
		for(int j=0;j<i;j++)
		{
			ans += c/(temp+f*j);
		}
		if(i>0)
			ans += x/(temp+i*f);
		else
			ans = x/temp;
		printf("Case #%d: %.7lf\n",nc,ans);
	}
}
