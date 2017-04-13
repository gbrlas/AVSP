//  RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP

#include <stdio.h>
#include <string.h>

int t, n;
char s[110][110];
double wp[110], owp[110], oowp[110];
int wins[110], played[110];


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
          memset(wp, 0, sizeof(wp));
          memset(owp, 0, sizeof(owp));
          memset(oowp, 0, sizeof(oowp));
          memset(wins, 0, sizeof(wins));
          memset(played, 0, sizeof(played));
          scanf ("%d", &n);
          for (i = 1; i <= n; ++i)
          {
              scanf("%s\n", s[i]+1);
              //printf("%s\n", s[i]+1);
          }
          
          for (i = 1; i <= n; ++i)
          {
              aux = 0;
              for (j = 1; j <= n; ++j)
              {
                  if (s[i][j] == '1')
                  {
                     aux++;
                     wins[i]++;
                     played[i]++;
                  }
                  else if (s[i][j] == '0')
                  {
                       played[i]++;
                  }
                  }
              //printf("%d\n", aux);
              //if (aux != 0)
              wp[i] = (double)wins[i]/played[i];
              //printf("%lf ", wp[i]);
          }
          for (i = 1; i <= n; ++i)
          {
              sum = 0;
              nr = 0;
              aux = 0;
              for (j = 1; j <= n; ++j)
              {
                  if (s[i][j] == '1')
                  {
                    if (played[j]-1 != 0)
                       sum += (double)wins[j]/(played[j]-1);
                    

                  }
                  else if (s[i][j] == '0')
                  {
                       if (played[j]-1 != 0)
                          sum += (double)(wins[j]-1)/(played[j]-1);
                  }
                  }
              //printf("%d\n", aux);
              //if (aux != 0)
              owp[i] = (double)sum/played[i];
              //printf("%lf ", owp[i]);
          }
          for (i = 1; i <= n; ++i)
          {
              sum = 0;
              nr = 0;
              aux = 0;
              for (j = 1; j <= n; ++j)
                  if (s[i][j] == '1' || s[i][j] == '0')
                  {
                    sum += (double)owp[j];


                  }
 
              //printf("%d\n", aux);
              //if (aux != 0)
              oowp[i] = (double)sum/played[i];
              //printf("%lf ", owp[i]);
          }
          
          printf("Case #%d:\n", k++);
          
          for(i = 1; i <= n; ++i)
          {
                printf("%.12lf\n", (double) 0.25 * wp[i] + (double) 0.50 * owp[i] + (double) 0.25 *oowp[i]);
                //printf("%lf %lf %lf\n", wp[i], owp[i], oowp[i]);

          }


    }
    return 0;
}
