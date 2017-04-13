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
int N;
bool valid(vector<int> A){
  int pos = max_element(A.begin(), A.end()) - A.begin();
  for (int i = 0; i < pos; i++){
    if (A[i] > A[i + 1]) return false;
  }
  for (int i = pos; i + 1 < N; i++){
    if (A[i] < A[i + 1]) return false;
  }
  return true;
}
int swapNums(vector<int> A, vector<int> B){
  vector<int> C(N);
  for (int i = 0; i < N; i++) C[B[i]] = i; 
  for (int i = 0; i < N; i++) A[i] = C[A[i]];
  int tot = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++) if (A[i] > A[j]) tot++; 
  }
  return tot;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--){
    cin >> N;
    vector<int> A(N);
    for (auto &elem: A) cin >> elem;
    vector<int> B(A);
    sort(B.begin(), B.end());

    for (auto &elem: A) elem = lower_bound(B.begin(), B.end(), elem) - B.begin();
    B = A;

    sort(B.begin(), B.end());;

    int best = 0x3f3f3f3f;
    do{
      if (valid(B)){
        best = min(best, swapNums(A, B));
      }
    }while(next_permutation(B.begin(), B.end()));
    cout << "Case #" << ++TestNum << ": " << best << endl;
  }
}

