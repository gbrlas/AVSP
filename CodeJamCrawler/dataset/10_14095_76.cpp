#include <cstdio>
#include <algorithm>

using namespace std;
struct xx
{
    int n, k, id, res;
}in[10010];

bool cmp1(xx a, xx b)
{
    if(a.k != b.k) return a.k < b.k;
    return a.n < b.n;
}
bool cmp2(xx a, xx b)
{
    return a.id < b.id;
}
int main()
{
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, i, j, a, b, state, num, k;

    scanf("%d", &testcases);
    for(i = 0; i < testcases; i++)
    {
        scanf("%d%d", &a, &b);
        in[i].n = a, in[i].k = b, in[i].id = i;
    }

    sort(in, in + testcases, cmp1);
    state = 0;
    num = 1;
    //printf("%x\n", (0 ^ (1 << 29)));
    for(j = 0; j < testcases && in[j].k == 0; j++) in[j].res = 0;
    for(i = 1; i <= in[testcases - 1].k && j < testcases; i++)
    {
        //printf("%x %d\n", state, num);
        state ^= (((1 << num) - 1) << (30 - num));
        for(k = 1; k < 30; k++)
        {
            //if(k < 3) printf("%d %x %x %x\n", k, state, (1 << (30 - k)), state & (1 << (30 - k)));
            if((state & (1 << (30 - k))) == 0) break;
        }
        num = k;
        //printf("i = %d, num = %d\n", i, num);
        for(; j < testcases; j++)
        {
            if(in[j].k != i) break;
          //  printf("state:%x\nin[%d].k = %d\n%x\n", state, j, in[j].k, (1 << (30 - in[j].k)));
            in[j].res = (state & (1 << (30 - in[j].n)));
            if(in[j].res && num < in[j].n) in[j].res = 0;//printf("%x\tNO %d:%d\n", state, i, in[j].res);
        }
    }
    sort(in, in + testcases, cmp2);

    for(i = 0; i < testcases; i++)
    {
        if(in[i].res) printf("Case #%d: ON\n", i + 1);
        else printf("Case #%d: OFF\n", i + 1);
    }
    return 0;
}
