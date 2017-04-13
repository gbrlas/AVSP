#include <iostream>

using namespace std;

// d[i][j] кол-во вариантов составления подстроки E(i, el), с позиции j строки s
// очевидно что d[0][0] есть наш ответ

// d[el-1][sl-1] = 1 если s[sl-1] == E[el-1] иначе 0
// т.е.

// d[i][j] = 
//  d[i][j+1] if(s[j] != E[i])
//  d[i][j+1] + 1 if(s[j] == E[i])
// считаем все d[x][i] для всех i

// d[i][j] =
//  d[i+1][j+1] if(j+1 < sl && s[j] == E[i])
//  0
int d[50][501];
#define MOD 10000
int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  string E = "welcome to code jam";
  int el = E.length();
  int Case, N;
  cin >> N;
  for(Case = 1; Case <= N; Case++) {
    int ans;
    char buf[501];
    cin.get();
    cin.get(buf, 501);
    string s = buf;
    int sl = s.length();
    if(sl < el) {
      ans = 0;
    }
    else {
      memset(d, 0, sizeof(d));
      d[el-1][sl-1] = (s[sl-1] == E[el-1]) ? 1 : 0;
      for(int i = sl - 2; i >= 0; i--) {
        d[el-1][i] = d[el-1][i+1];
        if(s[i] == E[el-1]) {
          d[el-1][i] += 1;
        }
      }
      for(int i = el - 2; i >= 0; i--) {
        for(int j = sl - 1; j >= 0; j--) {
          // d[i][j]
          for(int k = j; k < sl; k++) {
            if(s[k] == E[i] && j+1 < sl) d[i][j] = (d[i][j] + d[i+1][k+1]) % MOD;
          }
        }
      }
      /*
      for(int i = 0; i < el; i++) {
        cout << endl;
        for(int j = 0; j < sl; j++) {
          cout << d[i][j] << " ";
        }
      }
      */
      ans = d[0][0];
    }
    cout << "Case #" << Case << ": ";
    printf("%04d", ans);
    cout << endl;
  }
  return 0;
}
