#include <cstring>
#include <cstdlib>
#include <cstdio>

bool seen[20000005];
int x[20], y = 0;

int main() {

    int T;
    scanf("%d", &T);
    int a, b;
    char s[20];
    for (int t = 1; t <= T; t++) {
        int num = 0;
        scanf("%d %d", &a, &b);
        for (; a < b; a++) {
            sprintf(s, "%d", a);
            int len = strlen(s);
            for (int i = 0; i < len-1; i++) {
                s[i+len] = s[i];
                s[i+len+1] = 0;
                int c = atoi(s+i+1);
                if (c > a && c <= b && !seen[c]) { 
                    num++;
                    seen[c] = true;
                    x[y++] = c;
                }
            }
            while (y) seen[x[--y]] = false;
        }
        printf("Case #%d: %d\n", t, num);
    }
    return 0;
}


