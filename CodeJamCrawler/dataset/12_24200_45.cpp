#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    
    FILE *x;
    FILE *y;
    x=fopen("input.in","r");
    y=fopen("output.txt","w");
    fscanf(x,"%d",&T);
    for(i=0;i<T;i++)
    {
                    int N,S,p,ans=0,j;
                    fprintf(y,"Case #%d: ",i+1);
                    fscanf(x,"%d",&N);
                    fscanf(x,"%d",&S);
                    fscanf(x,"%d",&p);
                    
                    for(j=0;j<N;j++)
                    {
                                    int point;
                                    fscanf(x,"%d",&point);
                                    if(point>=p)
                                    {
                                        if((point-p)/2>=p-1)
                                        {
                                                    ans++;
                                        }
                                        else if (((point-p)/2>=p-2)&&(S>0))
                                        {
                                                    ans++;
                                                    S--;
                                        }
                                    }
                    
                    }
                    fprintf(y,"%d\n",ans);
                    
    }
    return 0;
}
