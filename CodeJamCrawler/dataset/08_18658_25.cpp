#include<stdio.h>
#include<string.h>

char engine[110][110];
char query[1010][110];
int sudah[110];

int main()
{
    int n,s,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d\n",&s);
        for(int j=0;j<s;j++)
        {
            gets(engine[j]);   
        }   
        scanf("%d\n",&q);
        for(int j=0;j<q;j++)
        {
            gets(query[j]);   
        }
        
        for(int k=0;k<s;k++)
        {
            sudah[k]=0;   
        }
        int banyak=0;
        int hasil=0;
        for(int j=0;j<q;j++)
        {
            for(int k=0;k<s;k++)
            {
                if(strcmp(query[j],engine[k])==0)
                {
                    if(sudah[k]==0)
                    {
                        banyak++;
                        if(banyak==s)
                        {
                            for(int m=0;m<s;m++)
                            {
                                sudah[m]=0;   
                            } 
                            banyak=1;
                            hasil++;
                        }   
                    }   
                    sudah[k]=1;
                }   
            }
            /*for(int x=0;x<s;x++)
            {
                printf("%d ",sudah[x]);   
            }
            printf("\n");*/
        }
        printf("Case #%d: %d\n",i+1,hasil);
    }
    return 0;   
}
