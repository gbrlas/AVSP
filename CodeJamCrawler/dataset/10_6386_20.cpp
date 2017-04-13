#include <iostream.h>
#include <math.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#define N 100000

struct snapper {
    int power;
    int on;
} a [12];

void reset (int n)
{
    for ( int i = 0; i < n; i++ ) {
        a [i].power = 0;
        a [i].on = 0;
    }
    a [0].power = 1;
}

int main ()
{
    freopen ("A-small.in", "r", stdin);
    freopen ("A-small-attempt1.out", "w", stdout);

    int T;
    scanf ("%d", &T);
    int cases = 0;

    while ( T-- ) {
        int n;
        int k;
        scanf ("%d %d", &n, &k);

        reset (n);

        for ( int i = 0; i < k; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( a [j].power )
                    a [j].on = a [j].on ? 0 : 1;
            }
	    for ( j = 0; j < n; j++ ) {
                if ( a [j].power && a [j].on )
                    a [j + 1].power = 1;
                else
                    a [j + 1].power = 0;
            }
        }

        if ( a [n - 1].power && a [n - 1].on )
            printf ("Case #%d: ON\n", ++cases);
        else
            printf ("Case #%d: OFF\n", ++cases);
    }

    return 0;
}
