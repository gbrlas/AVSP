#include<stdio.h>
#include<set>
#include<algorithm>
#define tr(c,s) for(it=c.begin(),it2=s.begin();it!=c.end();)
using namespace std;
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
    freopen("outp.in","w",stdout);
	int t,nb;
	scanf("%d",&t);
	nb=t;
	while(t--)
	{
		int n,i,war=0,d_war=0;
		scanf("%d",&n);
		set<double> s1,s3,s4,s5,s6;
		double num;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&num);
			s1.insert(num);
			s5.insert(-1*num);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&num);
			s3.insert(num);
			s4.insert(-1*num);
			s6.insert(-1*num);
		}
		typeof(s1.begin()) it;
		typeof(s3.begin()) it2;
		typeof(s1.begin()) save1;
		typeof(s3.begin()) save2;
		tr(s1,s3)
		{
			if(*it2<*it)
			{
				save1=it;
				save2=it2;
				it++;
				it2++;
				s1.erase(save1);
				s3.erase(save2);
				s4.erase(-1*(*save2));
				d_war++;
			}
			else
			{
				save1=it;
				it++;
				s1.erase(save1);
				s3.erase((*s4.begin())*-1);
				s4.erase(s4.begin());
			}
		}
		
		it=s5.begin();
		it2=s6.begin();
		while(it!=s5.end())
		{
			if((-1*(*it))>(-1*(*it2)))
			{
				war++;
				save1=it;
				save2=s6.end();
				save2--;
				it++;
				s5.erase(save1);
				s6.erase(save2);
			}
			else
			{
				it2++;
				it++;
			}
		}
		
		printf("Case #%d: %d %d\n",nb-t,d_war,war);
	}
	
return 0;
}
