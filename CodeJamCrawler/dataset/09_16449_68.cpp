#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>

using namespace std;

#define For(i,n) for (int i=0;i<(n);++i)

struct node {
  double w;
  string feature;
  int hasf, nothasf;
};

int read_tree(vector<node> &v) {
  char c;
  node no;
  no.hasf=no.nothasf=-1;
  no.feature="";
  v.push_back(no);
  int a = v.size()-1;

  cin >> v[a].w;

  cin >> c;
  while (c!='(' and c!=')') {
    v[a].feature += string(1,c);
    cin >> c;
  }
 
  if (v[a].feature!="") {
    assert(c=='(');
    int dummy = read_tree(v);
    v[a].hasf = dummy;
    cin >> c;
    assert(c=='(');
    dummy = read_tree(v);
    v[a].nothasf = dummy;
    cin >> c;
    assert(c==')');
  }
  else assert(c==')');

  return a;
}

void write_tree(int a, const vector<node> &v, int level) {
  For(i,level*4) cout << " ";
  cout << v[a].w << "(" << v[a].feature << "):"
       << v[a].hasf << " " << v[a].nothasf << endl;
  if (v[a].feature!="") {
    write_tree(v[a].hasf, v, level+1);
    write_tree(v[a].nothasf, v, level+1);
  }
}

double compute(int a, vector<node> &v, vector<string> feats) {
  if (v[a].feature=="") return v[a].w;
  For(i, feats.size()) {
    if (v[a].feature==feats[i])
      return v[a].w*compute(v[a].hasf, v, feats);
  }
  return v[a].w*compute(v[a].nothasf, v, feats);
}

int main() {
  cout.setf(ios::fixed);
  int casos;
  cin >> casos;
  int t = 0;
  while (casos--) {
    int n;
    cin >> n;
    //    string st;
    //getline(cin, kk);
    //while (n--) {
    //  getline(cin, kk);
    //  st+=" " + kk;
    // }

    char c;
    cin >> c;
    assert(c=='(');
    vector<node> v;
    read_tree(v);
    cout << "Case #" << ++t << ":" << endl;
    
    //    write_tree(0, v, 0);
    cin >> n;
    while (n--) {
      string name;
      cin >> name;
      int k;
      cin >> k;
      vector<string> feats(k);
      For(i,k) cin >> feats[i];
      
      cout << setprecision(7) << compute(0, v, feats) << endl;
    }
  }
}
