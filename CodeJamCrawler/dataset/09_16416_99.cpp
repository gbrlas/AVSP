#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> VS;

#define For(i,n) for (int i=0;i<int(n);++i)

int L, D, N;

string read_token() {
  char c;
  cin >> c;
  string s(1,c);
  if (c=='(') {
    s="";
    while (cin >> c and c!=')') s=s+string(1,c);
  }
  return s;
}

bool matches(const VS &p, const string &w) {
  For(i,w.size()) {
    bool match = false;
    For(j,p[i].size()) {
      if (w[i]==p[i][j]) {match=true; break;}
    }
    if (not match) return false;
  }
  return true;
}

int main() {
  cin >> L >> D >> N;
  VS words(D);
  For(i,D) {
    cin >> words[i];
  }
  
  For(i,N) {
    VS pattern(L);
    For(j,L) pattern[j] = read_token();

    int count = 0;
    For(j,D) if (matches(pattern, words[j])) ++count;

    cout << "Case #" << (i+1) << ": " << count << endl;
  }
}
