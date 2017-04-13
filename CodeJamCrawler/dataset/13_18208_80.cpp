#include "stdio.h"
#include "math.h"

typedef unsigned typ;
#define FMT_STR	"%u"

int nTests;
typ s,e;

int solve(void)
{
	int i,j,cnt=0,fac=1;
	typ a,b,a2=s,mult=10;

	if(s > e)
		return 0;
	
	a = sqrt(s);
	if(a*a < s)		a++;
	a2=a*a;

	b = sqrt(e);
	if(b*b > e)		b--;
	
	//Calculate the range factor
	while(a >= mult)
	{
		mult *= 10;
		fac++;
	}

	for( ; a <= b ; ++a)
	{
		if(a >= mult)
		{
			mult *= 10;
			fac++;
		}

		// Check for palindrome base
		typ mh = mult/10;
		typ f2 = fac>>1;
		typ ah = a;
		typ al = a;
		for(i=0 ; i<f2 ; ++i)
		{
			int p = ah / mh;
			int q = al % 10;
			if(p != q)
				break;
			ah = (ah % mh) * 10;
			al = al / 10;
		}
		if(i<f2)
			continue;
			
		a2 = a*a;

		// Check for palindrome square
		mh = 10;
		f2 = 1;
		while(a2 >= mh)
		{
			mh *= 10;
			f2++;
		}
		f2 = f2>>1;
		mh /= 10;
		ah = a2;
		al = a2;
		for(i=0 ; i<f2 ; ++i)
		{
			int p = ah / mh;
			int q = a2 % 10;
			if(p != q)
				break;
			ah = (ah % mh) * 10;
			al = al / 10;
		}
		if(i>=f2)
			cnt++;
	}
		
	return cnt;
}

int main(void)
{
	int cTest,i,j;

	scanf("%d\n", &nTests);

	for(cTest=1 ; cTest<=nTests ; ++cTest)
	{
		scanf(FMT_STR" "FMT_STR"\n", &s, &e);

		i=solve();
		
		printf("Case #%d: %d\n", cTest, i);
	}
	
	return 0;
}
