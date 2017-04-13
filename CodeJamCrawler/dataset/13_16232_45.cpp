#include <stdio.h>
#include <math.h>

int ispalindrome(int);

int main()
 {
    int T, i, A, B, cur, count = 0;
    scanf("%d", &T);
    if(T < 1 || T > 100)
        return 1;
    for(i = 0; i < T; i++)
     {
        count = 0;
        scanf("%d%d", &A, &B);
        if(A < 1 || A > 1000)
            continue;
        if(B < 1 || B > 1000)
            continue;
        cur = (int)sqrt(A);
        while(cur*cur < A)
            cur ++;
        while(cur*cur <= B)
         {
            if(ispalindrome(cur) && ispalindrome(cur*cur))
                count++;
            cur ++;
         }
        printf("Case #%d: %d\n", i+1, count);
     }
    return 0;
 }

int ispalindrome(int n)
 {
    int i, m, num = 0;
    m = n;
    while(m > 0)
     {
        num = num*10 + m%10;
        m = m / 10;
     }
    if(num == n)
        return 1;
    else
        return 0;
 }
