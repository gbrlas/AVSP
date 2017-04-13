#include <stdio.h>
int main()
{
    int t , n , i , k , j , num ;
    int a[4][4] , x[4] , y[4] ;
    freopen("r.txt","r",stdin);
    freopen("w.txt","w",stdout);
    scanf("%d", &t);
    for(k = 1 ; k <= t ; k++)
    {
        scanf("%d", &n);
        for(i = 0 ; i < 4 ; i++)
            for(j = 0 ; j < 4 ; j++)
            {
                if(i == n-1)
                    scanf("%d", &x[j]) ;
                else
                    scanf("%d", &a[i][j]) ;
            }
        scanf("%d", &n);
        for(i = 0 ; i < 4 ; i++)
            for(j = 0 ; j < 4 ; j++)
            {
                if(i == n-1)
                    scanf("%d", &y[j]) ;
                else
                    scanf("%d", &a[i][j]) ;
            }
        num = 0 ;
        for(i = 0 ; i < 4 ; i++)
            for(j = 0 ; j < 4 ; j++)
                if(x[i] == y[j])
                {
                    num++ ;
                    n = x[i] ;
                }
        if(num == 1)
            printf("Case #%d: %d\n", k , n);
        else if(num == 0)
            printf("Case #%d: Volunteer cheated!\n", k);
        else
            printf("Case #%d: Bad magician!\n", k);
    }
    return 0;
}
