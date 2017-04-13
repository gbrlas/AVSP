#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
long long licz, mian;

long long NWD(long long m, long long M)
{
    while (true)
    {
        long long k=M%m;
        M=m;
        m=k;
        if (m==0) return M;
    }
}


void read()
{
    char c;
    scanf("%lld%c%lld", &licz, &c, &mian);
    long long nwd=1;
    if (licz<=mian) nwd=NWD(licz, mian);
    licz/=nwd;
    mian/=nwd;
}

bool pow_2(long long a)
{
    while (a!=1)
    {
        if (a%2) return false;
        a/=2;
    }
    return true;
}

int main()
{
    int ttt;
    scanf("%d", &ttt);

    for (int i=1; i<=ttt; i++)
    {
        read();
        if (!pow_2(mian))
        {
            printf("Case #%d: impossible\n", i);
            continue;
        }
        int out=0;
        int L=mian;
        while (true)
        {
            if (L<=licz) break;
            out++;
            L/=2;
        }
        if (out==0) printf("Case #%d: 1\n", i);
        else printf("Case #%d: %d\n", i, out);

    }

}
