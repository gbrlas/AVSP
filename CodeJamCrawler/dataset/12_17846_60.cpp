#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

int main( )
{
	char trans[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	int t,i;
	char c;
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	scanf("%d\n",&t);
	for(i = 1; i <= t; ++i)
	{
		printf("Case #%d: ",i);
		while ((c = getchar()) != '\n' && c != EOF)
		{
			if (c == ' ')
			{
				printf(" ");
			}
			else
				printf("%c",trans[c-'a']);
		}
		printf("\n");
	}
	
	return 0;
}
