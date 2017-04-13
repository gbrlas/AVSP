#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, i, j, n1;
	scanf("%d", &n);
	for(n1 = 1;n1 <= n;n1++)
	{
		int a[20]={0}, k, t, b[4], f, r;
		f = 0;

		scanf("%d", &i);
		k = (i-1)*4;
		for(j=0;j<k;j++)
		{
			scanf("%d", &t);
		}
		for(j=0;j<4;j++)
		{
			scanf("%d", &t);
			a[t] = 1;
		}
		for(j=k+4;j<16;j++)
		{
			scanf("%d", &t);
		}


		scanf("%d", &i);
		k = (i-1)*4;
		for(j=0;j<k;j++)
		{
			scanf("%d", &t);
		}
		for(j=0;j<4;j++)
		{
			scanf("%d", &t);
			if(a[t] == 1)
			{
				r = t;
				f++;
			}
		}
		for(j=k+4;j<16;j++)
		{
			scanf("%d", &t);
		}

		if(f == 1)
		{
			printf("Case #%d: %d\n", n1, r);
		}
		else if(f == 0)
		{
			printf("Case #%d: Volunteer cheated!\n", n1, r);
		}
		else
		{
			printf("Case #%d: Bad magician!\n", n1, r);
		}
	}
	return 0;
}
