#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 0x3fffffff;
int n, c, d, tmp;
char data[N];
char C[N][4], D[N][3];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int cases;
    scanf("%d", &cases);
    int steps = 1;
    while (cases--)
    {
        scanf("%d", &c);
        for (int i= 0; i < c; ++i)
        {
            scanf("%s", C[i]);
        }
        scanf("%d", &d);
        d *= 2;
        for (int i = 0; i < d; ++i)
        {
            scanf("%s", D[i]);
            i++;
            D[i][0] = D[i - 1][1];
            D[i][1] = D[i - 1][0];
            D[i][2] = '\0';
        }
        scanf("%d", &n);
        int cnt = 0;
        char in[N];
        scanf("%s", in);
        for ( int i = 0; i < n; ++i)
        {
            data[cnt++] = in[i];
            if ( cnt > 1 )
            {
                bool notc = true;
                for (int j = 0; j < c && notc; ++j)
                {
                    if ( ( data[cnt - 1] == C[j][0] && data[cnt - 2] == C[j][1] )
                        || ( data[cnt - 2] == C[j][0] && data[cnt - 1] == C[j][1] ) )
                        {
                            data[cnt - 2] = C[j][2];
                            cnt--;
                            notc = false;
                        }
                }
                for (int j = 0; j < d && notc; ++j)
                {
                    if ( data[cnt - 1] == D[j][0] )
                    {
                        for (int k = 0; k < cnt - 1; ++k)
                        {
                            if ( data[k] == D[j][1] )
                            {
                                cnt = 0;
                                notc = false;
                            }
                        }
                    }
                }

            }
        }
        printf("Case #%d: ", steps++);
        printf("[");
        for (int i = 0; i < cnt; ++i)
        {
            if ( i ) printf(", ");
            printf("%c", data[i]);
        }
        printf("]\n");
    }


    return 0;
}
