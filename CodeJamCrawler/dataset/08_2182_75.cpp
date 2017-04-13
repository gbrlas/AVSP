#include <iostream>
#include <vector>
#include <cstdio>
#include <list>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define _Test
#ifdef _Test
#define in cin
#define out cout
#else
#endif

struct Ma
{
    int x, y, z, w;
};
//M^2^i
Ma m[128];
Ma e;

void MUL(Ma& a, Ma& b, Ma& dst)
{
    dst.x = ((a.x * b.x + a.y * b.z) % 1000 + 1000) % 1000;
    dst.y = ((a.x * b.y + a.y * b.w) % 1000 + 1000) % 1000;
    dst.z = ((a.z * b.x + a.w * b.z) % 1000 + 1000) % 1000;
    dst.w = ((a.z * b.y + a.w * b.w) % 1000 + 1000) % 1000;
}

void SQR(Ma& src, Ma& dst)
{
    MUL(src, src, dst);
}


void Pre()
{
    e.x = 1;
    e.y = 0;
    e.z = 0;
    e.w = 1;

    m[0].x = 6;
    m[0].y = -4;
    m[0].z = 1;
    m[0].w = 0;
    for (int i = 1; i < 64; ++i)
    {
        SQR(m[i-1], m[i]);
    }
}

Ma POW(int n)
{
    Ma rs = e;
    int i = 0;
    while (n)
    {
        if (n&1)
        {
            Ma c = rs;
            MUL(c, m[i], rs);
        }
        n >>= 1;
        ++i;
    }
    return rs;
}

int Si(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 5;
    }
    if (n == 2)
    {
        return 27;
    }
    Ma r = POW(n - 2);

    return (28 * r.x + 6 * r.y - 1) % 1000;
}

void Out(int r)
{
    if (r < 10)
    {
        out << "0";
    }
    if (r < 100)
    {
        out << "0";
    }
    out << r;
}

void One(int idx)
{
    int n;
    in >> n;

    out << "Case #" << idx << ": ";
    Out(Si(n));
    out << endl;
}

void One2(int idx)
{
    int n;
    int a[1024], b[1024];
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        in  >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        in  >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, std::greater<int>());

    __int64 rs = 0;
    for (int i = 0; i < n; ++i)
    {
        rs += ((__int64)a[i]) * b[i];
    }

    printf("Case #%d: %I64d\n", idx, rs);
}

void SolveN()
{
    Pre();
	int n;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		One(i + 1);
	}
}



void Solve()
{
}

int main()
{
	SolveN();
	return 0;
}