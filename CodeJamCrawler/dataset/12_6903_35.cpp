#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

const int n = 256;
char map[n];

char str[200];

int main() {
    for (int i = 0; i < n; i++) {
        map[i] = 0;
    }
    map[(int)'z'] = 'q';
    map[(int)'q'] = 'z';
    map[(int)' '] = ' ';
    string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != ' ') {
            map[(int)a[i]] = b[i];
        }
    }
    freopen ("a.in", "rt", stdin);
    freopen ("a.out", "wt", stdout);
    /*
    for (int i = 'a'; i <= 'z'; i++) {
        printf("%c:%c\n", i, map[i]);
    }
    */
    int T;
    scanf ("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        gets (str);
        int m = strlen(str);
        for (int i = 0; i < m; i++) {
            printf("%c", map[str[i]]);
        }
        printf ("\n");
    }
}
