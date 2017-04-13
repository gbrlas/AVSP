//  RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP

#include <stdio.h>
#include <string.h>

int t, n, m;
char s[200][200];
int x[100000];


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &t);
    int k = 1;
    int j, i, aux;
    int nr;
    double sum;
    int L, H;
    int ok;
    int res;
    int fail;
    while (k <= t)
    {
          scanf ("%d %d %d\n", &n, &L, &H);
  
          for (i = 1; i<= n; ++i)
              scanf("%d", &x[i]);
         
         fail = 1;
         for (i = L; i <= H; ++i)
         {
             ok = 1;
             for (j = 1; j <= n; ++j)
                 if (!(x[j]%i == 0 || i%x[j] == 0))
                 {
                    ok = 0;
                 }
             if (ok)
             {
             fail = 0;
              res = i;
              break;
             }
             }
         
          if (fail)
          {
                    printf("Case #%d: NO\n", k++);
          }
          else
          {
                             printf("Case #%d: %d\n", k++, res);
          }




    }
    return 0;
}
