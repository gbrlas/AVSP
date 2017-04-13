#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE * input = fopen("A-small.in","r");
	FILE * output = fopen("A-small.out","w");
	int n,k,t,i,j,m,s;
	char * state[2];
	int * snapper;
	int power;
	int flag;
	int result;
	state[0] = "OFF";
	state[1] = "ON";
	fscanf(input,"%d\n",&t);
	for (i=0;i<t;i++)
	{
		fscanf(input,"%d %d",&n,&k);
		power = 0;
		flag = 0;
		result = 0;
		snapper = (int *)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		{
			snapper[j] = 0;
		}
		//TODO::
		for(m = 0;m<k;m++)
		{
			flag = 0;
			for (s = 0;s<=power;s++)
			{
				snapper[s] = (snapper[s]==0)?1:0;

			}
			for (s = 0;s <n;s++)
			{
				if(snapper[s] ==0)
				{
					power = s;
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				power = n-1;
			}
		}
		if(snapper[n-1]&&(power==n-1))
		{
			result = 1;
		}
		fprintf(output,"Case #%d: %s\n",i+1,state[result]);
		free(snapper);
	}
	fclose(input);
	fclose(output);
}