#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char mp[30];

int main()
{
    mp['e'-'a'] = 'o';
    mp['j'-'a'] = 'u';
    mp['p'-'a'] = 'r';
    mp['m'-'a'] = 'l';
    mp['y'-'a'] = 'a';
    mp['s'-'a'] = 'n';
    mp['l'-'a'] = 'g';
    mp['j'-'a'] = 'u';
    mp['y'-'a'] = 'a';
    mp['l'-'a'] = 'g';
    mp['c'-'a'] = 'e';
    mp['k'-'a'] = 'i';
    mp['d'-'a'] = 's';
    mp['k'-'a'] = 'i';
    mp['x'-'a'] = 'm';
    mp['v'-'a'] = 'p';
    mp['e'-'a'] = 'o';
    mp['d'-'a'] = 's';
    mp['d'-'a'] = 's';
    mp['k'-'a'] = 'i';
    mp['n'-'a'] = 'b';
    mp['m'-'a'] = 'l';
    mp['c'-'a'] = 'e';
    mp['r'-'a'] = 't';
    mp['e'-'a'] = 'o';
    mp['j'-'a'] = 'u';
    mp['s'-'a'] = 'n';
    mp['i'-'a'] = 'd';
    mp['c'-'a'] = 'e';
    mp['p'-'a'] = 'r';
    mp['d'-'a'] = 's';
    mp['r'-'a'] = 't';
    mp['y'-'a'] = 'a';
    mp['s'-'a'] = 'n';
    mp['i'-'a'] = 'd';
    mp['r'-'a'] = 't';
    mp['b'-'a'] = 'h';
    mp['c'-'a'] = 'e';
    mp['p'-'a'] = 'r';
    mp['c'-'a'] = 'e';
    mp['y'-'a'] = 'a';
    mp['p'-'a'] = 'r';
    mp['c'-'a'] = 'e';
    mp['r'-'a'] = 't';
    mp['t'-'a'] = 'w';
    mp['c'-'a'] = 'e';
    mp['s'-'a'] = 'n';
    mp['r'-'a'] = 't';
    mp['a'-'a'] = 'y';
    mp['d'-'a'] = 's';
    mp['k'-'a'] = 'i';
    mp['h'-'a'] = 'x';
    mp['w'-'a'] = 'f';
    mp['y'-'a'] = 'a';
    mp['f'-'a'] = 'c';
    mp['r'-'a'] = 't';
    mp['e'-'a'] = 'o';
    mp['p'-'a'] = 'r';
    mp['k'-'a'] = 'i';
    mp['y'-'a'] = 'a';
    mp['m'-'a'] = 'l';
    mp['v'-'a'] = 'p';
    mp['e'-'a'] = 'o';
    mp['d'-'a'] = 's';
    mp['d'-'a'] = 's';
    mp['k'-'a'] = 'i';
    mp['n'-'a'] = 'b';
    mp['k'-'a'] = 'i';
    mp['m'-'a'] = 'l';
    mp['k'-'a'] = 'i';
    mp['r'-'a'] = 't';
    mp['k'-'a'] = 'i';
    mp['c'-'a'] = 'e';
    mp['d'-'a'] = 's';
    mp['d'-'a'] = 's';
    mp['e'-'a'] = 'o';
    mp['k'-'a'] = 'i';
    mp['r'-'a'] = 't';
    mp['k'-'a'] = 'i';
    mp['d'-'a'] = 's';
    mp['e'-'a'] = 'o';
    mp['o'-'a'] = 'k';
    mp['y'-'a'] = 'a';
    mp['a'-'a'] = 'y';
    mp['k'-'a'] = 'i';
    mp['w'-'a'] = 'f';
    mp['a'-'a'] = 'y';
    mp['e'-'a'] = 'o';
    mp['j'-'a'] = 'u';
    mp['t'-'a'] = 'w';
    mp['y'-'a'] = 'a';
    mp['s'-'a'] = 'n';
    mp['r'-'a'] = 't';
    mp['r'-'a'] = 't';
    mp['e'-'a'] = 'o';
    mp['u'-'a'] = 'j';
    mp['j'-'a'] = 'u';
    mp['d'-'a'] = 's';
    mp['r'-'a'] = 't';
    mp['l'-'a'] = 'g';
    mp['k'-'a'] = 'i';
    mp['g'-'a'] = 'v';
    mp['c'-'a'] = 'e';
    mp['j'-'a'] = 'u';
    mp['v'-'a'] = 'p';
    mp['q'-'a'] = 'z';
    mp['z'-'a'] = 'q';
    int cas;
    char google[200];
    scanf("%d\n",&cas);
    for(int ii = 1; ii <= cas; ii++)
    {
        printf("Case #%d: ",ii);
        gets(google);
        for(int i = 0; google[i]; i++)
        {
            if(google[i] != ' ')
                putchar(mp[google[i]-'a']);
            else printf(" ");
        }
        puts("");
    }
    return 0;
}
