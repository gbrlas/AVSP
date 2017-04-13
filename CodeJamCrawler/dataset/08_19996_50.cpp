#include <stdio.h>
#include<string.h>

int num_cases, num_se,num_q,firstOcc[200],chosenSE=-1,max=0;
char name[200][100],query[200][100];

calcFirst()
{
	int i,j,flag=0;
	for(i=1;i<=num_se;i++)
	{
		flag=0;
		for(j=max+1;j<=num_q;j++)
		{
		if(strcmp(name[i],query[j])==0 && i!=chosenSE)
			{
			firstOcc[i]=j;
			flag=1;
			break;
			}
		}
		if(i!=chosenSE && flag==0)
			firstOcc[i]=num_q+1;
		printf("%d\t",firstOcc[i]);
	}
	printf("\n");
}

calcMax()
	{
		int i;
		for(i=1;i<=num_se;i++)
			{
			if(firstOcc[i]>max && i!=chosenSE)
				{
				max=firstOcc[i];
				chosenSE=i;
				//printf("CSE : %d\n",chosenSE);
				}
			}
	}

int main()
	{
		int i,j,casen;
		FILE* rf;
		FILE* wf;
		rf=fopen ("in","r");
		wf=fopen ("out","w");

		fscanf(rf,"%d\n",&num_cases);
		printf("%d\n",num_cases);
		
		//iterate thru the cases
		
		for(i=1;i<=num_cases;i++)
			{
			max=0;chosenSE=-1;
			// num of search engines
			fscanf(rf,"%d\n",&num_se);
			printf("%d\n",num_se);
			// read names of SEs
			for(j=1;j<=num_se;j++)
				{
				fgets (name[j],100,rf);
				//printf("%s\n",name[j]);
				}
			// num of queries
			fscanf(rf,"%d\n",&num_q);
			printf("%d\n",num_q);
			for(j=1;j<=num_q;j++)
				{
				fgets (query[j],100,rf);
				//printf("%s\n",query[j]);
				}
			for(j=1;j<=num_se;j++)
				{
				firstOcc[i]=num_q+1;
				}
			casen=-1;
			do
//for(j=0;j<4;j++)
			{
			calcFirst();
			calcMax();
			casen++;
			}
			while (max<=num_q);

			printf("case %d : %d\n",i,casen);
			fprintf (wf,"Case #%d: %d\n",i,casen);
			}
		
	}
