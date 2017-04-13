#include <iostream>
#include <fstream>
#include <map>
#include <math.h>

typedef std::map<int, int> decomposition;

decomposition decompose(long x)
{
	decomposition output;

    long i = 2;

    long max = sqrt(x);
    while (i <= max)
    {
        int exposant = 0;
        while (!(x % i))
        {
            exposant = exposant + 1;
            x = x/i;
        }

        if (exposant)
            output[i] = exposant;

        i = i + 1;
    }

	if (x > 1)
		output[x] = 1;

	return output;
}

void intersect(decomposition &dec1, decomposition dec2)
{
    for (decomposition::iterator i = dec1.begin(); i != dec1.end();)
    {
        decomposition::iterator j = dec2.find(i->first);
        if (j != dec2.end())
        {
            if (j->second < i->second)
                dec1[i->first] = j->second;
            i++;
        }
        else
        {
            decomposition::iterator tmp = i;
            i++;
            dec1.erase(tmp);
        }
    }
}

void e_union(decomposition &dec1, decomposition dec2)
{
    for (decomposition::iterator i = dec2.begin(); i != dec2.end(); i++)
    {
        decomposition::iterator j = dec1.find(i->first);
        if (j == dec1.end() || j->second < i->second)
            dec1[i->first] = i->second;
    }
}

long rpow(int x, int n)
{
	long res = 1;
	while (n > 0)
	{
		if (n & 1)
			res = res*x;
		x = x*x;
		n = n >> 1;
	}
	return res;
}

long factor(decomposition d)
{
    long f = 1;

    for (decomposition::iterator i = d.begin(); i != d.end(); i++)
        f *= rpow(i->first, i->second);

    return f;
}

int main()
{
    std::fstream input("input.in", std::fstream::in);
    std::fstream output("output.out", std::fstream::out);

    int test_cases;
    input >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        int N, L, H;
        input >> N >> L >> H;

        decomposition i;
        long fs[N];
        for (int n=0; n < N; n++)
        {
            input >> fs[n];
            //decomposition df = decompose(fs[n]);
            //intersect(i, df);
        }
        long d = factor(i);
        long f;
        for (f = d*(L/d); f <= H; f+=d)
        {
            bool possible = true;
            for (int n = 0; n < N; n++)
            {
                if (fs[n] % f && f % fs[n])
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                output << "Case #" << test_case+1 << ": " << f << std::endl;
                break;
            }
        }
        if (f > H)
            output << "Case #" << test_case+1 << ": NO" << std::endl;
    }

    system("pause");

    return 0;
}
