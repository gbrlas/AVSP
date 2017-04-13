#include <iostream>
#include <algorithm>
using namespace std;

struct walkway
{
	int len,w;
	bool operator<(const walkway& o) const
	{
		return w<o.w;
	}
} ww[1000+5];

int main()
{
	int c,i,j,k,walk;
	double at,t,sy;
	int x,s,r,n;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin>>c;
	for (k=1;k<=c;k++)
	{
		cin>>x>>s>>r>>t>>n;
		walk=0;
		for (j=0;j<n;j++)
		{
			int b,e;
			cin>>b>>e>>ww[j].w;
			ww[j].len=e-b;
			walk+=ww[j].len;
		}
		walk=x-walk;
		sort(ww,ww+n);
		sy=t-walk/(double)r;
		if (sy<0)
		{
			sy=0;
			at=t+(walk-r*t)/(double)s;
		}
		else
		{
			at=walk/(double)r;
		}
		for (i=0;i<n;i++)
		{
			if (sy)
			{
				double ssy=sy-ww[i].len/(double)(r+ww[i].w);
				if (ssy<0)
				{
					at+=sy+(ww[i].len-(r+ww[i].w)*sy)/((double)(s+ww[i].w));
					sy=0;
				}
				else
				{
					sy=ssy;
					at+=ww[i].len/((double)(r+ww[i].w));
				}
			}
			else
			{
				at+=ww[i].len/((double)(s+ww[i].w));
			}
		}
		printf("Case #%d: %lf\n",k,at);
	}
	return 0;
}