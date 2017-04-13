#include <iostream>
#include <vector>
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

void One(int idx)
{
    int n_s;
    string s[128];
    in >> n_s;
    for (int i = 0; i < n_s; ++i)
    {
        getline(in, s[i]);
        while (s[i] == "")
        {
            getline(in, s[i]);
        }
    }

    int n_q;
    in >> n_q;
    string q[1024];
    for (int i = 0; i < n_q;++i)
    {
        getline(in, q[i]);
        while(q[i] == "")
        {
            getline(in, q[i]);
        }
    }

    int sw = 0;

    int st = 0;
    while(st < n_q)
    {
        int f = 0;
        for (int i = 0; i < n_s; ++i)
        {
            int j;
            for (j = st; j < n_q; ++j)
            {
                if (s[i] == q[j])
                {
                    if (j - st > f)
                    {
                        f = j - st;
                    }
                    break;
                }
            }
            if (j >= n_q)
            {
                f = -1;
                break;
            }
        }
        if (f == -1)
        {
            break;
        }

        st += f;
        ++sw;
    }

    out << "Case #" << idx << ": ";
    out << sw;
    out << endl;
}

void SolveN()
{
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