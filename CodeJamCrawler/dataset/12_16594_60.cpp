#include <cstdio>

int tr[256];
int T;

int main() {
    int i, j;
    char s[1000];
tr['a'] = 'y';
tr['b'] = 'h';
tr['c'] = 'e';
tr['d'] = 's';
tr['e'] = 'o';
tr['f'] = 'c';
tr['g'] = 'v';
tr['h'] = 'x';
tr['i'] = 'd';
tr['j'] = 'u';
tr['k'] = 'i';
tr['l'] = 'g';
tr['m'] = 'l';
tr['n'] = 'b';
tr['o'] = 'k';
tr['p'] = 'r';
tr['q'] = 'z';
tr['r'] = 't';
tr['s'] = 'n';
tr['t'] = 'w';
tr['u'] = 'j';
tr['v'] = 'p';
tr['w'] = 'f';
tr['x'] = 'm';
tr['y'] = 'a';
tr['z'] = 'q';
tr[' '] = ' ';

    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        gets(s);
        for (i = 0; s[i]; i++) s[i] = tr[s[i]];
        printf("Case #%d: %s\n", t, s);
    }
    return 0;
}


    


