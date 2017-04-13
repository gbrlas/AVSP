#include<stdio.h>
#include<set>
#include<algorithm>
#define tr(c,s) for(it=c.begin(),it2=s.begin();it!=c.end();)
using namespace std;
int main()
{
	freopen("D-large.in","r",stdin);
    freopen("outp.in","w",stdout);
	int t,nb;
	scanf("%d",&t);
	nb=t;
	while(t--)
	{
		int n,i,war=0,d_war=0;
		scanf("%d",&n);
		set<double> s1,s3;
		double num;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&num);
			s1.insert(num);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&num);
			s3.insert(num);
		}
		set<double> s5(s1),s6(s3);
		typeof(s1.begin()) it;
		typeof(s3.begin()) it2;
		tr(s1,s3)
		{
			if(*it2<*it)
			{
				it++;
				it2++;
				d_war++;
			}
			else
			{
				it++;
			}
		}
		typeof(s5.rbegin()) it3=s5.rbegin();
		typeof(s6.rbegin()) it4=s6.rbegin();
		
		while(it3!=s5.rend())
		{
			if((*it3)>(*it4))
			{
				war++;
				it3++;
			}
			else
			{
				it3++;
				it4++;
			}
		}
		
		printf("Case #%d: %d %d\n",nb-t,d_war,war);
	}
	
return 0;
}
