#include <stdio.h>
#include <string.h>
#include <math.h>
long long int in[100], count;
int n, l;

void counter( int cnt, long long int sym, long long int prev, long long int cur) {

    if( cnt == l) {
        long long int val, val2;

        if(sym == 0)
            val = prev+cur;
        else
            val = prev-cur;

        if(val < 0)
            val *= -1;

        //printf(" %lld\n", val);
        if( val == 0 || val%2 == 0 || val%3 == 0 || val%5 == 0 || val%7 == 0)
            count++;

        return;
    } else {
        long long int newp, newc;

        // case 0 none
        newc = cur*10+in[cnt];

        counter(cnt+1, sym, prev, newc);

        // case 1 +
        if(sym == 0)
            newp = prev+cur;
        else
            newp = prev-cur;

        newc =  in[cnt];

        counter(cnt+1, 0, newp, newc);

        // case 2 -
        counter(cnt+1, 1, newp, newc);

    }
}


main() {

    char str[100];
    int val;

    scanf(" %d", &n);

    for(int i=0; i<n; i++) {
        scanf(" %s", str);

        l = strlen(str);

        for(int j=0; j<l ; j++) {
            in[j] = str[j] - '0';
        }

        count = 0;

        counter(0, 0, 0, 0);

        printf("Case #%d: %d\n", i+1, count/3);
        
    }
}
