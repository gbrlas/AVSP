#include <fstream>
//freopen("a.txt","r",stdin);

#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;




int main()
{
	freopen("A-large.in","r",stdin);
	freopen("b.txt","w",stdout);

	int z , t , n , i , to , tb , po , pb , ans , pot , pbt , doo , db;
	char r[110];
	int p[110];
	scanf("%d" , &t);
	for(z = 1; z <= t; z++)
	{
		ans = 0;
		scanf("%d" , &n);
		for(i = 0; i < n; i++)
		{
			scanf("%c" , &r[i]);
			if(r[i] == ' ')
			{
				scanf("%c" , &r[i]);
			}
			scanf("%d" , &p[i]);
		}
		pot = 0;
		pbt = 0;
		po = 1;
		pb = 1;
		for(i = 0; i < n; i++)
		{
			if(r[i] == 'O')
			{
				doo = abs(p[i] - po) + 1;
				to = pot + doo;
				if(to > ans)
				{
					ans = to;
				}
				else
				{
					ans = ans + 1;
				}
				pot = ans;
				po = p[i];
			}
			else
			{
				db = abs(p[i] - pb) + 1;
				tb = pbt + db;
				if(tb > ans)
				{
					ans = tb;
				}
				else
				{
					ans = ans + 1;
				}
				pbt = ans;
				pb = p[i];
			}
		}
		printf("Case #%d: %d\n" , z , ans);
	}
    return 0;
}