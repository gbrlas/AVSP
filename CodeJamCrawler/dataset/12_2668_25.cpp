#include <stdio.h>
#include <string.h>

#include <map>
using std :: map;

map<char, char> table;


const int MAX_STR_SIZE = 110;

inline void decode (char str[])
{
    int len = strlen (str);
    for (int i = 0; i < len; ++i)
        str[i] = table[str[i]];
}

int main ()
{
    freopen ("inp.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    table['y'] = 'a';
table['n'] = 'b';
table['f'] = 'c';
table['i'] = 'd';
table['c'] = 'e';
table['w'] = 'f';
table['l'] = 'g';
table['b'] = 'h';
table['k'] = 'i';
table['u'] = 'j';
table['o'] = 'k';
table['m'] = 'l';
table['x'] = 'm';
table['s'] = 'n';
table['e'] = 'o';
table['v'] = 'p';
table['z'] = 'q';
table['p'] = 'r';
table['d'] = 's';
table['r'] = 't';
table['j'] = 'u';
table['g'] = 'v';
table['t'] = 'w';
table['h'] = 'x';
table['a'] = 'y';
table['q'] = 'z';
table[' '] = ' ';
    int all_string;
    scanf ("%d\n", &all_string);
    char str[MAX_STR_SIZE] = {};
    int c_id = 1;
    for (int i = 0; i < all_string; ++i)
    {
        fgets (str, MAX_STR_SIZE, stdin);
        decode (str);
        printf ("Case #%d: %s\n", c_id, str);
        ++c_id;
    }
    
    getchar ();
    getchar ();
    
    return 0;
}
