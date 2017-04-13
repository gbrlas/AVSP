#include <fstream>
//freopen("a.txt","r",stdin);

#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;


int main()
{
	//freopen("A-small-practice.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	
	freopen("b.txt","w",stdout);
	
	int tt,z,l,t,n,c,i,j,k;
	double mi,sum;
	int s[1100],st[1100],sn;
	double bet,aft,sumt,start,dis,trat;
	scanf("%d",&tt);
	for(z=1;z<=tt;z++)
	{
		scanf("%d%d%d%d",&l,&t,&n,&c);
		for(i=0;i<c;i++)
		{
			scanf("%d",&st[i]);
		}
		for(i=0;i<n;)
		{
			for(j=0;j<c;j++,i++)
			{
				s[i]=st[j];
			}
		}
		
		//l=0;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=s[i];
		}
		mi=sum/0.5;
		
		//l=1;
		if(l>0)
		{
			for(i=0;i<n;i++)
			{
				sum=0;
				sumt=0;
				for(k=0;k<i;k++)
				{
					sumt+=s[k];
				}
				sum=sumt/0.5;
				
				double waitt=t-sum;
				if(waitt<0)
				{
					waitt=0;
				}
				dis=0.5*waitt;
				if(dis>=s[i])
				{
					sum+=s[i]/0.5;
				}
				else
				{
					sum+=waitt;
					sum+=(s[i]-dis);
				}
			
				
				//l=1;last
				sumt=0;
				for(k=i+1;k<n;k++)
				{
					sumt+=s[k];
				}
				sum+=sumt/0.5;
				
				if(sum<mi)
				{
					mi=sum;
				}
			}
		}
		
		//l=2;
		if(l==2)
		{
			for(i=0;i<n-1;i++)
			{
				for(j=i+1;j<n;j++)
				{
					sum=0;
					sumt=0;
					for(k=0;k<i;k++)
					{
						sumt+=s[k];
					}
					sum=sumt/0.5;
					
					double waitt=t-sum;
					if(waitt<0)
					{
						waitt=0;
					}
					dis=0.5*waitt;
					if(dis>=s[i])
					{
						sum+=s[i]/0.5;
					}
					else
					{
						sum+=waitt;
						sum+=(s[i]-dis);
					}
					
					
					//l=2;2
					sumt=0;
					for(k=i+1;k<j;k++)
					{
						sumt+=s[k];
					}
					waitt=sumt/0.5;
					sum+=waitt;
					
					waitt=t-sum;
					if(waitt<0)
					{
						waitt=0;
					}
					dis=0.5*waitt;
					if(dis>=s[j])
					{
						sum+=s[j]/0.5;
					}
					else
					{
						sum+=waitt;
						sum+=(s[j]-dis);
					}
					
					//last
					sumt=0;
					for(k=j+1;k<n;k++)
					{
						sumt+=s[k];
					}
					sum+=sumt/0.5;
					
					if(sum<mi)
					{
						mi=sum;
					}
				}
			}
		}
		printf("Case #%d: %d\n",z,int(mi));
	}
    return 0;
}