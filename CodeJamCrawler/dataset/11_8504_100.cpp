#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>

#include<tr1/unordered_map>
#include<tr1/unordered_set>

#include<algorithm>
#include<functional>
#include<utility>
#include<iomanip>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int N;
    cin >> N;    
    int sum(0), minv(10000000), bitxor(0);
    REP(i,N){
      int temp; cin >> temp;
      bitxor ^= temp;
      sum += temp;
      minv = min(minv, temp);
    }
    
    cout << "Case #" << case_no+1 << ": ";
    if(bitxor == 0) cout << sum - minv << endl;
    else            cout << "NO" << endl;
  }

  return 0;
}
