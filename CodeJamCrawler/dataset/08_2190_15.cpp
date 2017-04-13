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

typedef long long Int64;

int N, M, A;

void One(int idx)
{
    in >> N >> M >> A;
    int x1 = 0, y1, x2, y2 = 0, x3, y3;
    bool ok = false;
        for (y1 = 0; y1 <= M; ++y1)
    for (x2 = 0; x2 <= N; ++x2)
        {
            for (x3 = 0; x3 <= N; ++x3)
            {
                for (y3 = 0; y3 <= M; ++y3)
                {
                    int s = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
                    s = abs(s);
                    if (s == A)
                    {
                        ok = true;
                        goto OUT;
                    }
                }
            }
        }
    //for (a = 0; a <= N; ++a)
    //{
    //    for (a = 0; a <= M
    //}
    //for (x1 = 0; x1 <= N; ++x1)
    //    for (y1 = 0; y1 <= M; ++y1)
    //for (x2 = 0; x2 <= N; ++x2)
    //    for (y2 = 0; y2 <= M; ++y2)
    //    {
    //        int xy3 = 
    //        for (x3 = 0; x3 <= N; ++x3)
    //        {
    //            for (y3 = 0; y3 <= 1; ++y3)
    //            {
    //                if (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3 == A)
    //                {
    //                    ok = true;
    //                    goto OUT;
    //                }
    //            }
    //        }
    //    }

OUT:
    
    out << "Case #" << idx << ": ";
    if (!ok)
    {
        out << "IMPOSSIBLE";
    }
    else
    {
        out << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
    }
    out << endl;
}

void SolveN()
{
	int _N;
	in >> _N;
	for (int i = 0; i < _N; ++i)
	{
		One(i + 1);
	}
}

int main()
{
	SolveN();
	return 0;
}
