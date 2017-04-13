#include<stdio.h>
#include<conio.h>
int main()
{
    long long int t, l, hrs, n, c, a[10001], dist[10001], i ,j ,k, start, max, maxpos;
    long long int time, flag;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
           scanf("%lld %lld %lld %lld",&l,&hrs,&n,&c);
           for(j=0;j<c;j++)
                 scanf("%lld",&a[j]);
           j = 1;
           k = 0;
           while(j<=n)
           {
                 dist[j] = a[k];
                 j++;
                 k++;
                 if(k==c)
                    k = 0;
           }
           j=1;
           time = 0;
           while((time<hrs)&&(j<=n))
           {
                 time = time + 2*dist[j];
                 j++;
           }
           flag = 0;
           j--;
           start = j;
           if(time>hrs)
           {
                 dist[j] = (time - hrs)/2;
                 time = hrs;
                 flag = 1;
           }
           else
                 start++; 
           while(l!=0)
           {
                  max = 0;
                  for(k=start;k<=n;k++)
                  {
                          if(dist[k]>max)
                          {
                                 maxpos = k;
                                 max = dist[k];
                          }
                  }
                  time = time + max;
                  dist[maxpos] = 0;
                  l--;
           }
           if((start!=n)||(flag!=0))
           for(k=start;k<=n;k++)
           {
                   time += dist[k]*2;
           }
           printf("Case #%lld: %lld\n",i+1,time);
    }
    return 0;
} 
                  
