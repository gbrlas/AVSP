#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#define AND &&
#define OR ||
#define inf ( 1 << 30 );
using namespace std;
const double pi = 2 * acos (0.0);
const double eps = 1e-11;

map < char, char > m;
void init ();

char buffer [200];

int main() {

	//freopen ("A-small-attempt0.in","r",stdin);
	//freopen ("output.txt","w",stdout);

	init();

	int kase, count = 0;

	scanf ( "%d", &kase );
	gets ( buffer );

	int i;
	while ( kase-- )
	{
	    printf ( "Case #%d: ", ++count );

	    gets ( buffer );
	    for ( i = 0; buffer[i]; i++ )
	    {
	        char c = buffer[i];
	        if ( isalpha ( c ) )
	        {
	            printf ( "%c", m[c] );
	        }
	        else printf ( "%c", c );
	    }
	    printf ( "\n" );
	}

	return 0;
}

void init ()
{
    m['a'] = 'y';
    m['b'] = 'h';
    m['c'] = 'e';
    m['d'] = 's';
    m['e'] = 'o';
    m['f'] = 'c';
    m['g'] = 'v';
    m['h'] = 'x';
    m['i'] = 'd';
    m['j'] = 'u';
    m['k'] = 'i';
    m['l'] = 'g';
    m['m'] = 'l';
    m['n'] = 'b';
    m['o'] = 'k';
    m['p'] = 'r';
    m['q'] = 'z';
    m['r'] = 't';
    m['s'] = 'n';
    m['t'] = 'w';
    m['u'] = 'j';
    m['v'] = 'p';
    m['w'] = 'f';
    m['x'] = 'm';
    m['y'] = 'a';
    m['z'] = 'q';
}
