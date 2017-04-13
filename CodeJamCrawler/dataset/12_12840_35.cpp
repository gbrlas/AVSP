#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int t, i;
    scanf(" %d", &t);
    for(i=1; i<=t; i++){
        int n, s, p, d, j, r=0;
        scanf(" %d %d %d", &n, &s, &p);
        for(j=0; j<n; j++){
            int f=3*p-2;
            scanf(" %d", &d);
            if(d >= f) r++;
            else if(p>1 && s && d >= f-2) {
                s--;
                r++;
            }
        }
        if(p==0) r=n;
        printf("Case #%d: %d\n", i, r);
    }
    return 0;
}
