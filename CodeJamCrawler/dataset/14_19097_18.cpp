#include<stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    int t,i,j;
    for(t=1;t<=T;t++)
    {
        int A,B,K;
        scanf("%d%d%d", &A, &B, &K);
        int ans=0;
        for(i=0;i<A;i++)
            for(j=0;j<B;j++)
                if((i&j)<K)
                    ans++;
        printf("Case #%d: %d\n", t,ans);
    }
    return 0;
}
