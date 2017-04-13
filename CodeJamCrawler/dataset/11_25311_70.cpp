#include <stdio.h>

int main(int argc, char **argv)
{
    int t, i;
    int n; 
    char r[2]; char ro;
    int p;
    int d, dt, da, doa;
    int op, bp;
    int od, bd;
    scanf("%d", &t);
    for (i = 1; i <= t; i ++)
    {
        d = dt = da = doa = 0;
        ro = 'P';
        op = bp = 1;
        od = bd = 0;
        scanf("%d", &n);
        while(n -- > 0)
        {
            scanf("%s %d", r, &p);
            switch(r[0])
            {
                case 'O':
                    dt = abs(p - op);
                    // op = p;
                    break;
                case 'B':
                    dt = abs(p - bp);
                    // bp = p;
                    break;
            }
//            printf ("ro=%c, r=%c, %d=>%d, dt=%d+1=%d, doa=%d, ", ro, r[0], (r[0] == 'O' ? op : bp), p, dt, dt+1, doa);
            switch(r[0])
            {
                case 'O':
                    op = p;
                    break;
                case 'B':
                    bp = p;
                    break;
            }
            if (r[0] != ro)
            {
                if (doa <= dt)
                {
//                    printf ("da=%d, ", doa);
                    dt -= doa;
                }
                else
                {
//                    printf ("da=%d, ", dt);
                    dt = 0;
                }
                doa = 0;
            }
            else
            {
                //printf ("na=%d, ", 0);
            }
            dt += 1;
            d += dt;
            if (r[0] != ro)
            {
                doa = dt;
            }
            else
                doa += dt;
            ro = r[0];
//            printf ("d=%d\n", d);
        }
        printf ("Case #%d: %d\n", i, d);
    }
    return 0;
}
