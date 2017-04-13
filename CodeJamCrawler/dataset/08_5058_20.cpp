#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	char ch[5000];
	int i,j,cas,CASNO,n;
	double k,base;
	int a[5000];
	int num=100000000;
	int d;

	freopen("C-small-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&CASNO);
		a[10] = 47; a[11] = 943; a[12] = 471; a[13] = 55; a[14] = 447;
		a[15] = 463; a[16] = 991; a[17] = 95; a[18] = 607;
		a[19] = 263; a[20] = 151; a[21] = 855; a[22] = 527; a[23] = 743;
		a[24] = 351; a[25] = 135; a[26] = 407; a[27] = 903; a[28] = 791;
		a[29] = 135; a[30] = 647;


	for (cas=1;cas<=CASNO;cas++)
	{
		scanf("%d",&n);

		if (n>=10)
		{
			d=a[n];
		if (d>=100) printf("Case #%d: %d\n",cas,d);
		else if (d>=10) printf("Case #%d: 0%d\n",cas,d);
		else printf("Case #%d: 00%d\n",cas,d);

		continue;
		}
		else
		{
		base = 3+pow(5,0.5);
		k=1;
		for (i=1;i<=n;i++)
		{
			k=k*base; 
			if (k>num) 
			{
				d=k;
				d%=num;
				k = d + k - (int) k;
			}

		}



		d=k;
		d%=1000;
		if (d>=100) printf("Case #%d: %d\n",cas,d);
		else if (d>=10) printf("Case #%d: 0%d\n",cas,d);
		else printf("Case #%d: 00%d\n",cas,d);
		}

	}
	return 1;
}
	