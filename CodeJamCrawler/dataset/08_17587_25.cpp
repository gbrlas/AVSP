#include <cstdio>
#include <cstring>

int a,b,c,d,e,f;

bool solve(int n,int m,int area)
{
	a=b=0;
	for(c=0;c<=n;++c)
		for(d=0;d<=m;++d)
			for(e=-n;e<=n;++e)
				for(f=-m;f<=m;++f)
				{
					if(c==0&&d==1&&e==1)
					{
						c=0;
					}
					int t=e<?f;
					if(t<0&&!(a-t<=n&&b-t<=m&&c-t<=n&&d-t<=m&&e-t<=n&&f-t<=m)) continue;
					int ta=e*d-f*c;
					if(ta<0) ta=-ta;
					if(area==ta)
					{
						if(t<0)
						{
							a-=t;
							b-=t;
							c-=t;
							d-=t;
							e-=t;
							f-=t;
						}
						return true;
					}
				}
	return false;
}

int main()
{
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	int T,n,m,area;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d %d",&n,&m,&area);
		if(solve(n,m,area)) printf("Case #%d: %d %d %d %d %d %d\n",t,a,b,c,d,e,f);
		else printf("Case #%d: IMPOSSIBLE\n",t);
	}
	return 0;
}

