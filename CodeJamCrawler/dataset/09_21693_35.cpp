#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char order[] = "0123456789";
int array[1000];
int n;
char string[1000];


void swap(int a,int b) 
	{
   	int c;
   	c = array[a];
   	array[a] = array[b];
   	array[b] = c;
	}

void copy() 
	{
    	int i,j,k;
	for(i = 0;string[i]; i ++)
		{
		for(k=0;order[k];k++)
			{
			if(string[i] == order[k])
				array[i] = k;
			}
		}
	}

void sort()
	{
	int i,j,k;
	for(i=1 ; i <= n;i++)
		{
		for(j=i+1;j<=n;j++)
			{
			if(array[i] > array[j])
				{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
				}
			}
		}
	}

int main() 
	{
	int i,j,flag,key,top,bottom,noi,temp,saket=0,alok;
	scanf("%d",&noi);
	while(saket<noi)  
		{
           	scanf("%s",string);
		copy();
		n = strlen(string) - 1;
		//sort();
		//for(i = 0;i<=n; i ++) 
		//	printf("%c",order[array[i]]);
		//printf("\n");
		//while(1) 
		  // 	{
		      	flag = 0;
              		for(i = n; i>=1; i --)
              		 	{
              		 	//printf("hi\n");
			  	if(array[i] > array[i-1]) 
			  		{
					flag = 1;
					break;
				  	}
			  	}
			if(flag == 0)
				{
				alok = n;
				
				while(array[alok]==0)
					alok--;
				//printf("%d\n",alok);
				if(alok!=0)
					{
					array[n+1] = array[0];	
					array[0] = array[alok];
					array[alok] = 0;
					}
				else
					{
					array[n+1] = 0;
					}
				
				n++;
				sort();
				//printf("%d",n);
				printf("Case #%d: ",(saket + 1));
				for(j = 0; j<=n;j ++)
					printf("%c",order[array[j]]);
				printf("\n");
				saket++;
				continue;
				
				}
			key = i - 1;
			i = n;
			while(array[i] <= array[key])
				i--;			
			swap(key,i);
			top = n;
			bottom = key+1;
			while(top > bottom) 
				{
				swap(top,bottom);
				top--;
				bottom++;
			  	}
			printf("Case #%d: ",(saket + 1));
			for(j = 0; j<=n;j ++)
				printf("%c",order[array[j]]);
			printf("\n");
			saket++;

		   //	}  
		} 
		
		return 0;
	}


