#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <queue>

#define db(X) cerr << "* DEBUG [L" << __LINE__ << "]: " << #X << " = " << X << endl;
#define db_arr(X) cerr << "* DEBUG [L" << __LINE__ << "]: {" << #X << "} = "; for (int __i__=0; __i__<sizeof(X)/sizeof(X[0]); __i__++) cerr << X[__i__] << " "; cerr << endl;
#define db_arrM(X, M) cerr << "* DEBUG [L" << __LINE__ << "]: {" << #X << "} = "; for (int __i__=0; __i__<M; __i__++) cerr << X[__i__] << " "; cerr << endl;
#define db_arrMN(X, M, N) cerr << "* DEBUG [L" << __LINE__ << "]: {" << #X << "} = "; for (int __i__=M; __i__<N; __i__++) cerr << X[__i__] << " "; cerr << endl;

#define For(i, n) for(i=0;i<(n);i++)
#define ForL(i, m, n) for(i=(m);i<(n);i++)

#define Clear(X) memset( (X), 0, sizeof( (X) ) )
#define Fill(X) memset( (X), -1, sizeof( (X) ) )

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned long ulong;

void _main();

int main() {
  // COUNTER CODE STARTS HERE
  int cases, i;
  cin >> cases;

  for (i=1; i<=cases; i++) {
    printf("Case #%d: ", i);
    _main();
    cout << endl;
  }

  // COUNTER CODE ENDS HERE

  return 0;
}

// ACTUAL CODE STARTS BELOW
ull g[1010], cum[1010], visit[1010], subcum[1010];
int N;
ull R, K;

void _main() {
  Clear(g); Clear(cum); Clear(visit); Clear(subcum);
  cin >> R >> K >> N;
  ull sum = 0, t, curr, round;
  int i, p, h;

  for (i=0; i<N; i++) { cin >> g[i]; }
  
  p = h = 0;
  curr = 0;
  round = 1;

  while (true) {
    if (curr + g[p] <= K) {
      sum += g[p];
      curr += g[p++];
      p %= N;

      if (p == h) {
	visit[h] = round++;
	if (round > R || visit[h]) {
	  break;
	}
      }

    } else {
      cum[h] = sum;
      subcum[h] = curr;
      visit[h] = round++;
      h = p;
      curr = 0;
      if (round > R || visit[h]) {
	break;
      }
    }
  }

  db_arrM(g, N); db_arrM(cum, N); db_arrM(visit, N); db_arrM(subcum, N);

  ull fastCumIncr = sum + subcum[h] - cum[h];
  ull fastRoundIncr = round - visit[h];
  ull roundRemaining = R - round + 1;
  ull fastSteps = roundRemaining / fastRoundIncr;

  db(sum); db(round);

  sum += fastSteps * fastCumIncr;
  round += fastSteps * fastRoundIncr;
  curr = 0;
  
  db(sum); db(round);

  while (round <= R) {
    if (curr + g[p] <= K) {
      sum += g[p];
      curr += g[p++];
      p %= N;

      if (p == h) {
	round++;
      }
    } else {
      round++;
      curr = 0;
      h = p;
    }
  }

  cout << sum;
}
