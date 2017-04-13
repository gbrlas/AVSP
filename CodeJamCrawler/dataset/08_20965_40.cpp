#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define EPS 1e-7

int t,T;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("1.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		int a,b,s;
		int x1,y1,x2,y2;
		scanf("%d%d%d",&a,&b,&s);
		bool ok=true;
		printf("Case #%d: ",t);
/*		for (x1=0;x1<=a && ok;x1++)
			for (y1=0;y1<=b && ok;y1++)
				for (x2=x1;x2<=a && ok;x2++)
					for (y2=0;y2<=b && ok;y2++)
					{
						double x=sqrt(x1*x1+y1*y1),y=sqrt(x2*x2+y2*y2),z=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
						double r=sqrt((x+y+z)*(x+y-z)*(x-y+z)*(y+z-x))/2;
						if (int(r+EPS)==s)
						{
							ok=false;
							printf("%d %d %d %d %d %d\n",0,0,x1,y1,x2,y2);
						}
					}	*/
		if (s>a*b) printf("IMPOSSIBLE\n");
		else
		{
			int c=(s-1)/a+1;
			int num=c*a-s;
			printf("%d %d %d %d %d %d\n",0,0,a,1,num,c);
/*			double x=sqrt(a*a+1),y=sqrt(num*num+c*c),z=sqrt((num-a)*(num-a)+(c-1)*(c-1));
			double r=sqrt((x+y+z)*(x+y-z)*(x-y+z)*(y+z-x))/2;
			if (int(r+EPS)==s)
			{
				ok=false;
			}
	*/		
		}
	}

	return 0;
}