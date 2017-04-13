#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int getnumdigits(int n) {
    int i;
    int numdigits = 0;
    while (n != 0) {
        n /= 10;
        numdigits += 1;
    }
    return numdigits;
}

int rightrotate(int n, int numdigits) {
    return (n % 10) * (int) pow(10, numdigits - 1)
        + (n / 10);
}

int isused(int *a, int usedcounter, int m) {
    int i;
    for (i = 0; i < usedcounter; i++)
        if (a[i] == m)
            return 1;
    return 0;
}

void main() {
    int t, numdigits;
    int i, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int a, b;
        int n;
        int count = 0;
        scanf("%d %d", &a, &b);
        numdigits = getnumdigits(a);
        for (n = a; n <= b; n++) {
            int m = n;
            int k;
            int *a = (int*) malloc((numdigits-1)*sizeof(int));
            int usedcounter = 0;
            for (k = 0; k < numdigits; k++)
                a[k] = -1;
            for (j = 0; j < numdigits - 1; j++) {
                m = rightrotate(m, numdigits);
                if ((m <= b) && (m > n) && !(isused(a, usedcounter, m))) {
                    count++;
                    a[usedcounter] = m;
                    usedcounter++;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, count);
    }
}
