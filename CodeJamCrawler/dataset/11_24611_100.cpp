#include <stdio.h>
#include <cstring>

char m[26][26], c[26][26], u[26], str[200], st[200];

int main() {
    int testnum, n, l;

    scanf("%d", &testnum);
    for (int test = 1;test <= testnum;test++) {
        memset(m, 0xff, sizeof(m));
        memset(c, 0, sizeof(c));
        scanf("%d", &n);
        for (int i = 0;i < n;i++) {
            scanf("%s", str);
            m[str[0] - 'A'][str[1] - 'A'] = str[2];
            m[str[1] - 'A'][str[0] - 'A'] = str[2];
        }
        scanf("%d", &n);
        for (int i = 0;i < n;i++) {
            scanf("%s", str);
            c[str[0] - 'A'][str[1] - 'A'] = 1;
            c[str[1] - 'A'][str[0] - 'A'] = 1;
        }
        scanf("%d%s", &n, str);
        l = 0;
        memset(u, 0, sizeof(u));
        for (int i = 0;i < n;i++) {
            if (l > 0) {
                if (m[st[l - 1] - 'A'][str[i] - 'A'] >= 0) {
                    u[st[l - 1] - 'A']--;
                    st[l - 1] = m[st[l - 1] - 'A'][str[i] - 'A'];
                    u[st[l - 1] - 'A']++;
                } else {
                    for (int j = 0;j < 26;j++) {
                        if (u[j] && c[j][str[i] - 'A']) {
                            l = 0;
                            memset(u, 0, sizeof(u));
                        }
                    }
                    if (l) {
                        st[l++] = str[i];
                        u[str[i] - 'A']++;
                    }
                }
            } else {
                st[l++] = str[i];
                u[str[i] - 'A']++;
            }
        }
        printf("Case #%d: [", test);
        for (int i = 0;i < l;i++) {
            if (i)
                printf(", ");
            printf("%c", st[i]);
        }
        puts("]");
    }
    return 0;
}
