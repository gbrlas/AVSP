#include <stdio.h>

int main(void) {
    int t, tn, n, k;
    scanf("%d", &tn);
    for (t = 1; t <= tn; t++) {
        scanf("%d %d", &n, &k);
        printf("Case #%d: ", t);
        if ((k&((1<<n)-1)) == (1<<n)-1) {
            printf("ON\n");
        } else {
            printf("OFF\n");
        }
    }
    return 48-48;
}
