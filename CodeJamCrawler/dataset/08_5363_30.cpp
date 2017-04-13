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

const int SIZE(1000001);
int parent(int a, int* tab){
  if(a == tab[a]) return a;
  else return tab[a] = parent(tab[a], tab);
}
inline void set_union(int* tab, int a, int b){
  int pa = parent(a, tab);
  int pb = parent(b, tab);
  if(pa < pb) tab[pb] = pa;
  else        tab[pa] = pb;
}

l_int gcd(l_int a, l_int b){
  return b?gcd(b, a%b):a;
}

void set_prime(const int &size, vector<int>& prime){
  prime.clear();
  bool tab[size];
  fill_n(tab, size, true);
  tab[0] = tab[1] = false;
  prime.PB(2);
  //for(int i = 4; i < size; i+=2) tab[i] = false;
  for(int i = 3; i < size; i+=2){
    if(tab[i]){
      for(int j = i+i+i; j < size; j+=i){
	tab[j] = false;
      }
      prime.PB(i);
    }
  }
  return ;
}

l_int maxprimef(l_int GCD, vector<int>& prime){
  int ret(1);
  for(int idx = 0, end = prime.size(); idx < end; idx++){
    if(prime[idx] > GCD)break;
    while(GCD%prime[idx] == 0){
      ret = prime[idx];
      GCD /= prime[idx];
    }
  }
  if(GCD != 1){
    ret = GCD;
  }
  return ret;
}

int main(){
  vector<int> prime;
  set_prime(SIZE, prime);
  int C;
  cin >> C;
  REP(case_no, C){
    int table[1001];
    int A, B, P;
    cin >> A >> B >> P;
    REP(i,B+1) table[i] = i;
    for(int i = A; i <= B; i++){
      for(int j = i+1; j <= B; j++){
	l_int GCD(gcd(i, j));
	l_int mp = maxprimef(GCD, prime);
	if(mp >= P) {
	  //cerr << i << " " << j << " " << mp << endl;
	  set_union(table, i, j);
	}
      }
    }
    l_int ans(0);
    //for(int i = A; i<=B; i++) cout << parent(i, table) << " "; cout << endl;

    for(int i = A; i<=B; i++) if(i == parent(i, table)) ans++;
    cout << "Case #" << case_no+1 << ": " << ans << endl;
  }
  return 0;
}
