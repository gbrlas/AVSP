#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <bitset>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

static FILE *in, *out;
static void open_file(void);

int main(void)
{
    open_file();

    int ti, t;
    fscanf(in, "%d\n", &t);

    for (ti=1; ti<=t; ++ti)
    {
        char msg[70];
        fscanf(in, "%s", msg);
        int len = strlen(msg);
        int mindif = 0;
        bool asc[256];
        memset(asc, false, sizeof(asc));

        for (int i=0; i<len; ++i)
            asc[msg[i]] = true;;
        for (int i=0; i<256; ++i)
            if (asc[i])
                ++mindif;
        
        int tmp[70];
        int num[50];
        num[0] = 1;
        num[1] = 0;
        for (int i=2; i<mindif; ++i)
            num[i] = i;

        int pos = 0;
        for (int i=0; i<mindif; ++i)
        {
            for (; pos<len; ++pos)
                if (asc[msg[pos]])
                    break;
            asc[msg[pos]] = false;
            for (int j=pos; j<len; ++j)
                if (msg[j] == msg[pos])
                    tmp[j] = num[i];
        }
        
        long long base = 1;
        long long ans = 0;
        if (mindif == 1)
            mindif = 2;
        for (int i=0; i<len; ++i)
        {
            ans += (tmp[len-1-i]) * base;
            base *= mindif;
        }

        printf("Case #%d: %lld\n", ti, ans);
        fprintf(out, "Case #%d: %lld\n", ti, ans);
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
