#include<stdio.h>
int hash[17];
int main()
{
    int t,n,i,j,a,flag,count,k,m;
    scanf("%d",&m);
    for(t=1;t<=m;t++)
    {
       for(i=1;i<=16;i++)
       hash[i]=0; 
       
        scanf("%d",&n);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
             scanf("%d",&a);
                if(i==n)
                {
                 hash[a]=1;
                }
            }
        }
        
     count=0; 
scanf("%d",&n);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                scanf("%d",&a);
                if(i==n)
                {
                if(hash[a]==1){
                count++;
                k=a;
                }
                
                }
            }
        }  
        
     if(count==1)
     printf("Case #%d: %d\n",t,k);
     else if(count==0)
     printf("Case #%d: Volunteer cheated!\n",t);
     else
     printf("Case #%d: Bad magician!\n",t);
}
    return 0;
}
           
