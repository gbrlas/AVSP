/*
 * Google Code Jam 2008
 * Qualification Round
 * Problem A: Saving the Universe
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 999999

int solve(const vector<string> engines,
          const vector<string> queries)
{
  const int S = engines.size();
  const int Q = queries.size();

  // dp[s][q] = the fewest number of switches required
  //            to process the first  q  queries,
  //            leaving  s  as the active search engine, 
  //            or  INF  if it is not possible to do so.
  //
  int dp[128][1024];
  for (int s = 0; s < S; s++)
    dp[s][0] = 0;
  for (int q = 1; q <= Q; q++) {
    const string query = queries[q-1];
    int engineMatch = -1;
    for (int e = 0; e < S; e++)
      if (query == engines[e])
        engineMatch = e;
    for (int s = 0; s < S; s++) {
      if (s == engineMatch) {
        dp[s][q] = INF;
      } else {
        dp[s][q] = dp[s][q-1];
        for (int s2 = 0; s2 < S; s2++)
          if ((dp[s2][q-1]+1) < dp[s][q])
            dp[s][q] = dp[s2][q-1] + 1;
      }
    }//next s
  }//next q
  int ret = INF;
  for (int s = 0; s < S; s++)
    if (dp[s][Q] < ret)
      ret = dp[s][Q];
  return ret;
}
    

int main(int argc, char *argv[])
{
  int N;
  cin >> N;
  for (int tc = 1; tc <= N; tc++) {
    int S, Q;
    vector<string> engines;
    vector<string> queries;
    cin >> S;
    string tmp;
    for (int s = 0; s < S; s++) {
      do getline(cin, tmp); while (tmp.size() == 0);
      engines.push_back(tmp);
    }
    cin >> Q;
    for (int q = 0; q < Q; q++) {
      do getline(cin, tmp); while (tmp.size() == 0);
      queries.push_back(tmp);
    }
    int ret = solve(engines, queries);
    printf("Case #%d: %d\n", tc, ret);
  }
}
    
  
