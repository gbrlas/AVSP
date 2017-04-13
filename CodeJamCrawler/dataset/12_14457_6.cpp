#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


string randvec(int N) {
  string ret;
  for(int i = 0; i < N; i++)
    ret += '0' + (rand()%2);
  return ret;
}

pair<string, string> getans(vector<long long> &ps,
                long long maxdig) {
  int N = ps.size();

while(1) {
  vector<pair<long long, string> > msets;

  for(int i = 0; i < sqrt(10*maxdig); i++) {
    string mys = randvec(N);
    long long mysum = 0;
    for(int i = 0; i < N; i++)
      if(mys[i]=='1') mysum+=ps[i];

    msets.push_back(make_pair(mysum, mys));
  }

  sort(msets.begin(), msets.end());

  for(int i = 0; i < msets.size()-1; i++) {
    if(msets[i].first == msets[i+1].first) {
      if(msets[i].second != msets[i+1].second) {
        return make_pair(msets[i].second, msets[i+1].second);
      }
    }
  }
}

  pair<string, string> ret;
  return ret;
}

int main() {
  int T;
  cin >> T;
  for(int c = 0; c < T; c++) {
    int N;
    cin >> N;
    long long maxdig = 0;
    vector<long long> ps;
    for(int i=0; i < N; i++) {
      long long temp;
      maxdig = max(maxdig, temp);
      cin >> temp;
      ps.push_back(temp);
    }

    pair<string, string> ans = getans(ps, maxdig);
    cout << "Case #" << (c+1) << ":" << endl;
    for(int i = 0; i < ans.first.size(); i++){
      if(ans.first[i]=='1') {
        cout<<ps[i];
        if(i!=ans.first.size()-1) cout<< " ";
      }
    }
    cout << endl;
    for(int i = 0; i < ans.second.size(); i++){
      if(ans.second[i]=='1') {
        cout<<ps[i];
        if(i!=ans.second.size()-1) cout<< " ";
      }
    }
    cout << endl;
  }
  return 0;
}

