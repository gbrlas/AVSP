#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>
#include <numeric>

using namespace std;
  
#define MM 10005
#define AND 1
#define OR 0

int M,V;
int tree_gates[MM];
bool tree_gate_changeable[MM];
int leaf_values[MM];

int dyna[MM][2];

bool is_leaf(int s) {
  return s > (M-1) / 2;
}

int min_changes(int s, int v);

void case_or(int &best, int fils1, int fils2, int v, bool inv = false) {
  bool fals = inv;
  bool tru = !inv;
  if (v == 0) {
    best = min(best, min_changes(fils1, fals) + min_changes(fils2, fals));
  }
  if (v == 1) {
    best = min(best, min_changes(fils1, fals) + min_changes(fils2, tru));
    best = min(best, min_changes(fils1, tru) + min_changes(fils2, fals));
    best = min(best, min_changes(fils1, tru) + min_changes(fils2, tru));
  }
}

void case_and(int &best, int fils1, int fils2, int v) {
  if (v == 1) {
    case_or(best, fils1, fils2, !v, true);
  }
  if (v == 0) {
    case_or(best, fils1, fils2, !v, true);
  }
}

int min_changes(int s, int v) {
  int &best = dyna[s][v];
  if (best != -1) return best;
  best = 1000000;
  if (is_leaf(s)) {
    if (v == leaf_values[s]) best = 0;
  } else {
    int fils1 = 2*s;
    int fils2 = 2*s + 1;
    // without changing
    if (tree_gates[s] == AND) {
      case_and(best, fils1, fils2, v);
    }
    if (tree_gates[s] == OR) {
      case_or(best, fils1, fils2, v);
    }
    //changing
    if (tree_gate_changeable[s]) {
      int b2 = 1000000;
      case_and(b2, fils1, fils2, v);
      b2 += (tree_gates[s] != AND);
      best = min(best, b2);
      int b3 = 1000000;
      case_or(b3, fils1, fils2, v);
      b3 += tree_gates[s] != OR;
      best = min(best, b3);
    }
  }
  return best;
}

  
int main() {
  int test_case;
  cin>>test_case;
  for (int tt = 1 ; tt <= test_case ; tt++) {
    cin>>M>>V;
    for (int i = 1 ; i <= (M-1)/2 ; i++) {
      int G,C;
      cin>>G>>C;
      tree_gates[i] = G;
      tree_gate_changeable[i] = C;
    }
    for (int i = 0 ; i < (M+1)/2 ; i++) {
      int I;
      cin>>I;
      leaf_values[i + (M-1)/2 + 1] = I;
    }
    fill(*dyna, *dyna + MM*2, -1);
    
    int res = min_changes(1, V);
    cout <<"Case #"<<tt<<": ";
    if (res >= 1000000) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}
