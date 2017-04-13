#include <stdio.h>
#include <set>
using namespace std;

typedef unsigned long UL;

UL T, TC=1;

UL N, x, s;
UL a[1005];//, sean[16], patrick[16];
UL smallest;

int main ()
{
	UL c, i;
    for (scanf ("%lu", &T); TC <= T; TC++)
    {
		scanf("%lu", &N);
		memset(a, 0, sizeof(a));
		x = s = 0;
		smallest = -1;
		for(i=0; i<N; i++)		
		{
			scanf("%lu",a+i);
			x ^= a[i];
			s += a[i];
			smallest = min(smallest, a[i]);
		}

		printf ("Case #%lu: ", TC);
		if(x == 0)
			printf("%lu\n", s - smallest);
		else
			printf("NO\n");
    }

    return 0;
}
