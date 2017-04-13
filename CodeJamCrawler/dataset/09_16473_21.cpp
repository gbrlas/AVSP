#include <iostream>
#include <vector>
#include <cassert>


using namespace std;
typedef vector<int> VI;

#define For(i,n) for(int i=0;i<int(n);++i)
#define Forf(i,f,t) for(int i=f;i<int(t);++i)

int main() {
  int N;
  cin >> N;
  For(caso, N) {
    cout << "Case #" << (caso+1) << ": ";
    int k;
    cin >> k;
    VI filas(k);
    For(i, k) {
      filas[i] = 0;
      For(j, k) {
        char t;
        cin >> t;
        if (t=='1') filas[i]=j;
      }
    }
    int swaps = 0;
    For(i, k) {

      //      For(kk, k) cout << filas[kk];
      //      cout << endl;

      if (filas[i]<=i) continue;
      else {
        int j = i+1;
        while (j<k and filas[j]>i) ++j;
        assert(j<k);
        swaps += j-i;
        for (int t=j;t>i;--t) filas[t] = filas[t-1];
      }
    }
    cout << swaps << endl;
  }
}
