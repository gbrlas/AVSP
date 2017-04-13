#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

long long a[1000], b[1000];

int main()
{
    int cas;
    scanf("%d", &cas);
    for (int c = 1; c <= cas; ++c)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%I64d", a + i);
        }   
        for (int i = 0; i < n; ++i)
        {
            scanf("%I64d", b + i);   
        }
        sort(a, a + n);
        sort(b, b + n, greater<long long>());
        long long res = 0;
        for (int i = 0; i < n; ++i)
            res += a[i] * b[i];
        printf("Case #%d: %I64d\n", c, res); 
    }
    return 0;    
}
