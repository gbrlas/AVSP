#include "stdio.h"

#if 1

#undef SKC
#define IN_FILE	"IO/CJ14-1B-2.in"
//#define IN_FILE	"Debug/B-small-attempt0.in"

#define P 		printf

int main(void)
{
	int t,tst;

	FILE* fin = stdin;
#ifdef SKC
	fin = fopen(IN_FILE,"r");
	if(fin == NULL)
	{
		printf("Cannot Open file %s\n", IN_FILE);
		return 0;
	}
#endif

	fscanf(fin, "%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		int i,j,res=0, a,b,k;

		fscanf(fin,"%d %d %d", &a, &b, &k);
		P("Case #%d: ", t);

		if(a<=k && b<=k)
		{
			P("%d\n", a*b);
			continue;
		}
		if(a<b)
		{
			int aa = a;
			a = b;
			b = aa;
		}

		int kk = k;
		if(k>b)
			kk = b;
		else
			res = (b-k)*k;
		res += a*kk;
		for(i=k ; i<a ; ++i)
		{
			for(j=k ; j<b ; ++j)
			{
				if((i&j) < k)
					res++;
			}
		}

		P("%d\n",res);
	}

#ifdef SKC
	fclose(fin);
#endif

	return 0;
}

#endif
