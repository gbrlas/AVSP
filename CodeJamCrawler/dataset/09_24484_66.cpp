#include <stdio.h>
#include <stdlib.h>


char* match_if (char *s, char *ps)
{
     while (*s != ')') {
          if (*ps == *s) {
               while (*s != ')')
                    s++;
               return s;
          }
          s++;
     }
     return NULL;
}

int main ()
{
     FILE *rfp = fopen ("A-large.in", "r");
     FILE *wfp = fopen ("A-large.out", "w");

     int l, d, n, i, j;


     fscanf (rfp, "%d %d %d", &l, &d, &n);
     char *str[5000];
     char *buf = malloc (d * (l+1));
     if (!buf)
          exit (1);
     for (i = 0; i < d; i ++)
          str[i] = buf + (l+1) * i;

     for (i = 0; i < d; i++) {
          fscanf (rfp, "%s", str[i]);
          
     }
     char tes[430];
     char *s, *e, *ps;
     int count, match;

     for (i = 0; i < n; i ++) {
          count = 0;
          fscanf (rfp, "%s", tes);
          for (j = 0; j < d; j++) {
               s = e = tes;
               match = 0;
               ps = str[j];
               while (*s) {
                    if (*s == '(') {
                         s++;
                         e = match_if (s, ps);
                         if (!e) {
                              match = 0;
                              break;
                         } else {
                              s = e+1;
                              match = 1;
                         }
                    } else {
                         if (*s == *ps) {
                              s++;
                              match = 1;
                         } else {
                              match = 0;
                              break;
                         }
                    }
                    ps++;
               }
               if (match)
                    count++;
          }

          fprintf (wfp, "Case #%d: %d\n", i+1, count);
     }
     fclose (rfp);
     fclose (wfp);
     free(buf);
}

