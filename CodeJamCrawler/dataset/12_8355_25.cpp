#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int d[100];
int main() {
        d['y'] = 'a';
        d['n'] = 'b';
        d['f'] = 'c';
        d['i'] = 'd';
        d['c'] = 'e';
        d['w'] = 'f';
        d['l'] = 'g';
        d['b'] = 'h';
        d['k'] = 'i';
        d['u'] = 'j';
        d['o'] = 'k';
        d['m'] = 'l';
        d['x'] = 'm';
        d['s'] = 'n';
        d['e'] = 'o';
        d['v'] = 'p';
        d['z'] = 'q'; // f or q
        d['p'] = 'r';
        d['d'] = 's';
        d['r'] = 't';
        d['j'] = 'u';
        d['g'] = 'v';
        d['t'] = 'w';
        d['h'] = 'x';
        d['a'] = 'y';
        d['q'] = 'z'; // f or q
        int a;
        string b;
        scanf("%d\n",&a);
        for (int x=1; x<=a; x++) {
                printf("Case #%d: ",x);
                getline(cin,b);
                for (int i=0; i<(int)b.size(); i++) {
                	if ('a' <= b[i] && b[i] <= 'z') {
                        	b[i] = d[b[i]];
                        }
                        cout << b[i];
                }
                cout << endl;
        }
 
        return 0;
}