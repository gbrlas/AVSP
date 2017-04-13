#include <fstream>
#include <vector>
#include <string>

using namespace std;

const char w[20] = "welcome to code jam";

int count;
string s = "";

void Find(int l, int p)
{
    if ( l == 19 )
    {
        count++;
        if ( count > 10000 )
            count %= 10000;
        return;
    }
    for (p; p < s.size(); p++)
    {
        if (s[p] == w[l])
            Find(l+1, p+1);
    }
        
}

int main()
{
    FILE* pif = fopen("C-small.in", "r");
    FILE* pof = fopen("C-small.out", "w");

    int N;

    fscanf(pif, "%d\n", &N);

    for (int n = 1; n <= N; n++)
    {
        count = 0;
        s = "";
        char c;
        fscanf(pif, "%c", &c);
        while ( c != 10 )
        {
            s += c;
            fscanf(pif, "%c", &c);
        }
        Find(0, 0);

        fprintf(pof, "Case #%d: %.4d\n", n, count);
    }

    return 0;
}