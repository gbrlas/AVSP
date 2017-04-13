#include <stdio.h>

int num1[800];
int num2[800];

int main()
{
	int numtest;
	int i;
	int num;
	int j;
	int k;
	int temp;
	int sum = 0;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&numtest);

	for(i = 0; i< numtest; ++i)
	{
		sum = 0;
		scanf("%d",&num);
		for(j=0; j <num; ++j)
		{
			scanf("%d",&num1[j]);
		}

		for(j=0; j <num; ++j)
		{
			scanf("%d",&num2[j]);
		}
		for(j=0;j<num;j++)
		{
			for(k=0;k<num;++k)
			{
				if(num1[j]<num1[k])
				{
					temp = num1[j];
					num1[j] = num1[k];
					num1[k] = temp;
				}

				if(num2[j]<num2[k])
				{
					temp = num2[j];
					num2[j] = num2[k];
					num2[k] = temp;
				}
			}
		}
		for(j=0,k=num-1;j<num,k>=0;j++,k--)
		{
			sum += num1[j]*num2[k];
		}
		printf("Case #%d: %d\n",i+1,sum);
	}
	return 0;
}