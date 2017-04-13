#include<stdio.h>

int main()
{
    int i,j,k,l,r,c,t,T,m;
    char A[51][51];
    char ch;
    
    scanf("%d",&T);
    
    for(t=1;t<=T;t++)
    {
        scanf("%d",&r);
        scanf("%d",&c);
        
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                ch='4';
                while((ch!='.')&&(ch!='#'))
                scanf("%c",&ch);    
                A[i][j]=ch;
            }    
            
        }
        
        m=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
            if(A[i][j]=='#')
               {
                if((A[i+1][j]=='#')&&(A[i+1][j+1]=='#')&&(A[i][j+1]=='#'))
                   {
                    A[i][j]='/';
                    A[i][j+1]='\\';
                    A[i+1][j]='\\';
                    A[i+1][j+1]='/';    
                    }    
                 else
                    {
                    m=1;    
                    break;
                    }   
                }    
                
            }    
        if(m==1)
          break;
        }  
    printf("Case #%d:\n",t);
          
    if(m==0)
    {
    for(i=0;i<r;i++)
        {
        for(j=0;j<c;j++)
            {
            printf("%c",A[i][j]);    
            }    
            printf("\n");
        }    
    }
    else
    {
    printf("Impossible\n");    
    }  
    }
    
    return 0;
}
