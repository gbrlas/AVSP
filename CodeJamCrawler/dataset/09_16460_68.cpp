#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define For(i,n) for(int i=0;i<(n);++i)
#define Forf(j,f,n) for(int j=(f);j<(n);++j)

void reordena(string &st) {
  if (st.size()==1) {
    cout << st << "0" << endl;
    return;
  }
  int i = st.size()-1;
  while (i>0 and st[i]<=st[i-1]) {
    --i;
  }

  if (i==0) {
    int k = st.size()-1;
    while (st[k]=='0') --k;
    cout << st[k] << "0";
    For(j, st.size()) {
      if (st.size()-1-j!=k) cout << st[st.size()-1-j];
    }
  }
  else {
    --i;
    Forf(j, 0, i) cout << st[j];
    int sm = '9'+1, ism = -1;
    Forf(j, i+1, st.size()) {
      if (st[j]<sm and st[j]>st[i]) {
	sm = st[j];
	ism = j;
      }
    }
    cout << st[ism];
    vector<char> vc;
    Forf(j, i, st.size()) {
      if (j!=ism) vc.push_back(st[j]);
    }
    sort(vc.begin(), vc.end());
    For(j, vc.size()) cout << vc[j];
  }
  cout << endl;

}

int main() {
  int n;
  cin >> n;
  For(caso, n) {
    cout << "Case #" << (caso+1) << ": ";
    string st;
    cin >> st;
    
    reordena(st);
  }

}
