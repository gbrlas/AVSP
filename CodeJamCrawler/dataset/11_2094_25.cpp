#include <stdio.h>

int min2(int a, int b)
{
    return a<b?a:b;
}

int main()
{
    freopen("C-small-attempt3.in", "r" , stdin);
    freopen("C-small-attempt3.out", "w" , stdout);
    int T,N;
    scanf("%d" , &T);
    int caseN = 0;
    while(T--)
    {
        scanf("%d" , &N);
        int minValue = 999000000;
        int xorSum = 0;
        int sum = 0;
        int tmp;
        for(int i=0; i<N; ++i)
        {
            scanf("%d" , &tmp);
            xorSum^=tmp;
            sum+=tmp;
            minValue = min2(tmp, minValue);
        }
        printf("Case #%d: ", ++caseN);
        if(xorSum) printf("NO\n");
        else printf("%d\n" , sum - minValue);
    }
    return 0;
}
