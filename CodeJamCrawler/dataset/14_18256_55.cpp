#include<stdio.h>
int main()
{
	int test,cas=1;
	scanf("%d",&test);
	while(test--)
	{
		printf("Case #%d: ",cas);
		double c,f,x;
		double val1,val2;
		scanf("%lf %lf %lf",&c,&f,&x);
		val1 = x/2.0;
		int index=1;
		while(true)
		{
			double temp = 0.0;
			for(int i=0; i<index;i++)
				temp += c/(2.0+(i*f));
			temp += x/(2.0+(index*f));
			val2 = temp;
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
