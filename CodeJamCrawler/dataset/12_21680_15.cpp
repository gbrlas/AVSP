#include <stdio.h>
#include <string.h>
#include <string>
#include <assert.h>
using namespace std;

char str[256];
char mapping[26];

char* inp = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char* out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int getline(char* s) {
    int pos = 0;
    char c;
    while((c = getchar()) != '\n')
        s[pos++] = c;
    return pos;
}

int main() {
    // freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(mapping, 0, sizeof(mapping));

    for(int i = 0; i < strlen(inp); ++i) {
        if(inp[i] != ' ') {
            char c = inp[i];
            char mapto = out[i];
            if(mapping[c - 'a'] != 0 && mapto != mapping[c - 'a'])
                assert(0);
            mapping[c - 'a'] = mapto;
        }
    }
    mapping['z' - 'a'] = 'q';
    //for(int i = 0; i < 26; ++i)
        // if(mapping[i] == 0) 
            //printf("Mapping for %c is %c\n", i + 'a', mapping[i]);

    int T;
    getline(str);
    sscanf(str, "%d", &T);
    for(int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int n = getline(str);
        for(int i = 0; i < n; ++i)
            if(str[i] == ' ')
                putchar(' ');
            else
                putchar(mapping[str[i] - 'a']);
        putchar('\n');
    }


    return 0;
}