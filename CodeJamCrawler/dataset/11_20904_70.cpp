#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 0x3fffffff;
int n, tmp;

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int cases;
    scanf("%d", &cases);
    int steps = 1;
    while (cases--)
    {
        int minn = INF;
        int sum = 0, t = 0;
        scanf("%d", &n);
        for (int i= 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            t ^= tmp;
            sum += tmp;
            minn = min( minn, tmp );
        }
        printf("Case #%d: ", steps++);
        if ( !t ) printf("%d\n", sum - minn);
        else printf("NO\n");
    }


    return 0;
}
