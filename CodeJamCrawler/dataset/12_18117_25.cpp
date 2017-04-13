#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int n, s, p, t, a, b;

string digits(int x)
{
    string s;
    while(x)
    {
        s.push_back(x%10 + '0');
        x /= 10;
    }
    return s;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &t);

    for (int cases = 1; cases <= t; cases++)
    {
        int res = 0;
        scanf("%d %d", &a, &b);

        for (int i = a; i <= b; i++)
            for (int j = i+1; j <= b; j++)
            {
                string s1 = digits(i), s2 = digits(j);
                s1 = s1 + s1;
              
                if (s1.find(s2)!=string::npos)
                    res++;

                

            }


        printf("Case #%d: %d\n", cases, res);
    }

    return 0;
}
