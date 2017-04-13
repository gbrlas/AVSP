#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, s, task, cs=0, p, a, x, y, z;

int main(){
	freopen("B-small-attempt2.in","r",stdin);
	//freopen("b.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int cs=1; cs<=task; cs++)
	{
		scanf("%d%d%d", &n, &s, &p);
		int ret = 0;
		for (int i=0; i<n; i++)
		{
			scanf("%d", &a);
			x = a/3;
			z = a%3;
			if ( z==0 )
			{
				y = x;
			}
			else
			{
				y = x+1;
				z--;
			}

			if ( y>=p )
			{
				ret++;
				continue;
			}
			y += z;
			if ( (p-y)%2==0 )
				x -= (p-y)/2;
			else 
				x -= (p-y)/2+1;

			if ( x>=0 && p-x<=2 && s>0 )
			{
				s--;
				ret++;
			}
		}
		printf("Case #%d: %d\n", cs, ret);
	}
	return 0;
}
