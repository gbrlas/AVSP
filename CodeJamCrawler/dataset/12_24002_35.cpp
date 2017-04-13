#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool used[255];

int main() {
    freopen("input2.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    char tr[255];

    tr['e']='o';
    tr['j']='u';
    tr['p']='r';
    tr[' ']=' ';
    tr['m']='l';
    tr['y']='a';
    tr['s']='n';
    tr['l']='g';
    tr['c']='e';
    tr['k']='i';
    tr['d']='s';
    tr['x']='m';
    tr['v']='p';
    tr['n']='b';
    tr['r']='t';
    tr['i']='d';
    tr['b']='h';
    tr['t']='w';
    tr['a']='y';
    tr['h']='x';
    tr['w']='f';
    tr['f']='c';
    tr['o']='k';
    tr['u']='j';
    tr['g']='v';
    tr['q']='z';
    tr['z']='q';

    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        char s[500];
        gets(s);
        for (int j = 0; j < strlen(s); j++) {
            s[j] = tr[s[j]];
        }
        printf("Case #%d: %s\n", i+1, s);
    }


    return 0;
}
