#include <fstream>
#include <stdio.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

int main()
{
    int T, k;
    long long i,y;
    double C,F, X;
    double cost, r;
    char s[100];
    fin >> T;

    for(int k = 1; k <= T; k++)
    {
        fin >> C >> F >> X;
        y = (X * F - 2 * C)/ (F * C);
        fout<<"Case #"<<k<<": ";
        cost = 2;
        r = 0;
        for(i = 1; i <= y; i++)
        {
            r += C /cost;
            cost += F;
        }
        r += X / cost;
        sprintf(s, "%.7f", r);
        fout<<s<<"\n";
    }
    return 0;
}
