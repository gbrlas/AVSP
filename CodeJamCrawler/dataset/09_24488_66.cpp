#include <stdio.h>
#include <stdlib.h>

typedef struct{
     int n;
     int f;                     /* bool value */
     char k;
}node;

char key;
node *pn;

node *find_sink (node *p, int h, int w)
{
     int r = (p-pn);
     int s = 0, low = p->n;
    
     if (r >= w && (p-w)->n < low) {
          low = (p-w)->n;
          s = -w;
     }
     if (r % w && (p-1)->n < low) {
          low = (p-1)->n;
          s = -1;
     }
     if (r%w != w-1 && (p+1)->n < low) {
          low = (p+1)->n;
          s = 1;
     }
     if (r+w < h*w && (p+w)->n < low) {
          low = (p+w)->n;
          s = w;
     }
     if (s == 0)
          return NULL;
     return  p+s;
}

char go_sink (node *p, int h, int w)
{
     p->f = 1;
     node *ps = find_sink (p, h, w);
     if (ps) {
          if (ps->f) 
               p->k = ps->k;
          else 
               p->k = go_sink (ps, h, w);

     } else {
          p->k = key;
          key++;
     }
     return p->k;
}


int main ()
{
     FILE *rfp = fopen ("B-large.in", "r");
     FILE *wfp = fopen ("B-large.out", "w");

     int t, h, w, i, j, k;
     node *p;

     fscanf (rfp, "%d", &t);
     for (i = 0; i < t; i++) {
          fscanf (rfp, "%d %d", &h, &w);
          pn = calloc (sizeof (node), h * w);
          if (!pn)
               exit (1);
          for (j = 0; j < h; j++)
               for (k = 0; k < w; k++)
                    fscanf (rfp, "%d", &(pn+j*w+k)->n);
          key = 'a';
          for (j = 0; j < h; j ++)
               for (k = 0; k < w; k++) {
                    p = pn+j*w+k;
                    if (p->f)
                         continue;
                    go_sink (p, h, w);
               }
          fprintf(wfp, "Case #%d: \n", i+1);
          for (j = 0; j < h; j++) 
               for (k = 0; k < w; k++) {
                    fprintf(wfp, "%c ", (pn+j*w+k)->k);
                    if (k == w-1)
                         fprintf (wfp, "\n");
               }
          free (pn);
     }
     fclose (rfp);
     fclose (wfp);
}

