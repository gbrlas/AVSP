#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VE;
typedef vector<VE> VVE;

#define For(i,n) for (int i=0;i<int(n);++i)
#define Forf(i,f,t) for (int i=int(f);i<int(t);++i)

const string pattern = "welcome to code jam";


int main() {
  int N;
  cin >> N;
  string kk;
  getline(cin, kk);
  For(caso,N) {
    string text;
    getline(cin, text);
    VVE m(text.size()+1, VE(pattern.size()+1, 0));

    For(i, text.size()) m[i][0] = 1;
    Forf(j, 1, pattern.size()+1) {
      Forf(i, j, text.size()+1) {
        m[i][j]=m[i-1][j];
        if (text[i-1]==pattern[j-1]) m[i][j]+=m[i-1][j-1];
        m[i][j] %= 1000;
      }
    }
    cout << "Case #" << (caso+1) << ": " 
         << setfill('0') << setw(4) << m[text.size()][pattern.size()] << endl;
  }
}
