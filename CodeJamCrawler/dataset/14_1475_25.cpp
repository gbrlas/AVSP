#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int a[5][5],ar[5][5],t,query,query1,n=0;
	cin>>t;
	while(n!=t)
	{ int aux[17]={0};
	  int count=0,count2=0,result=0;
		cin>>query;
		for(int i=1;i<=4;i++)
	      {for(int j=1;j<=4;j++)
	        { 
				scanf("%d",&a[i][j]);
	     	   }
	     	   //printf("\n");
	        	}
	      // printf("\n"); 	
	    cin>>query1;
	    for(int i=1;i<=4;i++)
	      { 
				for(int j=1;j<=4;j++)
	             {
					scanf("%d",&ar[i][j]);
	           	}
	        //   	printf("\n");
		}
        for(int i=1;i<=4;i++)
	      {
		     aux[a[query][i]]++;
		     aux[ar[query1][i]]++;
		   }
		   for(int j=1;j<=16;j++)
	          {
					if(aux[j]==2)
					 {
							count++;
					result=j;
					}

					}
			if(count==0)
			{
				printf("Case #%d: Volunteer cheated!\n",n+1);
				}
			if(count==1)
			{printf("Case #%d: %d\n",n+1,result);
				}
			if(count>1)
			{
				printf("Case #%d: Bad magician!\n",n+1);
				}	
			n++;	
    }
    return 0;
}
