#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i < (b); i++)
#define REP(i, a) for(int i=0; i < (a); i++)

FILE* fin = fopen("small.in", "r");
FILE* fout = fopen("output.txt", "w");
int read_int() { int x; fscanf(fin, "%d", &x); return x; }

int main()
{
  int T = read_int();
  FOR(i, 0, T)
  {
    int N = read_int();
    vector<int> x, y;
    FOR(j, 0, N)
    {
      int xj = read_int();
      x.push_back(xj);
    }
    FOR(j, 0, N)
    {
      int yj = read_int();
      y.push_back(yj);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int min = 0;
    FOR(j, 0, N)
    {
      min += x[j] * y[N - j - 1];
    }
    fprintf(fout, "Case #%d: %d\n", i + 1, min);
  }

  return 0;
}
