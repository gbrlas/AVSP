#include <math.h>
#include <stdio.h>

main () {
    
    int t, n, k, power;

     scanf(" %d", &t);

    for(int i=0; i<t; i++) {
        scanf(" %d %d", &n, &k);

        power = (int) pow(2, n);

        while(k > power) {
            k -= power;
        }

        if( k == power-1) {
            printf("Case #%d: ON\n", i+1);
        } else {
            printf("Case #%d: OFF\n", i+1);
        }
    }
}
