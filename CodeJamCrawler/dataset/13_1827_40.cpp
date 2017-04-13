#include <fstream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    ifstream fin("c.in");
    ofstream fout("c.out");
    int t;
    __int64 a, b;
    char tmp1[15], tmp2[15], tmp3[15], tmp4[15];
    fin >> t;
    for (int l = 0; l < t; l++)
    {
        fin >> a >> b;
        int sum = 0;
        for (__int64 j = ceil(sqrtl((long double)a)), i = j * j; i <= b; ++j, i = j * j)
        {
            itoa(i, tmp1, 10);
            itoa(j, tmp3, 10);
            itoa(i, tmp2, 10);
            itoa(j, tmp4, 10);
            reverse(tmp2, tmp2 + strlen(tmp2));
            reverse(tmp4, tmp4 + strlen(tmp4));
            if (strcmp(tmp1, tmp2) == 0 && strcmp(tmp3, tmp4) == 0)
            {
                ++sum;
            }
        }
        fout << "Case #" << l + 1 << ": " << sum << endl;
    }
    return 0;
}
