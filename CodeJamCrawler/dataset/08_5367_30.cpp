#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<complex>
#include<list>
#include<deque>
#include<bitset>

#include<algorithm>
#include<functional>
#include<numeric>
#include<iomanip>
#include<utility>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long int l_int;
const int IMAX((1<<30)-1);
const int LLMAX(1LL<<60);
const double EPS(1.0e-10);
const double mpi(acos(-1.0));


#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define PB push_back
#define MP make_pair


int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int K, n;
    cin >> K >> n;
    map<int,vector<int> > indeces;
    REP(i,n) {
      int tmp; cin >> tmp;
      indeces[tmp].PB(i);
    }
    deque<int> deck(K);
    REP(i,K) deck[i] = i+1;
    int ans[n];
    int idx(0);
    set<int> b,c;
    REP(i,K){
      if(idx >= n)break;      
      REP(j,i){
	deck.PB(deck.front());
	deck.pop_front();
      }
      if(indeces.find(deck.front()) != indeces.end()){
	vector<int>& t(indeces[deck.front()]);
	REP(j, t.size()) ans[t.at(j)] = i+1;
	idx++;
      }
      deck.pop_front();
    }
    cout << "Case #" << case_no+1 << ":";
    REP(i,n) cout << " " << ans[i]; cout << endl;
  }
  return 0;
}
