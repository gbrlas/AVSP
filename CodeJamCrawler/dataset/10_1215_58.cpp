#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

//#define debug(...)
#define debug printf

int N;
map<int, int> line;
vector<int> a, b;
map<int, int> lowerN;
vector<int> border;

int main() {
//  freopen("A-sample.in", "r", stdin);

  int caseN;
  cin >> caseN;

  for (int cc = 1; cc <= caseN; ++cc) {
    cout << "Case #" << cc << ": " ;

    a.clear();
    b.clear();
    lowerN.clear();
    line.clear();

    cin >> N;
    int ta, tb;
    for (int i = 0 ; i < N; ++i) {
      cin >> ta >> tb;
      a.push_back(ta);
      b.push_back(tb);
      line[ta] = tb;
    }
    sort(a.begin(), a.end());
    border.resize(N);
    for (int i = 0; i < N; ++i) {
      border[i] = line[a[i]];
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (border[j] < border[i]) sum++;
      }
    }
    cout << sum;

    cout << endl;
  }

  return 0;
}

