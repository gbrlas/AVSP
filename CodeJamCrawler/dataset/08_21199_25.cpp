#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int C, s, q, tab[1010], mem[110][1010];
map<string, int>  M;
char buff[1000];

int cnt(int last, int step)
{
    int &r = mem[last][step];
    if (r == -1)
    {
        if (step == q)
            r = 0;
        else if (last != tab[step])
            r = cnt(last, step + 1);
        else
        {            
            r = 0x7fffffff;
            for (int i = 0; i < s; ++i)
                if (i != last)
                    r = min(r, cnt(i, step + 1));
            ++r;
        }
    }
    return r;   
}

int main()
{
    scanf("%d\n", &C);
    for (int c = 0; c < C; ++c)
    {
        memset(mem, -1, sizeof(mem));
        M.clear();
        scanf("%d\n", &s);   
        for (int i = 0; i < s; ++i)
        {
            gets(buff);
            M[buff] = i;
        }
        scanf("%d\n", &q);
        for (int i = 0; i < q; ++i)
        {
            gets(buff);
            tab[i] = M[buff];
        }
        int res = 0x7fffffff;
        for (int i = 0; i < s; ++i)
            res = min(res, cnt(i, 0));
            
        printf("Case #%d: %d\n", c + 1, res);
    }
    return 0;
}
