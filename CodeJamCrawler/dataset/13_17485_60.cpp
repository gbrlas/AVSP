#include <stdio.h>
#include <math.h>

int ifpalin(int n)
{
    int m = n;
    int n2 = 0;
    int k;
    
    while (m>0)
    {
        n2 *= 10;
        k = m%10;
        n2 += k;
        m /= 10;
    }
    
    if (n2 == n)
        return 1;
    
    return 0;
}

int foo(int n)
{
    int root = sqrt(n);
    
    if (root*root != n)
        return 0;
    
    if (ifpalin(n) == 1 && ifpalin(root) == 1)
        return 1;
       
    return 0;
}

int main()
{
    int t, a, b, count, k = 0, i;
    
    scanf("%d", &t);
    
    while(t--)
    {
        count = 0;
        k++;
        scanf("%d%d", &a, &b);
        
        for (i = a; i<=b; i++)
        {
            if (foo(i) == 1)
                count++;
        }
        
        printf("Case #%d: %d\n", k, count);
    }
    
    return 0;
}
