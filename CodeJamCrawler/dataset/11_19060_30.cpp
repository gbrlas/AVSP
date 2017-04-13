#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
    int time, t, n, r[1001], i, j, k, poso, posb;
    char p[1001];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
            scanf("%d",&n);
            for(j=0;j<n;j++)
            {
                    scanf("%s %d",&p[j],&r[j]);
            }
            time = 0;
            poso = 1;
            posb = 1;
            for(j=0;j<n;j++)
            {
                   if(p[j]=='O')
                   {
                           for(k=j+1;(p[k]=='O')&&(k<n);k++);
                           while(poso != r[j])
                           {
                                   if(r[j]>poso)
                                          poso++;
                                   else
                                          poso--;
                                   if(p[k]=='B')
                                   {
                                          if(r[k]>posb)
                                                posb++;
                                          if(r[k]<posb)
                                                posb--;
                                   }
                                   time++;
                           }
                   }
                   if(p[j]=='B')
                   {
                            for(k=j+1;(p[k]=='B')&&(k<n);k++);
                            while(posb != r[j])
                            {
                                    if(r[j]>posb)
                                           posb++;
                                    else
                                           posb--;
                                    if(p[k]=='O')
                                    {
                                           if(r[k]>poso)
                                                 poso++;
                                           if(r[k]<poso)
                                                 poso--;
                                    }
                                    time++;
                            }
                   }
                   time++;
                   if(p[j]=='O' && p[k] == 'B')
                   {
                         if(r[k]>posb)
                              posb++;
                         if(r[k]<posb)
                              posb--;
                   }
                   if(p[j]=='B' && p[k] == 'O')
                   {
                         if(r[k]>poso)
                              poso++;
                         if(r[k]<poso)
                              poso--;
                   }      
                   
            }
            printf("Case #%d: %d\n",i+1,time);
    }
    return 0;
    
}                    
                                          
            
            
            
            
