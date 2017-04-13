#include<stdio.h>
#include<stdlib.h>


int cmpfunc (const void *a, const void *b)
     {
       const double *da = (const double *) a;
       const double *db = (const double *) b;
     
       //return (*da > *db) - (*da < *db);
       if(*da < *db)
   		return -1;
   else if(*da > *db)
   		return 1;
   else
   		return 0;
     }

int check(double a[10],double b[10],int n,int j)
{
	int i = 0;
	int flag = 1;
	int count = 0;
//	for(i = 0 ; i <n ; i++)
//	{
	//	printf("%0.2f ",a[i]);
	//}
//	printf("\n");
	//for(i = 0 ; i <n ; i++)
	//{
	//	printf("%0.2f ",b[i]);
	//}
	for(i = j ; i < n ;i++)
	{
		if(a[i] > b[i])
		{
			count++;
			
		}
		else
		{
			//printf("(%0.2f %0.2f)",a[i],b[i]);
			flag = 0;
			break;	
		} 
	}
	if(flag == 0)
	{
		return 0;
	}
	else
		return count;
	}	

int main()
{
	int T,i;
	FILE *f1,*f2;
	f1 = fopen("D.txt","r");
	f2 = fopen("test.txt","w");
	fscanf(f1,"%d",&T);
	for(i = 1 ; i <= T ; i++)
	{
		int N;
		fscanf(f1,"%d",&N);
		int res = 0;
		int j,k;
		int count = 0;
		double a[N],b[N],a1[N],b1[N];
		for(j = 0 ; j < N ; j++)
		{
			fscanf(f1,"%lf",&a[j]);
			a1[j] = a[j];
		}
		for(j = 0 ; j < N ; j++)
		{
			fscanf(f1,"%lf",&b[j]);
			b1[j] = b[j];
		}
		qsort(a,N,sizeof(double),cmpfunc);
		
		qsort(b,N,sizeof(double),cmpfunc);
		qsort(a1,N,sizeof(double),cmpfunc);
		qsort(b1,N,sizeof(double),cmpfunc);
		for(j = 0 ;j < N ;j++)
		{
			int flag = 0 ;
			for(k =0  ; k < N ;k++)
			{
				
				if(a[j] < b[k])
				{
					a[j] = -1;
					b[k] = -1;
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				res = N - j;
				break;
			}
		}
		for(j = 0 ; j < N ;j++)
		{
			//if(a1[j] > b1[j])
			int t = 0;
			//for(k = 0 ; k < N ; k++)
			//{
			//	printf("%f",a1[k]);
			//}	
			t = check(a1,b1,N,j);
			
			if( t == 0)
			{
				//printf("(%0.2f , %0.2f)",a1[j],b1[N-1]);
				a1[j] = -1;
				b1[N-1] = -1;
				//printf("%d",j);
				qsort(a1,N,sizeof(double),cmpfunc);
			//	for(k = 0 ; k < N ; k++)
		//{
		//	printf("%f",a1[k]);
		//}	
				qsort(b1,N,sizeof(double),cmpfunc);
			}
			else
			{
				count = t;
				break;
			}				
			//	break;
		}
		
		fprintf(f2,"Case #%d: %d %d\n",i,count,res);
	}
	return 0;
}
