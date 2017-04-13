#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>

#include<cstdio>
#include<cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int main(){
  int C;
  cin >> C;
  REP(case_no, C){
    int B, K, N, T;
    cin >> N >> K >> B >> T;
    vector<int> pos(N), vec(N);
    REP(i, N){
      cin >> pos[i];
    }
    REP(i, N){
      cin >> vec[i];
    }
    reverse(ALL(pos)); reverse(ALL(vec));
    vector<int> reached;
    REP(i, N){
      int dist = B - pos[i];
      if(dist <= T * vec[i]){
	reached.push_back(i);
      }
    }
    cout << "Case #" << case_no+1 << ": ";
    if((int)reached.size() < K){
      cout << "IMPOSSIBLE" << endl;
    }
    else{
      int ans(0);
      REP(i, K){
	ans += reached[i] - i;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
