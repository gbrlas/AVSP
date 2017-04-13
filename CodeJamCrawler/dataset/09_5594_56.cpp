#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<deque>
#include<stack>

#include<algorithm>
#include<utility>
#include<functional>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define MP make_pair

struct Tree{
  string feature;
  double weight;
  vector<Tree> child;
  bool isLeaf(){ return child.size() == 0; }
  double calc(set<string>& features){
    return (isLeaf() 
	    ? 1.0 
	    : ( features.find(feature) != features.end() 
		? child[0].calc(features) 
		: child[1].calc(features)) ) * weight;
  }
};

int parseTree(string& s, Tree& tree, int idx = 0){
  while(idx < (int)s.size() && !isdigit(s[idx])) idx++;
  int head = idx;
  while(idx < (int)s.size() && (isdigit(s[idx]) || s[idx] == '.'))idx++;
  double w = atof(s.substr(head, idx - head).c_str());
  tree.weight = w;
  //  cerr << w << endl;
  if(idx >= (int)s.size() || s[idx] == ')'){
    //leaf
    return idx+1;
  }else{
    //internal
    tree.child.push_back(Tree()); 
    tree.child.push_back(Tree());
    head = idx;
    while(idx < (int)s.size() && s[idx] != '(') idx++;
    tree.feature = s.substr(head, idx - head);
    //    cerr << tree.feature << endl;
    idx = parseTree(s, tree.child[0], idx);
    idx = parseTree(s, tree.child[1], idx);
  }
  return idx;
}

int main(){
  int N, L, A;
  string buf;
  cin >> N;
  REP(case_no, N){
    string s;
    set<string> feature;
    cin >> L; cin.ignore();
    REP(i, L){
      getline(cin, buf);
      istringstream iss(buf);
      while(iss >> buf) s += buf;
    }
    //    cerr << s << endl;
    //parse
    Tree tree;
    parseTree(s, tree);
    
    //query
    printf("Case #%d:\n", case_no+1);
    cin >> A; cin.ignore();
    REP(i, A){
      string name;
      int n;
      set<string> features;
      cin >> name >> n;
      REP(j, n){
	cin >> buf; features.insert(buf);
      }
      printf("%.7lf\n", tree.calc(features));
    }
    cin.ignore();
  }
  return 0;
}
