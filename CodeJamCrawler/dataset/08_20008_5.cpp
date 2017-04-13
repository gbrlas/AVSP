#include <stdio.h>
#include <string.h>



void asort(int a[], int size)
	{
	int i,j,temp;
	for(i=1;i<size;i++)
		for(j=i;j<=size;j++)
		{
		if(a[i]<a[j])
			{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}



void printa(int a[],int size)
	{
	int i;
	for(i=1;i<=size;i++)
		printf ("%d\t",a[i]);
	printf ("\n");
	}



void place (int p,int k,int l,int cf[],int cp[][200])
	{
		int i,j,count=1;
		for(i=1;i<=p;i++)
			{
			for(j=1;j<=k;j++)
				{
				if(count<=l)
					cp[j][i]=cf[count];
				else
					cp[j][i]=0;
				count++;
				
				}
			}
		for(i=1;i<=k;i++)
			{
			for(j=1;j<=p;j++){
				printf("%d\t",cp[i][j]);}
			printf("\n");
			};
	}
int check(int p,int k,int l,int cf[],int cp[][200])
	{
		int i,count=0;
		for(i=1;i<=l;i++)
			{
			if(cf[i]==0)
				count++;
			}
	}
long calc(int p,int k,int l,int cp[][200])
	{
		int i,j;
		long sum=0;
		for(i=1;i<=k;i++)
			{
			for(j=1;j<=p;j++)
				{
				sum+=(cp[i][j]*j);
				}
			}
		return sum;
	
	}
int main()
	{
		int i,j;
		long casen;
		int num_elements,cf[2000],cp[200][200],num_cases=0,flag;		
		int p,k,l;
		int ii,jj;

		FILE* rf;
		FILE* wf;
		rf=fopen ("in1","r");
		wf=fopen ("out1","w");

		fscanf(rf,"%d\n",&num_cases);
		printf("%d\n",num_cases);
		
		//iterate thru the cases
		
		for(i=1;i<=num_cases;i++)
			{
			fscanf(rf,"%d %d %d\n",&p,&k,&l);
			printf("%d %d %d\n",p,k,l);

			for(j=1;j<=l;j++)
				{
				fscanf(rf,"%d ",&cf[j]);
				}

			printa(cf,l);
			asort(cf,l);
			printa(cf,l);

		for(ii=1;ii<=k;ii++)
			for(jj=1;jj<=p;jj++)
				cp[ii][jj]=0;
			
			if((p*k)<l)
				{
					flag=check(p,k,l,cf,cp);
					if((flag+(p*k))<l)
					{
						printf("case %d : IMPOSSIBLE\n",i);
						fprintf (wf,"Case #%d: IMPOSSIBLE\n",i);
					}
					else
					{
					place (p,k,l,cf,cp);
					casen=calc(p,k,l,cp);
					printf("case %d : %d\n",i,casen);
					fprintf (wf,"Case #%d: %d\n",i,casen);
					}
				}
			else
				{
					place (p,k,l,cf,cp);
					casen=calc(p,k,l,cp);
					printf("case %d : %d\n",i,casen);
					fprintf (wf,"Case #%d: %d\n",i,casen);
				}
			}
		
	}
