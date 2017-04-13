#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
template<class T> inline T Max(T a,T b)
{if(a>b)return a;else return b;}
template<class T> inline T Min(T a,T b)
{if(a<b)return a;else return b;}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T TripleMax(T a,T b,T c)
{return Max(Max(a,b),c);}
template<class T> inline T TripleMin(T a,T b,T c)
{return Min(Min(a,b),c);}
#define ll long long
#define For(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define DFor(i, b, a) for (int (i) = (b) - 1; (i) >= (a); (i)--)

int     t;
char    o[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                 'o', 'p', 'q', 'r', 's', 't', 'u',
                 'v', 'w', 'x', 'y', 'z'};
char    p[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v',
                 'x', 'd', 'u', 'i', 'g', 'l', 'b',
                 'k', 'r', 'z', 't', 'n', 'w', 'j',
                 'p', 'f', 'm', 'a', 'q'};
FILE*   fpin;
FILE*   fpout;
char    data[105];
int     pt;

int main (int argc, const char* argv[]) {
    
    fpin = fopen("1.in", "r");
    fpout = fopen("1.out", "w");
    fscanf(fpin, "%d", &t);
    fgetc(fpin);
    For(i, 0, t) {
        pt = 0;
        fgets(data, 105, fpin);
        fprintf(fpout, "Case #%d: ", i + 1);
        while (data[pt] != '\0' && data[pt] != '\n') {
            if (data[pt] == ' ') fprintf(fpout, " ");
            else  {
                fprintf(fpout, "%c", p[data[pt] - 'a']);
            }
            pt++;
        }
        if (i != t - 1) fprintf(fpout, "\n");
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
