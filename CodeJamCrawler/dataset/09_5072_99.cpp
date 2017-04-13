#include <stdio.h>
#include <assert.h>

int dp[19];
char cent[502];

void count()
{
    int i,j;
    for (i=0; i<19; i++)
    {
        dp[i] = 0;
    }
    i=0;
    for (j=0; cent[j] != 0; j++)
    {
        i++;
    }
    for (j=i; j>=0; j--)
    {
        switch(cent[j])
        {
        case 'w':
            dp[0] += dp[1];
            if (dp[0] > 9999)
                dp[0] -= 10000;
            break;
        case 'e':
            dp[1] += dp[2];
            if (dp[1] > 9999)
                dp[1] -= 10000;
            dp[6] += dp[7];
            if (dp[6] > 9999)
                dp[6] -= 10000;
            dp[14] += dp[15];
            if (dp[14] > 9999)
                dp[14] -= 10000;
            break;
        case 'l':
            dp[2] += dp[3];
            if (dp[2] > 9999)
                dp[2] -= 10000;
            break;
        case 'c':
            dp[3] += dp[4];
            if (dp[3] > 9999)
                dp[3] -= 10000;
            dp[11] += dp[12];
            if (dp[11] > 9999)
                dp[11] -= 10000;
            break;
        case 'o':
            dp[4] += dp[5];
            if (dp[4] > 9999)
                dp[4] -= 10000;
            dp[9] += dp[10];
            if (dp[9] > 9999)
                dp[9] -= 10000;
            dp[12] += dp[13];
            if (dp[12] > 9999)
                dp[12] -= 10000;
            break;
        case 'm':
            dp[5] += dp[6];
            if (dp[5] > 9999)
                dp[5] -= 10000;
            dp[18] += 1;
            if (dp[18] > 9999)
                dp[18] -= 10000;
            break;
        case ' ':
            dp[7] += dp[8];
            if (dp[7] > 9999)
                dp[7] -= 10000;
            dp[10] += dp[11];
            if (dp[10] > 9999)
                dp[10] -= 10000;
            dp[15] += dp[16];
            if (dp[15] > 9999)
                dp[15] -= 10000;
            break;
        case 't':
            dp[8] += dp[9];
            if (dp[8] > 9999)
                dp[8] -= 10000;
            break;
        case 'd':
            dp[13] += dp[14];
            if (dp[13] > 9999)
                dp[13] -= 10000;
            break;
        case 'j':
            dp[16] += dp[17];
            if (dp[16] > 9999)
                dp[16] -= 10000;
            break;
        case 'a':
            dp[17] += dp[18];
            if (dp[17] > 9999)
                dp[17] -= 10000;
            break;
        }
    }
}

int main()
{
    int T;
    int i;
    scanf("%d\n", &T);
    for (i=1; i<=T; i++)
    {
        gets(cent);
        count();
        printf("Case #%d: %04d\n", i, dp[0]);
    }
    printf("\n");
    return 0;
}
