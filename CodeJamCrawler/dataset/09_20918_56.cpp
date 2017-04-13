#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <map>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
//#define DEBUG
#ifdef DEBUG
#define printd(args...) printf(args)
#else
#define printd(args...)
#endif
#define scand(args...) if(scanf(args) == EOF) { \
   fprintf(stderr, "FATAL ERROR: unexpected end of file\n"); \
   exit(1); \
}
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(),(c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define PF push_front
#define MP make_pair
const int INF = 1000000001;
const double EPS = 10e-9;

struct Ted {
   Ted() {}
   Ted(LD _v, string _s, Ted * _l, Ted * _r): v(_v), s(_s), l(_l), r(_r) {}
   Ted(LD _v): v(_v), s(""), l(NULL), r(NULL) {}
   LD v;
   string s;
   Ted * l, * r;
   ~Ted() {
      if (l != NULL) delete l;
      if (r != NULL) delete r;
   }
   void print(int d) {
      REP(x, d) cout << " ";
      cout << v;
      if (SIZE(s)) {
         cout << "  " << s << ":" << endl;
         l->print(d+3);
         r->print(d+3);
      }
      else cout << endl;
   }
};

struct Tr {
   string a;
   Ted * root;

   LD get_num(int & v) {
      while (!(a[v] <= '9' && a[v] >= '0')) v++;
      string s = "";
      while ((a[v] <= '9' && a[v] >= '0') || a[v] == '.') {
         s.append(1, a[v++]);
      }
      stringstream ss;
      ss << s;
      //cout << "s: " << s << endl;
      LD h;
      ss >> h;
      return h;
   }

   string get_string(int & v) {
      while (!(a[v] >= 'a' && a[v] <= 'z')) v++;
      string s = "";
      while (a[v] >= 'a' && a[v] <= 'z') {
         s.append(1, a[v++]);
      }
      return s;
   }

   Ted * rek(int & v) {
      while (a[v] != '(') v++;
      v++;
      LD x = get_num(v);
      while (a[v] == ' ') v++;
      if (a[v] == ')') {
         v++;
         return new Ted(x);
      }
      else {
         Ted * l, * r;
         string s = get_string(v);
         l = rek(v);
         r = rek(v);
         return new Ted(x, s, l, r);
      }
   }

   Tr() {
      int m;
      cin >> m;
      cin.ignore();
      char s[1000];
      a = "";
      REP(x, m) {
         cin.getline(s, 1000);
         a += string(s);
      }
      //cout << "a: " << a << endl;
      int c = 0;
      root = rek(c);
   }

   LD play(set<string> & ce) {
      Ted * e = root;
      LD sol = 1;
      sol *= e->v;
      while (SIZE(e->s)) {
         if (ce.find(e->s) != ce.end()) e = e->l;
         else e = e->r;
         sol *= e->v;
      }
      return sol;
   }

   ~Tr() {
      delete root;
   }
};

void play() {
   Tr tr;
   //tr.root->print(0);
   int m;
   cin >> m;
   REP(x, m) {
      string s, t;
      int v;
      set<string> ce;
      cin >> s >> v;
      REP(y, v) {
         cin >> t;
         ce.insert(t);
      }
      cout << tr.play(ce) << endl;
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cout.precision(7);
   cout.setf(ios::fixed, ios::floatfield);
   int t;
   cin >> t;
   REP(x, t) {
      cout << "Case #" << x+1 << ":" << endl;
      play();
   }
   return 0;
}

