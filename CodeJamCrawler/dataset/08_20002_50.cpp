#include <stdio.h>
#include<string.h>

int t[500][4],na,nb,tt,num_cases;

int check()
	{
	int i;
	for(i=1;i<=(na+nb);i++)
		{
		if (t[i][4]==0)
			return i;
		}
	return -1;
	}
sort()
	{
	int i,j,temp;
	for(i=1;i<(na+nb);i++)
		for(j=i+1;j<=(na+nb);j++)
			{
			if(t[i][1]>t[j][1])
				swap (t[i],t[j]);
			}
	for(i=1;i<=(na+nb);i++)
		{
			printf("%d\t%d\t%d\n",t[i][1],t[i][2],t[i][3]);
		}
	}
swap (int a[4], int b[4])
	{
	int i,temp[4];
	for(i=1;i<=4;i++)
		{
		temp[i]=a[i];
		a[i]=b[i];
		b[i]=temp[i];
		}
	}

update (int pos)
	{
	int i;
	int *temp;
	t[pos][4]=1;
	temp=t[pos];
	for(i=pos+1;i<=(na+nb);i++)
		{
			if((temp[2]+tt)<=t[i][1] && t[i][3]!=temp[3] && t[i][4]==0)
				{
				t[i][4]=1;
				temp=t[i];
				}
		}
	}

int main()
	{
		int i,j,casena,casenb,pos=0;
		int dhr,dmin,shr,smin;
		FILE* rf;
		FILE* wf;
		rf=fopen ("in","r");
		wf=fopen ("out","w");

		fscanf(rf,"%d\n",&num_cases);
		printf("%d\n",num_cases);
		
		//iterate thru the cases
		
		for(i=1;i<=num_cases;i++)
			{
			

			fscanf(rf,"%d\n",&tt);
			printf("%d\n",tt);
			fscanf(rf,"%d %d\n",&na,&nb);
			printf("%d\n%d\n",na,nb);
			//turn around time = tt
			for(j=1;j<=na;j++)
				{
				fscanf(rf,"%d:%d %d:%d\n",&shr,&smin,&dhr,&dmin);
				t[j][1]=(shr*60)+smin;
				t[j][2]=(dhr*60)+dmin;
				t[j][3]=1;
				t[j][4]=0;
				printf("%d\t%d\n",t[j][1],t[j][2]);
				}
			for(j=na+1;j<=(nb+na);j++)
				{
				fscanf(rf,"%d:%d %d:%d\n",&shr,&smin,&dhr,&dmin);
				t[j][1]=(shr*60)+smin;
				t[j][2]=(dhr*60)+dmin;
				t[j][3]=2;
				t[j][4]=0;
				printf("%d\t%d\n",t[j][1],t[j][2]);
				}
			// array contains the time table of both the stations
			sort();
			pos=1;
			casena=0;
			casenb=0;

			while (pos!=-1)
				{
				pos=check();				
				if(t[pos][3]==1 && t[pos][4]==0)
					{
					casena++;
					printf("A %d \t",t[pos][1]);
					}
				else if (t[pos][3]==2 && t[pos][4]==0)
					{
					casenb++;
					printf("B %d \t",t[pos][1]);
					}

				update(pos);
				
				}
			

//			if (na==0) casena=0;if (nb==0) casenb=0;

			printf("case %d : %d\t %d\n",i,casena,casenb);
			fprintf (wf,"Case #%d: %d %d\n",i,casena,casenb);
			}
		
	}
