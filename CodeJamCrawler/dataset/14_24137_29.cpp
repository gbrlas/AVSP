//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 1024;
int M, N;
vector<string> S;
vector<vector<string>> servers;
int X, Y;
int calc(vector<string> a){
  sort(a.begin(), a.end());
  int tot = 1;
  for (int i = 0; i < (int)a.size(); i++){
    tot += a[i].size();
    if (i - 1 < 0) continue;
    for (size_t j = 0; j < min(a[i].size(), a[i - 1].size()); j++){
      if (a[i - 1][j] == a[i][j]){
        tot--;
      }else{
        break;
      }
    }
  }
  return tot;
}

void dfs(int k){
  if (k == M){
    int tot = 0;
    for (int i = 0; i < N; i++) if (servers[i].size() == 0) return;
    for (int i = 0; i < N; i++){
      auto tmp = servers[i];
      tot += calc(tmp);
    }
    if (tot == X) Y++;
    else if (tot > X) X = tot, Y = 1;
  }else{
    for (int i = 0; i < N; i++){
      servers[i].push_back(S[k]);
      dfs(k + 1);
      servers[i].pop_back();
    }
  }
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    cin >> M >> N;
    S.clear();
    S.resize(M);
    for (auto &elem: S) cin >> elem;
    servers.clear();
    servers.resize(N);
    X = Y = 0;
    dfs(0);
    cout << "Case #" << ++TestNum << ": " << X << " " << Y << endl;
  }
}

