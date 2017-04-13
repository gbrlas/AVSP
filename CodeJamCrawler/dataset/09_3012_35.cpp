#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

static FILE *in, *out;
static void open_file(void);

int main(void)
{
    open_file();

    int t, ti;

    fscanf(in, "%d\n", &t);

    for (ti=1; ti<=t; ++ti)
    {
        char ans[30];
        fscanf(in, "%s", ans);
        int len = strlen(ans);
        bool f = false;

        for (int i=len-2; i>=0; --i)
        {
            int j;
            sort(ans+i+1, ans+len);
            for (j=i+1; j<len; ++j)
            {
                if (ans[j] > ans[i])
                {
                    swap(ans[j], ans[i]);
                    sort(ans+i+1, ans+len);
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        if (!f)
        {
            ans[len] = '0';
            ans[len+1] = 0;
            sort(ans, ans+len+1);
            for (int i=0; i<=len; ++i)
                if (ans[i] != '0')
                {
                    swap(ans[i], ans[0]);
                    break;
                }
        }

        printf("Case #%d: %s\n", ti, ans);
        fprintf(out, "Case #%d: %s\n", ti, ans);
    }

    return 0;
}

/* open in and out file for solution */
static void open_file(void)
{
    char filename[32], infile[32], outfile[32];

    scanf("%s", filename);

    strcpy(infile, filename);
    strcpy(outfile, filename);
    strcat(infile, ".in");
    strcat(outfile, ".out");

    in = fopen(infile, "r");
    out = fopen(outfile, "w");
}
