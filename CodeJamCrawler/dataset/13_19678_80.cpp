#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
int T, A, B;
const int Maxn = 20;
char numstr[Maxn];
int is_pal(int temp)
{
    std::stringstream strs;
    strs << temp;
    strs  >> numstr;
    int len = strlen(numstr);
    int ok = 1;
    for (int i  = 0; i < len; i++)
    {
        if(numstr[i] != numstr[len-1-i]) ok = 0;
    }
    strs.str("");
    return ok;
}
int main()
{
//	freopen ("data.in", "r",stdin);
//	freopen ("data.out","w",stdout);
    scanf("%d", &T);
    for ( int num =1 ; num < T+1; num++)
    {
        scanf("%d %d", &A, &B);
        int front = (int) (sqrt(A) - 0.0000000001) +1;
        int end = (int) (sqrt(B));
        int count = 0;
        for (int i = front; i < end+1; i++)
        {
             if(is_pal(i))
             {
                 int temp = i * i;
                 count += is_pal(temp);
             }

        }
        printf("Case #%d: %d\n", num, count);
    }



	return 0;
}
