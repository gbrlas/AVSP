#include <algorithm>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int count(int *x, int m, int *y, int n)
{
   int i, j, k;
   for(k=i=j=0; j<n; j++)
   {
      for(; i<m && x[i]<y[j]; i++);
      if(i<m)
      {
         i++;
         k++;
      }
   }
   return k;
}

int main()
{
   char s[1024];
   int As[128], Af[128], Bs[128], Bf[128], N, A, B, T, t, i;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &N);
      scanf("%d", &A);
      scanf("%d", &B);
      
      for(i=0; i<A; i++)
      {
         scanf("%s", s);
         As[i]=((s[0]-'0')*10+s[1]-'0')*60+((s[3]-'0')*10+s[4]-'0');
         scanf("%s", s);
         Af[i]=((s[0]-'0')*10+s[1]-'0')*60+((s[3]-'0')*10+s[4]-'0')+N;
      }
      for(i=0; i<B; i++)
      {
         scanf("%s", s);
         Bs[i]=((s[0]-'0')*10+s[1]-'0')*60+((s[3]-'0')*10+s[4]-'0');
         scanf("%s", s);
         Bf[i]=((s[0]-'0')*10+s[1]-'0')*60+((s[3]-'0')*10+s[4]-'0')+N;
      }
      
      sort(As, As+A);
      sort(Af, Af+A);
      sort(Bs, Bs+B);
      sort(Bf, Bf+B);
      
      printf("Case #%d: %d %d\n", t, A-count(As, A, Bf, B), B-count(Bs, B, Af, A));
   }
   
   return 0;
}
