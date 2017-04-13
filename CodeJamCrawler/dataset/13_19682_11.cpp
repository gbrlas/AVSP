#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N, num;
float cost, r, t;
#define pai 3.1415926;
int main()
{
	//freopen ("data.in", "r",stdin);
	//freopen ("data.out","w",stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%f%f", &r, &t);
        num = 0;
        r = r-1;
        for (;;)
        {
            cost = ((r+2)*(r+2)-(r+1)*(r+1));
            t -= cost;
            r = r+2;
            if (t < 0) break;
            num++;
        }
        printf("Case #%d: %d\n", i, num);
    }



	return 0;
}
