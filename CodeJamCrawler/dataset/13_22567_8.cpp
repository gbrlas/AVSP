// fas.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>

#define MAX 101

int main()
{
    int t=0, n=0;
    char str[MAX];

    scanf("%d", &t);

    for (int x=0; x<t; ++x)
    {
        scanf("%s%d", str, &n);

        int y=0, len=0;
        len = strlen(str);

        for (int i=n; i<=len; ++i)
        {
            for (int j=0; j<=len-i; ++j)
            {
                int cnt=0;
                for (int k=j; k<j+i; ++k)
                {
                    if (str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u')
                    {
                        if (j+i-1-k < n)
                        {
                            break;
                        }
                        cnt=0;
                        continue;
                    }
                    ++cnt;
                    if (cnt == n)
                    {
                        ++y;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", x+1, y);
    }

	return 0;
}

