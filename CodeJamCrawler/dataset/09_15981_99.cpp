#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <cmath>
#include <numeric>
#include <complex>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iomanip>
#include <sstream>

#include <cctype>
#include <cstring>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>

#include <ext/hash_map>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned char uchar;
typedef short int sint;
typedef unsigned short int usint;
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef double dbl;
typedef long double ldbl;

#define pb push_back
#define mp make_pair
#define _clear(x) memset(x, 0, sizeof(x))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

#define PRB "B"

char d[100][100], cache[100][100];
int a[100][100];
int h, w, next;

bool issink(int r, int c) {
  int min = a[r][c];
  if(r-1>=0) {
    if(a[r-1][c] < min) return false;
  }
  if(c-1>=0) {
    if(a[r][c-1] < min) return false;
  }
  if(c+1<w) {
    if(a[r][c+1] < min) return false;
  }
  if(r+1<h) {
    if(a[r+1][c] < min) return false;
  }
  return true;
}

char getSink(int r, int c) {
  if(cache[r][c] == 0) {
    int min = a[r][c];
    int rr=-1,cc=-1;
    if(r-1>=0) {
      if(a[r-1][c] < min) {
        min=a[r-1][c];
        rr=r-1;
        cc=c;
      }
    }
    if(c-1>=0) {
      if(a[r][c-1] < min) {
        min=a[r][c-1];
        rr=r;
        cc=c-1;
      }
    }
    if(c+1<w) {
      if(a[r][c+1] < min) {
        min=a[r][c+1];
        rr=r;
        cc=c+1;
      }
    }
    if(r+1<h) {
      if(a[r+1][c] < min) {
        min=a[r+1][c];
        rr=r+1;
        cc=c;
      }
    }
    if(rr!=-1) {
      cache[r][c] = getSink(rr, cc);
    }
    else {
      cache[r][c] = d[r][c];
    }
  }
  return cache[r][c];
}

void replace(char c, char s) {
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(d[i][j] == c && !cache[i][j]) {
        d[i][j] = s;
        cache[i][j] = 1;
      }
    }
  }
}

int main() {
  freopen(PRB".in", "r", stdin);
  freopen(PRB".out", "w", stdout);
  int Case, T;
  cin >> T;
  for(Case = 1; Case <= T; Case++) {
    cin >> h >> w;
    _clear(d);
    _clear(cache);
    next = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        cin >> a[i][j];
      }
    }
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(issink(i, j)) {
          d[i][j] = 'a' + next++;
          cache[i][j] = d[i][j];
        }
      }
    }
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(d[i][j] == 0) {
          d[i][j] = getSink(i, j);
        }
      }
    }
    
    _clear(cache);
    next = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(!cache[i][j]) {
          replace(d[i][j], (char)('a' + next++));
        }
      }
    }
    if(Case != 1) cout << endl;
    cout << "Case #" << Case << ": ";
    for(int i = 0; i < h; i++) {
      cout << endl;
      for(int j = 0; j < w; j++) {
        cout << d[i][j] << " ";
      }
    }
  }
  return 0;
}
