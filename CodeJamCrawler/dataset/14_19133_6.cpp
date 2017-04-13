#include<stdio.h>

int main()
{
    int a[4][4],b[4][4],times,row,row1,res,count;
    int i,j,no;
    scanf("%d",&times);
    count=1;
    res=0;
    
    while(count<=times)
    {
                       res=no=0;
                       
                       scanf("%d",&row);
                       for(i=0;i<4;i++)
                               for(j=0;j<4;j++)
                                        scanf("%d",&a[i][j]);
                                       
                                         
                       scanf("%d",&row1);
                       for(i=0;i<4;i++)
                               for(j=0;j<4;j++)
                                        scanf("%d",&b[i][j]);
                       
                          for(i=0;i<4;i++)
                          {
                               for(j=0;j<4;j++)
                                       if(a[row-1][i]==b[row1-1][j])
                                       {
                                               res++;
                                               no=b[row1-1][j];
                                               if(res>1)
                                               break;
                                       }
                                       
                               if(res>1)
                               break;
                          }                    
                       if(res==1)                        
                       printf("Case #%d: %d",count,no);
                       else if(res>1) 
                       printf("Case #%d: Bad magician!",count); 
                       else if(res==0)
                       printf("Case #%d: Volunteer cheated!",count);
                       
                       printf("\n");
                       count++;
    }
                       
    
    return 0;
}
      
