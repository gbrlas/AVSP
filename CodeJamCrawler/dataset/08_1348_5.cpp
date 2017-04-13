#include<stdio.h>
int main()
{
	int index1,test,index2,k,index3,searchno,queryno,tr[1000],count=0,flag=0;
	char str[1000][100],query[1000][100];
	scanf("%d",&test);
	for(index1=0;index1<test;index1++)
	{   count=0;
	    scanf("%d",&searchno);
	    for(index2=0;index2<searchno;index2++)
	       {fflush(stdin);
		scanf(" %[^\n]",str[index2]);
		 tr[index2]=0;
	       }
	    scanf("%d",&queryno);
	    for(k=0;k<queryno;k++)
	       { fflush(stdin);
		 scanf(" %[^\n]",query[k]);
	       }

	    for(k=0;k<queryno;k++)
	    { flag=0;
	      for(index2=0;index2<searchno&&!flag;index2++)
		 if(strcmp(query[k],str[index2])==0&&tr[index2]==0)
		    { flag=1;
		      tr[index2]=1;

		   for(index3=0;index3<searchno;index3++)
		     if(tr[index3]==0)
			break;
		   if(index3==searchno)
		       { for(index3=0;index3<searchno;index3++)
			  tr[index3]=0;
			 count++;
			 tr[index2]=1;
		       }
		   }

	    }
        printf("Case #%d: %d\n",index1+1,count);

	    }
        return 0;

	}
