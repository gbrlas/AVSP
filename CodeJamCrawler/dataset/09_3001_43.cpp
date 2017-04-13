#include <iostream>
#include <vector>
#include <list>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

static const char jam[] = "welcome to code jam";
static int jam_len = strlen(jam);

int count(const char *s, int len, int s_pos, int pos)
{
    int ans = 0;

    if (pos == jam_len)
        return 1;
    
    int tmp = len - jam_len + pos;
    for (int i=s_pos; i<tmp; ++i)
    {
        if (s[i] == jam[pos])
        {
            ans += count(s, len, i+1, pos+1);
            ans %= 10000;
        }
    }

    return ans;
}

int main(void)
{
    FILE *in, *out;

    in = fopen("C-small.in", "r");
    out = fopen("C-small.out", "w");

    int n;
    char tmp[501];

    fscanf(in, "%d\n", &n);

    for (int i=0; i<n; ++i)
    {
        fgets(tmp, 500, in);

        int ans = count(tmp, strlen(tmp), 0, 0);

        printf("%s\n", tmp);
        printf("Case #%d: %04d\n", i+1, ans);
        fprintf(out, "Case #%d: %04d\n", i+1, ans);
    }

    return 0;
}
