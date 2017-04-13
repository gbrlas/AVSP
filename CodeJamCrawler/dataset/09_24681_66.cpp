#include <cctype>
#include <cstdio>
#include <set>
#include <string>
#include <vector>

using namespace std;

char buffer[1000];
int yy, L, D, N, last, ii, jj, total;
set<char> tokens[20];
vector<string> dict;
vector<string>::iterator it;

int main(void)
{
    scanf("%d %d %d\n", &L, &D, &N);
    for (ii = 0; ii < D; ii++)
    {
        scanf("%s\n", buffer);
        dict.push_back(buffer);
    }
    for (yy = 1; yy <= N; yy++)
    {
        scanf("%s\n", buffer);
        for (ii = 0, jj = 0; buffer[jj] != 0; ii++)
        {
            if (isalpha(buffer[jj]))
            {
                tokens[ii].insert(buffer[jj]);
                last = ii;
                jj++;
                continue;
            }
            if (buffer[jj] == '(')
            {
                for (++jj; buffer[jj] != ')' && buffer[jj] != 0; jj++)
                {
                    tokens[ii].insert(buffer[jj]);
                    last = ii;
                }
                if (buffer[jj] == ')')
                    jj++;
            }
        }
        total = 0;
        for (it = dict.begin(); it != dict.end(); it++)
        {
            for (ii = 0; ii < L; ii++)
            {
                if (tokens[ii].find((*it)[ii]) == tokens[ii].end())
                    break;
            }
            if (ii >= L)
                total++;
        }
        printf("Case #%d: %d\n", yy, total);
        for (ii = last; ii >= 0; ii--)
            tokens[ii].clear();
    }
    return 0;
}
