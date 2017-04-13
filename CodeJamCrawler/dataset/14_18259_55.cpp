#include<stdio.h>
int main()
{
	int test,cas=1;
	scanf("%d",&test);
	while(test--)
	{
		double c,f,x;
		double val1,val2;
		scanf("%lf %lf %lf",&c,&f,&x);
		printf("Case #%d: ",cas);
		val1 = x/2.0;
		int index=1;
		while(true)
		{
			val2 = val1-(x/(2.0+(index-1)*f))+(c/(2.0+(index-1)*f))+(x/(2.0+(index*f)));
			if( val2 > val1)
			{
				printf("%0.7lf\n",val1);
				break;
			}
			val1 = val2;
			index++;
		}
		cas++;
	}
	return 0;
}
