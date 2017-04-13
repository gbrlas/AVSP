# include <stdio.h>
int arr[101];



int main(void)
{
    long int i,j,t;
    char arrpd[16];
    
    int cnt =0;
    int n,pg,pd,flag;
    for(i=100;i>=0;i--)
        arr[i] = 0;

    for(i=100;i>=1;i--)
        for(j=i;j>=0;j--)
        {
            t = j*100;
            t = t/i;
            if((t*i) == (j*100))
            {
                if(arr[t] == 0)
                {
                    cnt++;
                }
                    arr[t] = i;
                    /*if(cnt == 100)
                    {
                        printf("DONE !! \n");
                        i = 0;
                        break;
                    }*/
                
            }
        }
            
//    for(i=0;i<=100;i++)
//        printf("%d\n",arr[i]);

    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        flag = 1;
        scanf("%s ",arrpd);
    
        j=0;
        while(arrpd[j]!=0)
            j++;

        if(j<4)
           n = atoi(arrpd);
        else
           n = 101;

        scanf("%d ",&pd);
        scanf("%d ",&pg);
        
        //printf("::%d::\n",n);

        if((arr[pd] > n) || (arr[pd] == 0))
            flag = 0;

        if((pg == 100) && (pd !=100))
            flag = 0;

        if((pg == 0) && (pd !=0))
            flag = 0;

        if(flag ==1)
            printf("Case #%ld: Possible\n",i+1);
        else
            printf("Case #%ld: Broken\n",i+1);
     }
            
    return 1;
}

        
