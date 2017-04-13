#include<stdio.h>

int ar[17];
int main()
{
    int test,t;
    scanf("%d",&test);
    t=1;
    while(t<=test)
    {
        int a,b,c[8],buff,i,j,count=0;
        for(i=0;i<17;i++)
        {
            ar[i]=0;
        }
        scanf("%d",&a);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++){
                                if(i+1==a){
                                            scanf("%d",&c[j]);
                                            ar[c[j]]++;

                                            }
                                            else
                                                scanf("%d",&buff);
                                                }

        }
        scanf("%d",&b);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++){
                                if(i+1==b){
                                            scanf("%d",&c[4+j]);
                                            ar[c[4+j]]++;
                                            }
                                            else scanf("%d",&buff);
                                            }
        }
        for(i=0;i<4;i++)
        {
            if(ar[c[i]]==2)
            {
                count++;
                buff=c[i];
            }
        }
        if(count==0)
        {
            printf("Case #%d: Volunteer cheated!\n",t);
        }
       else if(count==1)
        {
            printf("Case #%d: %d\n",t,buff);
        }
      else  if(count>1)
        {
            printf("Case #%d: Bad magician!\n",t);
        }
        t++;
    }
    return 0;
}
