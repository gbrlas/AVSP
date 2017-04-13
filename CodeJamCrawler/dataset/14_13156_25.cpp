#include <stdio.h>
int main()
{
    int t , k ;
    double c , f , x ;
    double nowtime , nowneedtime , nowk , nextneedtime , nextk ;
    freopen("r1.txt","r",stdin);
    freopen("w1.txt","w",stdout);
    scanf("%d", &t);
    for(k = 1 ; k <= t ; k++)
    {
        scanf("%lf %lf %lf", &c , &f , &x);
        nowtime = 0 ;
        nowk = 2 ;
        nowneedtime = x / nowk ;
        while(1)
        {
            nextk = nowk + f ;
            nextneedtime = c / nowk + x / nextk ;
            if(nextneedtime > nowneedtime)
                break;
            else
            {
                nowtime += (c / nowk) ;
                nowneedtime = nextneedtime - (c/nowk) ;
                 nowk = nextk ;
            }
        }
        printf("Case #%d: %.7lf\n", k , nowtime+nowneedtime) ;
    }
}
