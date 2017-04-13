#include <algorithm>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int x[128][1024], q[1024];

int main()
{
   char s[1024];
   int S, Q, T, t, i, j, k;
   map<string,int> se;
   
   for(gets(s), T=atoi(s), t=1; t<=T; t++)
   {
      gets(s), S=atoi(s);
      for(i=S; i--; gets(s), se[s]=i);
      
      gets(s), Q=atoi(s);
      for(i=Q; i--; gets(s), q[i]=se[s]);
      
      for(i=S; i--; x[i][0]=0);
      for(j=0; j<Q; j++)
         for(i=S; i--; )
         {
            if(q[j]==i)
            {
               x[i][j+1]=1<<30;
               for(k=S; k--; )
                  if(k!=i)
                     x[i][j+1]<?=x[k][j]+1;
            }
            else
               x[i][j+1]=x[i][j];
         }
      
      k=1<<30;
      for(i=S; i--; k<?=x[i][Q]);
      printf("Case #%d: %d\n", t, k);
   }
   
   return 0;
}
