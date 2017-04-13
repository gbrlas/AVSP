#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    for(int kase = 1; kase <= t; ++kase) {
        char line[256];
        scanf("%s", line);
        int n = strlen(line);
        printf("Case #%d: ", kase);
        if (!next_permutation(line, line + n)) {
            int p;
            for (int i = 0; i <n; ++i) {
                if (line[i] != '0') {
                    p = i;
                    break;
                }
            }
            putchar(line[p]);
            putchar('0');
            for (int i = 0; i < p; ++i) putchar(line[i]);
            for (int i = p + 1; i < n; ++i) putchar(line[i]);
            puts("");
        } else {
            puts(line);
        }
    }
    return 0;
}
