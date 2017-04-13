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

int a[4][4];
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    map<int, int> M;
    for (int _i = 0; _i < 2; _i++){
      int row; cin >> row; row--; 
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
          cin >> a[i][j];
        }
      }
      for (int i = 0; i < 4; i++) M[a[row][i]]++;
    }

    vector<int> ans;
    for (auto it: M) if (it.second == 2){
      ans.push_back(it.first);
    }
    cout << "Case #" << ++TestNum << ": ";
    if (ans.size() == 1) cout << ans[0] << endl;
    if (ans.size() == 0) cout << "Volunteer cheated!" << endl;
    if (ans.size() >  1) cout << "Bad magician!" << endl;
  }
}





