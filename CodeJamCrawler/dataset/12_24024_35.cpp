#include<stdio.h>
#include<math.h>
void main()
{
	int runs=0;
	scanf("%d",&runs);
	int* result = malloc(runs*sizeof(int));
	int tempr=runs;
	while(runs>0)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		int numd =0;
		while(A>=pow(10,numd))
			numd++;
		//printf("%d\n",numd);	
		int i=0;
		int j = 1;
		int mod = 0;
		int count = 0;
		int rem = 0;
		if(numd==1)
			count= 0;
		else
		{	
			for(i=A;i<=B;i++)
			{
				j=1;
				while(j<numd)
				{
					mod = i%(int)pow(10,j);
					//printf("\n%d %d\n",mod%(int)pow(10,j-1),B%(int)pow(10,numd-1));
					//if(mod/(int)pow(10,j-1)==0)
					//	break;
				//	if(mod/(int)pow(10,j-1)>B/(int)pow(10,numd-1))
					//	break;
					rem = i/pow(10,j);
					
					int newnum = mod*pow(10,numd-j)+rem;
					//printf("%d %d %d %d\n",mod,rem,newnum,i);
					if(newnum<=B&&newnum>=A&&newnum>i)
					{
						
						count++;
					}
					j++;
				}
			}
		}
		result[tempr-runs] = count;
		runs--;
	}
	int i=0;
	for(i=0;i<tempr;i++)
	{
		printf("Case #%d: %d\n",i+1,result[i]);
	}
}
