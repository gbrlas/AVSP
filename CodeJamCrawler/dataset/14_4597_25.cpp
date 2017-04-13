#include<stdio.h>
#define FOR(a,b,c) for(a = b;a < c;a++)
#define REP(a,b) FOR(a,0,b)

int main()
{
	int t, t1;
	double c, f, x, prod, sum, min;
	scanf("%d", &t);
	REP(t1,t)
	{
		scanf("%lf %lf %lf", &c, &f, &x);
		prod = 2;
		sum = 0;
		while((c / prod) + (x / (prod + f)) < (x / prod))
		{
			//printf("%20.20lf ", c / prod);
			sum += c / prod;
			prod += f;
			//while((x / prod) > (c / prod) + (x / (prod + f))
		}
		//printf(" -> %20.20lf\n", x / prod);
		sum += x / prod;
		printf("Case #%d: %.7lf\n", t1 + 1, sum);
	}
}