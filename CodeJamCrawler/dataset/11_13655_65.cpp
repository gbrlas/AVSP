#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int C = 1005;
const int N = 1000005;

int a[C];
int val[N];
int b[N];

int main()
{
    //freopen("B-small-attempt0 (3).in", "r", stdin);
    //freopen("B-small-attempt0 (3).out", "w", stdout);
    int ca;
    scanf("%d",&ca);
    int cas = 0;
    while (ca--)
    {
        int l, n, c;
        long long t;
		scanf("%d%lld%d%d", &l, &t, &n, &c);
		int i;
        for (i = 0; i < c; i++)
        {
        	scanf("%d",&a[i]);
		}
        for(i = 0; i < n; i++)
        {
        	val[i] = a[i % c];
		}
        long long sum = 0;
        int flag = -1;
        for (i = 0; i < n; i++)
        {
            sum += val[i] * 2;
            if (sum >= t) 
			{
				flag = i;
				break;
			}
        }
        int tmp = i;
        if (flag == -1)
        {
			printf("Case #%d: %lld\n", ++cas, sum);
            continue;
        }
        val[i] = ((int) (sum - t)) / 2;
        for (int k = i; k < n; k++)
        {
        	b[k - i] = val[k];
		}
        sort(b, b + n - i, greater<int>());
        for (int k = i; k < n; k++)
        {
        	val[k] = b[k - i];
		}
        long long res = t;
        for (int j = tmp; j < n; j++)
        {
            if (l > 0)
            {
				res += val[j];
				l--;
            }
            else 
			{
				res += val[j] * 2;
			}
        }
        printf("Case #%d: %lld\n", ++cas, res);
    }
    return 0;
}
