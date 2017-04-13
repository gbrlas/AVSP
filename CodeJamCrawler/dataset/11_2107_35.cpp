#include <stdio.h>
#include <string.h>

#define MAXN 110
char winTable[MAXN][MAXN];

int opn[MAXN];
double WP[MAXN];
double OWP[MAXN];
double OOWP[MAXN];
int win[MAXN];

int T,N;

int main()
{
    freopen("A-large.in", "r" , stdin);
    freopen("Alarge.out", "w" , stdout);
    scanf("%d" , &T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d" , &N);
        for(int i=0; i<N; ++i)
        scanf("%s" , winTable[i]);

        //Calculate WP:
        for(int i=0; i<N; ++i)
        {
            opn[i] = 0;
            WP[i] = 0;
            win[i] = 0;
            for(int j=0; j<N; ++j)
            {
                if(winTable[i][j] == '.') continue;
                opn[i]++;
                if(winTable[i][j] == '1') win[i]++;
            }
            WP[i] = win[i]/(double)opn[i];
        }


        //Calculate OWP:
        for(int i=0; i<N; ++i)
        {
            OWP[i] = 0;
            for(int j=0; j<N; ++j)
            {
                if(winTable[i][j] == '1')
                    OWP[i] += win[j]/(double)(opn[j] - 1);
                else if(winTable[i][j] == '0')
                    OWP[i] += (win[j]-1)/(double)(opn[j] - 1);
            }
            OWP[i]/=opn[i];
            //printf("OWP[%d] = %.4f\n" , i, OWP[i]);
        }

        //Calculate OOWP:
        for(int i=0; i<N; ++i)
        {
            OOWP[i] = 0;
            for(int j=0; j<N; ++j)
            {
                if(winTable[i][j] != '.')
                {
                    OOWP[i] += OWP[j];
                }
            }
            OOWP[i]/=opn[i];
        }

        printf("Case #%d:\n" , t);
        for(int i=0; i<N; ++i)
        printf("%.9f\n", 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i]);
    }
    return 0;
}
