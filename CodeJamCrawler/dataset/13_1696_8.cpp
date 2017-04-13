#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf


class Event {
public:
  Event (int tstation, int tp, bool tenter):
    station(tstation), p(tp), enter(tenter) {}
  bool operator< (const Event& e) const {
    if (station < e.station) return true;
    else if (station > e.station) return false;
    else return enter;
  }
  bool operator== (const Event& e) const {
    if (station == e.station && enter == e.enter) return true;
    return false;
  }

  int station, p;
  bool enter;
};


ll N, M;
ll org_price, new_price;
set<Event> event_queue;
vector<int> current_starts;

void genEvent(int o, int e, int p) {
  // find event.
  set<Event>::iterator pe;
  int totalp;

  // enter.
  pe = event_queue.find(Event(o, p, true));
  totalp = p;
  if (pe != event_queue.end()) {
    totalp = pe->p + p;
    event_queue.erase(pe);
  }
  event_queue.insert(Event(o, totalp, true));

  // leave.
  pe = event_queue.find(Event(e, p, false));
  totalp = p;
  if (pe != event_queue.end()) {
    totalp = pe->p + p;
    event_queue.erase(pe);
  }
  event_queue.insert(Event(e, totalp, false));
}

int getPrice(int o, int e) {
  if (o == e) return 0;
  int dist = e - o;
  return (N + N - dist + 1) * (dist) / 2;
}

void input() {
  cin >> N >> M;
  event_queue.clear();
  current_starts.clear();
  org_price = 0;
  new_price = 0;

  int o, e, p;
  forn(i, M) {
    cin >> o >> e >> p;
    genEvent(o, e, p);
    org_price += (getPrice(o, e) * p);
  }
}

void process() {
  fori(it, event_queue) {
    if (it->enter) {
      forn(i, it->p) {
        current_starts.push_back(it->station);
      }
    } else {
      forn(i, it->p) {
        int o = current_starts.back();
        current_starts.pop_back();
        new_price += getPrice(o, it->station);
      }
    }
  }
}

void dump() {
  cout << endl;
  fori(it, event_queue) {
    cout << it->station << " " << it->p << " "
        << (it->enter ? "enter" : "leave") << endl;
  }
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);
        input();
        //dump();
        process();
        cout << (org_price - new_price) % 1000002013;
        printf("\n");
    }

    return 0;
}

