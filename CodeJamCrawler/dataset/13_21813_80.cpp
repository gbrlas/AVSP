#include <cstdio>
using namespace std;
int i,a,b,t,num,sol;
int is_pal(int nr)
{
    int nr2 = nr;
    int sl=0;
    while(nr > 0)
    {
        sl*=10;
        sl+=nr%10;
        nr/= 10;
    }
    return (nr2 == sl);
}

int get_rad(int nr)
{
    int temp=1;
    while(temp*temp < nr)
    {
        temp ++;
    }
    return(temp);
}
int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    scanf("%i", &t);
    for(i=1;i<=t;i++)
    {
        sol = 0;
        scanf("%i %i", &a,&b);
        while(a<=b)
        {
            if(is_pal(a))
            {
               num = get_rad(a);
               if(num*num == a)
               {
                   if(is_pal(num)) sol++;
               }
            }
            a++;
        }
        printf("Case #%i: %i\n", i, sol);
    }
    return 0;
}
