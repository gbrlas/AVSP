#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mena1[25],menb1[25];
int mena2[25],menb2[25];
void quick(char arr[][15],int kr,int kn)
{
	int j,k;
	char temp[15];
	if(kr<kn)
	{
		j=kr;
		k=kn+1;
		do
		{
			do{
				j++;
			}while(strcmp(arr[j],arr[kr])<0);
			do{
				k--;
			}while(strcmp(arr[k],arr[kr])>0);
			if(j<=k)
			{
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[k]);
				strcpy(arr[k],temp);
			}
		}while(j<=k);
		strcpy(temp,arr[k]);
		strcpy(arr[k],arr[kr]);
		strcpy(arr[kr],temp);
		quick(arr,kr,k-1);
		quick(arr,k+1,kn);
		
	}
}

int main()
{
	char jam1[25][15];
	char jam2[25][15];
	int flaga[25];
	int flagb[25];
	int i,j,k,l;
	int n,t;
	int aa,bb;
	int juma,jumb;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		scanf("%d %d\n",&aa,&bb);
		memset(flaga,0,sizeof(flaga));
		memset(flagb,0,sizeof(flagb));
		for(j=0;j<aa;j++)
		{
			gets(jam1[j]);
		}
		quick(jam1,0,aa-1);
		
		for(j=0;j<bb;j++)
		{
			gets(jam2[j]);
		}
		quick(jam2,0,bb-1);
	
		for(j=0;j<aa;j++)
		{
			
			mena1[j]=((jam1[j][0]-48)*600)+((jam1[j][1]-48)*60)+((jam1[j][3]-48)*10)+jam1[j][4]-48;
			
			mena2[j]=((jam1[j][6]-48)*600)+((jam1[j][7]-48)*60)+((jam1[j][9]-48)*10)+jam1[j][10]-48;
		
		}
	
		for(j=0;j<bb;j++)
		{
			menb1[j]=((jam2[j][0]-48)*600)+((jam2[j][1]-48)*60)+((jam2[j][3]-48)*10)+jam2[j][4]-48;
			
			menb2[j]=((jam2[j][6]-48)*600)+((jam2[j][7]-48)*60)+((jam2[j][9]-48)*10)+jam2[j][10]-48;
	
		}
		juma=aa;
		for(j=0;j<bb;j++)
		{
			for(k=0;k<aa;k++)
			{
				if(mena1[k]-menb2[j]>=t&&flaga[k]==0)
				{
					juma--;
					flaga[k]=1;
					
				
					break;
				}
			}
		}
	
		jumb=bb;
		for(j=0;j<aa;j++)
		{
			for(k=0;k<bb;k++)
			{
				if(menb1[k]-mena2[j]>=t&&flagb[k]==0)
				{
					jumb--;
					flagb[k]=1;
					
						
					break;
				}
			}
		}
			printf("Case #%d: %d %d\n",i+1,juma,jumb);
	}
	return 0;
}
