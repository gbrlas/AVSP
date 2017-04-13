#include <stdio.h>
#include <math.h>

int ispalindrome(long long int);

int main()
 {
    int T, i, count = 0;
    long long int A, B, cur;
    scanf("%d", &T);
    if(T < 1 || T > 10000)
        return 1;
    for(i = 0; i < T; i++) 
     {   
        count = 0;
        scanf("%lld%lld", &A, &B);
        if(A < 1 || A > 100000000000000)
            continue;
        if(B < 1 || B > 100000000000000)
            continue;
        cur = (long long int)sqrt(A);
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

int ispalindrome(long long int n)
 {
    long long int m, num = 0;
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
