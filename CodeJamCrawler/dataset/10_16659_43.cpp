#include<stdio.h>
#include<stdlib.h>
int  T,R,K,N;
int data[1010];
int main()
{   int q,w,e,r,t,out=0;
    freopen("C-small-attempt2.in.txt","r",stdin);
    freopen("C-smallbood.out","w",stdout);
    scanf("%d",&T);
    for(q=0;q<T;q++)
    {  scanf("%d%d%d",&R,&K,&N);
       for(w=0,out=0,e=0;w<N;w++)
       {  scanf("%d",&data[w]);e+=data[w];
       }
       if(e>K){
       for(w=0,e=0,r=0;w<R;e++)
       {  if(e==N) e=0;
          if(r+data[e]>K)
          {  w++;
             out+=r;
             r=data[e];
          }
          else r+=data[e];
       }
       }
       else out=e*R;
       printf("Case #%d: %d\n",q+1,out);
    }
    return 0;
}
