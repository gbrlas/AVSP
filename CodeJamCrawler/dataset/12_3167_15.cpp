#include <iostream>
#include <cstdio>
#include <sstream>
#include <string.h>
#include <cstdlib>
using namespace std;

const char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x',
                'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
                'z', 't', 'n', 'w', 'j', 'p', 'f', 'm',
                'a', 'q'};
const int maxn = 200;

int t;
char line[maxn];
stringstream ss;
int main() {

    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    gets(line);
    ss << line;
    ss >> t;
    for (int i=1; i <= t; ++i) {
        gets(line);
        printf("Case #%d: ", i);
        for (int j=0; j < (int)strlen(line); ++j)
            if (line[j] == ' ')
                printf(" ");
            else
                printf("%c", map[line[j]-97]);
        printf("\n");
    }
    return 0;
}
