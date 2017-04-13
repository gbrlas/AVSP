// fas.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    //const long double PI = 3.141592653589793238;
    int T=0, x=0, y=0;
    double r=0, t=0;

    scanf("%d", &T);

    for (x=0; x<T; ++x)
    {
        y=0;
        scanf("%lf%lf", &r, &t);

        for (int i=1; ; i+=2)
        {
            t = t-( (r+i)*(r+i)-(r+i-1)*(r+i-1) );
            if (t>0)
            {
                ++y;
            }
            else if (t==0)
            {
                ++y;
                break;
            }
            else
            {
                break;
            }
        }

        printf("Case #%d: %d\n", x+1, y);
    }

	return 0;
}
