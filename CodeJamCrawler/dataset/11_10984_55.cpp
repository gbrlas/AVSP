#include <fstream>
//freopen("a.txt","r",stdin);

#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;




int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("b.txt","w",stdout);

	int t , z , n , c[1100] , p , sora , sorb , sa , sb , j , i , it , f , ma;
	scanf("%d" , &t);
	for(z = 1; z <= t; z++)
	{
		f = 0;
		scanf("%d" , &n);
		for(i = 0; i < n; i++)
		{
			scanf("%d" , &c[i]);
		}
		p = pow(double(2) , n);
		ma = -1;
		for(i = 1; i < p - 1; i++)
		{
			sora = 0;
			sorb = 0;
			sa = 0;
			sb = 0;
			it = i;
			for(j = 0; j < n; j++)
			{
				if(it % 2 == 0)
				{
					sora ^= c[j];
					sa += c[j];
				}
				else
				{
					sorb ^= c[j];
					sb += c[j];
				}
				it = it >> 1;
			}
			if(sora == sorb)
			{
				f = 1;
				if(sa > ma)
				{
					ma = sa;
				}
				if(sb > ma)
				{
					ma = sb;
				}
			}
		}
		if(f == 0)
		{
			printf("Case #%d: NO\n" , z);
		}
		else
		{
			printf("Case #%d: %d\n" , z , ma);
		}
	}
    return 0;
}