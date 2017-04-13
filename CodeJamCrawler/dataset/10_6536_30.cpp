#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main()
{
	FILE * input = fopen("C-small.in","r");
	FILE * output = fopen("C-small.out","w");
	int t,r,k,n,head,total;
	int i,j;
	int * queen;
	int result,sum;
	fscanf(input,"%d\n",&t);
	for (i=0;i<t;i++)
	{
		result = 0;
		head = 0;		
		fscanf(input,"%d %d %d\n",&r,&k,&n);
		
		queen = (int *) malloc(n*sizeof(int));
		for (j=0;j<n-1;j++)
		{
			fscanf(input,"%d ",&queen[j]);
		}
		fscanf(input,"%d\n",&queen[n-1]);

		for (j=0;j<r;j++)
		{
			sum = 0;
			total = 0;
			while(queen[head]+sum<=k&&total<n){
				sum += queen[head];
				total++;
				if(head == n-1)
					head = 0;
				else
					head++;
			}
			result += sum;
		}
		
		fprintf(output,"Case #%d: %d\n",i+1,result);
		free(queen);
	}
	fclose(input);
	fclose(output);
}
