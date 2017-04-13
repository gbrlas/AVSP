#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

struct event {
  ll vertex;
  ll count;
  bool start;
  ll endpoint;
  event(ll _vertex, ll _ep, ll _count, bool _start);
  bool operator<(event b) const;
};

event::event(ll _vertex, ll _ep, ll _count, bool _start) : vertex(_vertex), endpoint(_ep), start(_start), count(_count) {}

bool event::operator<(event b) const {
  return vertex < b.vertex || (vertex == b.vertex && ((start && !b.start) || (start && b.start && (count < b.count || (count == b.count && endpoint < b.endpoint)))));
}

ll arithm_progr(ll a1, ll d, ll n) {
  return (2 * a1 + d * (n - 1)) * n / 2;
}

const ll modulo = 1000002013;

ll norm (ll a) {
  //  return a;
  return a < 0 ? a + modulo : a % modulo;
}

void test(ll t) {
  cout << "Case #" << t << ": ";
  ll n, m;
  cin >> n >> m;
  vector<event> events;
  ll original_price = 0;
  for (ll i = 0; i < m; i++) {
    ll o, e, p;
    cin >> o >> e >> p;
    events.push_back(event(o, e, p, true));
    events.push_back(event(e, e, p, false));
    original_price = norm(original_price + arithm_progr(n, -1, e-o) * p);
  }
  sort(events.begin(), events.end());
  map<ll, ll> people;
  map<ll, ll> tickets;
  ll price = 0;
  for (vector<event>::iterator p = events.begin(); p != events.end(); p++) {
    if (p->start) {
      people[p->endpoint] += p->count;
      tickets[p->vertex] += p->count;
    }
    else {
      ll cnt = p->count;
      for (map<ll, ll>::reverse_iterator pt = tickets.rbegin(); pt != tickets.rend(); pt++) {
	ll ticket = pt->first, count = pt->second;
	if (cnt > count) {
	  tickets[ticket] = 0;
	  price = norm(price + arithm_progr(n, -1, p->endpoint - ticket) * count);
	  cnt -= count;
	}
	else {
	  tickets[ticket] -= cnt;
          price = norm(price + arithm_progr(n, -1, p->endpoint - ticket) * cnt);
	  cnt = 0;
	  break;
	}
      }
    }
  }
  cout << original_price - price << endl;
}

int main() {
  ll t; cin >> t;
  for (ll i = 0; i < t; i++)
    test(i + 1);
}
