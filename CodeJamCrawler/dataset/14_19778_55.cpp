#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>


using namespace std;

#define MAX 1000

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("deceit.txt", "w", stdout);

    int t;
    scanf("%d",&t);
    int i,j,k,n,count1,count2,l;
    double A[MAX],B[MAX];
    for(i = 1;i <= t;i++)
    {
        count1 = 0;
        count2 = 0;
        scanf("%d",&n);
        for(j = 0;j < n;j++)
        {
            scanf("%lf",&A[j]);
        }
        sort(A,A+n);
         for(j = 0;j < n;j++)
        {
            scanf("%lf",&B[j]);
        }
        sort(B,B+n);
        k = 0;
        for(j = 0;j < n;j++)
        {
            if(A[j] > B[k])
            {
                 count1++;
                 k++;
            }

        }
        k = n-1;
        for(j = n-1;j>=0;j--)
        {
            if(A[j] > B[k])
            {
                count2++;
                l++;
            }
            else
                k--;

        }
        printf("case #%d: %d %d\n",i,count1,count2);


    }
}
