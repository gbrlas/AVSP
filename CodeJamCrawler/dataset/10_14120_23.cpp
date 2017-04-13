#include <cstdio>
#include <algorithm>

using namespace std;

struct xx
{
    int x, y, id;
    bool operator < (const xx aa)const{
        if(x != aa.x) return x < aa.x;
        return y < aa.y;
    }
}kk[1024*1024];
bool g[1024][1024];
int gcd(int aa, int bb)
{
    if(!aa || !bb) return aa + bb;
    if(aa > bb) return gcd(aa % bb, bb);
    else return gcd(aa, bb % aa);
}
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, t, a[1024], b[1024], n, res;
    int i, j, k;
    scanf("%d", &testcases);
    for(t = 1; t <= testcases; t++)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
        memset(g, 0, sizeof(g));
        res = 0;
        for(i = 0; i < n; i++)
        {
            k = 0;
            for(j = 0; j < n; j++)
            {
                if(j == i) continue;
                int tempa = a[i] - a[j], tempb = b[i] - b[j], tempk;
                if(tempa * tempb > 0) continue;
                //printf("---%d %d\n", tempa, tempb);
                tempa = tempa > 0 ? tempa : -tempa;
                tempb = tempb > 0 ? tempb : -tempb;
                tempk = gcd(tempa, tempb);
                kk[k].x = tempa / tempk;
                kk[k].y = tempb / tempk;
                kk[k].id = j;
                k++;
            }
          //  for(j = 0; j < k ; j++)
          //  printf("%d %d\n", kk[j].x, kk[j].y);
          //  printf("\n");
            sort(kk, kk + k);
            if(k) res++, g[i][kk[0].id] = 1;
            for(j = 1; j < k; j++)
            {
                if(i == j) continue;
                if(kk[j - 1].x == kk[j].x && kk[j - 1].y == kk[j].y) continue;
                g[i][kk[j].id] = 1;
                res++;
            }
        }
       // printf("%d\n", res);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(g[i][j] && g[j][i])
                    res--, g[i][j] = g[j][i] = 0;
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
