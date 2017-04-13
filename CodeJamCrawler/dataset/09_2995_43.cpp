#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    FILE *in, *out;
    int l, d, n, i, j, ans = 0;

    in = fopen("A-large.in", "r");
    out = fopen("A-large.out", "w");

    fscanf(in, "%d %d %d", &l, &d, &n);

    char words[5000][16];

    for (i=0; i<d; ++i)
        fscanf(in, "%s", words[i]);

    char tmp[5000];

    unsigned int f[5000];
    unsigned flag = (1<<l) - 1;

    for (i=0; i<n; ++i)
    {
        ans = 0;
        memset(f, 0, sizeof(f[0])*5000);
        fscanf(in, "%s", tmp);

        int k = 0;
        bool p = false;
        for (j=0, k=0; k<l; ++j)
        {
            if (tmp[j] == '(')
                p = true;
            else if (tmp[j] == ')')
            {
                p = false;
                ++k;
            }
            else 
            {
                for (int h=0; h<d; ++h)
                {
                    if (words[h][k] == tmp[j])
                        f[h] |= 1<<k;
                }
                if (p == false)
                    ++k;
            }
        }

        for (j=0; j<d; ++j)
            if (f[j] == flag)
                ++ans;
        
        fprintf(out, "Case #%d: %d\n", i+1, ans);
    }

    return 0;
}
