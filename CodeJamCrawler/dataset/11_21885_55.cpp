#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, temp, o =1, b = 1, r = 0, s = 0, m = 0;
        char c, c_last;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf(" %c %d", &c, &temp);
            if (c == 'O') { // Orange Robot
                if (j && c == c_last) {
                    r = abs(temp - o) + 1;
                    s += r;
                } else {
                    r = ((abs(temp - o) - s > 0) ? (abs(temp - o) - s) : 0) + 1;
                    s = r;
                }
                o = temp;
            } else { // Blue Robot
                if (j && c == c_last) {
                    r = abs(temp - b) + 1;
                    s += r;
                } else {
                    r = ((abs(temp - b) - s > 0) ? (abs(temp - b) - s) : 0) + 1;
                    s = r;
                }
                b = temp;
            }
            m += r;
            c_last = c;
            
            //printf("r=%d s=%d\n", r, s);
            
        }
        printf("Case #%d: %d\n", i + 1, m);
    }
    return 0;
}
