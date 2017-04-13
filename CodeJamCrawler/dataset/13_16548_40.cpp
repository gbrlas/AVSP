#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main()
{
    unsigned long long dig;
    unsigned long long input;
    unsigned long long sqrtinput;
    unsigned long long st;
    unsigned long long en;
    unsigned long long n;
    unsigned long long rev = 0;
    int total = 0;
    int e;

    ifstream in;
    in.open("input");
    ofstream out;
    out.open("output2");

    in>>e;
    for(int i = 0; i < e; i++)
    {
        in>>st;
        in>>en;
        for(unsigned long long j = st; j <= en; j++)
        {
            input = j;
            if (sqrt(j) - (int)sqrt(j)) continue;
            sqrtinput = sqrt(j);
            n = sqrtinput;
            rev = 0;
            while (sqrtinput > 0)
            {
                dig = sqrtinput % 10;
                rev = rev * 10 + dig;
                sqrtinput = sqrtinput / 10;
            }
            if(n == rev)
            {
                n = input;
                rev = 0;
                while (input > 0)
                {
                    dig = input % 10;
                    rev = rev * 10 + dig;
                    input = input / 10;
                }
                if (n == rev) total++;
            }
        }
        out<<"Case #"<<i+1<<": "<<total<<endl;
        total = 0;
    }

    return 0;
}
