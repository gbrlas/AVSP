#include <stdio.h>
#include <string.h>

char map[27] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[10000000];
int main() {
    freopen("input", "r", stdin);
    int T;
    scanf("%d\n", &T);
    for (int i = 0; i < T; i++) {
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        printf("Case #%d: ", i + 1);
        for (int j = 0; j < len; j++) {
            if (s[j] == '\n' 
                    || s[j] == '\r') 
                continue;
            if (s[j] == ' ') printf(" ");
            else printf("%c", map[s[j] - 'a']);
        }
        printf("\n");
    }
    return 0;
}



















