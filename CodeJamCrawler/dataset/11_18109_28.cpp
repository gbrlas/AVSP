//  RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP

#include <stdio.h>
#include <string.h>

int t, n, m;
char s[200][200];


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &t);
    int k = 1;
    int j, i, aux;
    int nr;
    double sum;
    while (k <= t)
    {
          int fail = 0;
          //memset(left, 0, sizeof(left));
          scanf ("%d %d\n", &n, &m);
          for (i = 1; i <= n; ++i)
              scanf("%s\n", s[i]+1);
              
          for (i = 1; i <= n; ++i)
          {
              for (j = 1; j <= m; ++j)
              {
                  if (s[i][j] == '#' && s[i+1][j] == '#' && s[i][j+1] == '#' && s[i+1][j+1] == '#'
                     && i+1 <= n && j+1 <= m)


                  {
                     s[i][j] = '/';
                     
                     s[i+1][j] = '\\';
                     s[i][j+1] = '\\';
                     s[i+1][j+1] ='/';
                  }
                  else if (s[i][j] == '#')
                  {
                      fail = 1;
                  }
              }
          }


          printf("Case #%d:\n", k++);
          if (fail)
          {
                   printf("Impossible\n");
          }
          else
          {
              for (i = 1; i <= n; ++i)
              {
                for(j = 1; j <= m; ++j)
                  printf("%c", s[i][j]);
               printf("\n");
                  
              }
          }




    }
    return 0;
}
