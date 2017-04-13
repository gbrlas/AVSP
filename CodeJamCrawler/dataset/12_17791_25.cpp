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
#include <memory.h>
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

FILE*   fpin;
FILE*   fpout;
int     t;
int     a, b;
int     hash[2000001];

inline int solve (int index, int low, int high) {
    int     l;
    int     num = 1;
    int     n = 1;
    int     sum = 0;
    l = (int)log10(index) + 1;
    n = index;
    hash[index] = -1;
    For(i, 1, l) num = num * 10;
    For(i, 1, l) {
        n = (n / num) + (n % num) * 10;
        //printf("o : number = %d, cnum = %d, hash[number] = %d, hash[cnum] = %d\n", index, n, hash[index], hash[n]);
        if (low <= index && index < n && n <= high && hash[n] != -1) {
            sum++;
            
            hash[n] = -1;
        }
        //printf("e : number = %d, cnum = %d, hash[number] = %d, hash[cnum] = %d\n", index, n, hash[index], hash[n]);
    }
    return sum;
}

void judge (int low, int high) {
    int     sum = 0;
    For(i, low, high + 1) {
        sum += solve(i, low, high);
        //printf("sum = %d\n", sum);
        For(j, low, high + 1) hash[j] = 0;
    }
    fprintf(fpout, "%d\n", sum);
}

int main (int argc, const char* argv[]) {
    
    fpin = fopen("1.in", "r");
    fpout = fopen("1.out", "w");
    fscanf(fpin, "%d", &t);
    For(i, 0, t) {
        memset(hash, 0, sizeof(hash));
        fscanf(fpin, "%d %d", &a, &b);
        fprintf(fpout, "Case #%d: ", i + 1);
        judge(a, b);
    }
    fclose(fpin);
    fclose(fpout);
    return 0;
}
