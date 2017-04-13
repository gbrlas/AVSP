#include <cstdio>

using namespace std;

int main()
{
   int T, t, N, S, p, x[128], i, j, a, b;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d %d", &N, &S, &p);
      a=b=0;
      for(i=N; i--; )
      {
         scanf("%d", &j);
         if(p+2*((p-1)>?0)<=j)
            a++;
         else if(p+2*((p-2)>?0)<=j)
            b++;
      }
      
      printf("Case #%d: %d\n", t, a+(b<?S));
   }
   
   return 0;
}
