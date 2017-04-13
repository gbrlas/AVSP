#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLENTH = 60

void main()
{
	FILE * input = fopen("B-small.in","r");
	FILE * output = fopen("B-small.out","w");
	int c,n,combine,t,result;
	int i,j,k,s;
	int * events,* differs;
	fscanf(input,"%d\n",&c);
	for (i=0;i<c;i++)
	{
		fscanf(input,"%d ",&n);
		events = (int *)malloc(n*sizeof(int));
		for (j=0;j<n-1;j++)
		{
			fscanf(input,"%d ",&events[j]);
		}
		fscanf(input,"%d\n",&events[j]);
		combine = (n-1)*n/2;
		differs = (int *)malloc(combine*sizeof(int));
		s = 0;
		for(j=0;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				differs[s++] = abs(events[j]-events[k]);
			}
		}
		t = gcdall(differs,combine);

		if(events[0]%t ==0)
		{
			result = 0;
		}else {
			result = t - events[0]%t;
		}
		fprintf(output,"Case #%d: %d\n",i+1,result);
		free(events);
		free(differs);
	}
	fclose(input);
	fclose(output);
}

int gcd(int a,int b)
{
	int r;
	while(b != 0)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int gcdall(int * d,int num)
{
	int i,temp;
	temp = d[0];
	for (i=1;i<num;i++)
	{
		temp = gcd(temp,d[i]);
	}
	return temp;
}