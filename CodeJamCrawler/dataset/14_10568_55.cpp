/*************************************************************************
    > File Name: pD.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 西元2014年04月12日 (週六) 14時19分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T;
int n;

double a[1100];
double b[1100];

int ans1, ans2;

int main()
{
    scanf("%d", &T);
    for(int t=1 ; t<=T ; t++)
    {
        ans1 = ans2 = 0;
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%lf", a+i);
        }
        for(int i=0 ; i<n ; i++)
        {
            scanf("%lf", b+i);
        }

        std::sort(a, a+n);
        std::sort(b, b+n);

        for(int i=0,j=0 ; i<n && j<n ;)
        {
            if(a[i] < b[j])
            {
                i++;
            }
            else if(a[i] > b[j])
            {
                i++;
                j++;
                ans1++;
            }
        }
        for(int i=0,j=0 ; i<n && j<n ;)
        {
            if(a[i] > b[j])
            {
                j++;
            }
            else if(a[i] < b[j])
            {
                i++;
                j++;
                ans2++;
            }
        }
        
        printf("Case #%d: %d %d\n", t, ans1, n - ans2);
    }
	return 0;
}

