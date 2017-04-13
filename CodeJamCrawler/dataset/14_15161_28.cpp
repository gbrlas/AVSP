#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

int main()
{
	int T,it;
	FILE *f2,*f1;
	f1 = fopen("out1.txt","w");
	f2 = fopen("A-small-attempt2.txt","r");
	fscanf(f2,"%d",&T);
	
	//printf("B");
	
	//printf("c");
	
	//printf("a");
	for(it = 1 ; it <=T ;it++)
	{
		int ans1,ans2,i,j;
		
		int a[4][4],cand1[4],temp;
		fscanf(f2,"%d",&ans1);
		//printf("%d",ans1);
		for(i = 0 ; i < 4 ; i++)
		{
			for(j = 0 ; j <4 ; j++)
			{
				fscanf(f2,"%d",&a[i][j]);		
				//printf("(%d)",a[i][j]);
			}
			
		}
		for(j = 0 ; j < 4;j++)
		{	cand1[j] = a[ans1-1][j];
		//	printf("%d",cand1[j]);
		
		}
		fscanf(f2,"%d",&ans2);
		//printf("%d",ans2);
		int k = 0;
		for(i = 0 ; i < 4 ; i++)
		{
			for(j = 0 ; j <4 ; j++)
			{
				fscanf(f2,"%d",&a[i][j]);
				
			}
		}		
		/*for(i = 0 ; i < 4 ; i++)
		{
			for(j = 0 ; j <4 ; j++)
			{
				printf("%d",a[i][j]);
			}
		}*/		
		for(i = 0 ; i < 4 ;i++)
		{
			for(j = 0 ; j < 4; j++)
			{
			//	printf("[%d,%d]",a[ans2-1][j],cand1[i]);
				if(a[ans2-1][j] == cand1[i])
				{
					k++;
					temp = cand1[i];
					//printf("(%d)",temp);
				}
			}
		}
		fprintf(f1,"Case #%d: ",it); 
		if(k == 1)
		{
			fprintf(f1,"%d\n",temp);
		}
		else if( k == 0)
		{
			fprintf(f1,"Volunteer cheated!\n");
		}
		else
			fprintf(f1,"Bad magician!\n");
	}
	printf("done");
	fclose(f1);
	//fclose(f2);
	return 0;
}	

