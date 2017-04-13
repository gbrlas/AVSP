#include <fstream>
//freopen("a.txt","r",stdin);

#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;




int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b.txt","w",stdout);

	int z , t , c , d , n , i , j , k , fc , fd;
	char cs[40][4] , ds[30][3] , s[110];
	char e[110];
	int es , ee;
	scanf("%d" , &t);
	for(z = 1; z <= t; z++)
	{
		scanf("%d" , &c);
		for(i = 0; i < c; i++)
		{
			scanf("%s" , cs[i]);
		}
		scanf("%d" , &d);
		for(i = 0; i < d; i++)
		{
			scanf("%s" , ds[i]);
		}
		scanf("%d" , &n);
		scanf("%s" , s);
		es = 0;
		ee = 0;
		for(i = 0; i < n; i++)
		{
			if(es == ee)
			{
				e[ee++] = s[i];
				continue;
			}
			fc = 0;
			e[ee++] = s[i];
			//combine
			for(j = 0; j < c; j++)
			{
				if((cs[j][0] == e[ee - 2] && cs[j][1] == e[ee - 1])
					|| (cs[j][1] == e[ee - 2] && cs[j][0] == e[ee - 1]))
				{
					e[ee - 2] = cs[j][2];
					ee--;
					fc = 1;
					break;
				}
			}
			if(fc == 1)
			{
				continue;
			}
			//dispose
			fd = 0;
			for(j = 0; j < d; j++)
			{
				if(e[ee - 1] == ds[j][0])
				{
					for(k = es; k < ee - 1; k++)
					{
						if(e[k] == ds[j][1])
						{
							ee = 0;
							es = 0;
							fd = 1;
							break;
						}
					}
					if(fd == 1)
					{
						break;
					}
				}
				else if(e[ee - 1] == ds[j][1])
				{
					for(k = es; k < ee - 1; k++)
					{
						if(e[k] == ds[j][0])
						{
							ee = 0;
							es = 0;
							fd = 1;
							break;
						}
					}
					if(fd == 1)
					{
						break;
					}
				}
			}
		}
		printf("Case #%d: [" , z);
		for(i = es ;i < ee; i++)
		{
			printf("%c" , e[i]);
			if(i != ee - 1)
			{
				printf(", ");
			}
		}
		printf("]\n");
	}
    return 0;
}