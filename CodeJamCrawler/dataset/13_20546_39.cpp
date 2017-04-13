#include <iostream>
#include <map>
#include <set>
using namespace std;
const int M = 1000002013;
long long T, n, m, o, e, p, norm, res;
set<long long> s, s2;
map<long long, long long> in, out, cards;
long long f(long long a, long long b) {
    return (n*(n+1)/2-(n-(b-a-1))*(n-(b-a))/2)%M;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> n >> m;
        while (m--) {
            cin >> o >> e >> p;
            norm += (p*f(o,e))%M;
            norm %= M;
            in[o] += p;
            out[e] += p;
            s.insert(o);
            s.insert(e);
        }
        for (set<long long>::iterator i=s.begin(); i != s.end(); i++) {
            cards[*i] += in[*i];
            s2.insert(*i);
            o = out[*i];
            if (o != 0)
            for (set<long long>::reverse_iterator j=s2.rbegin(); j!=s2.rend(); j++) {
                if (cards[*j] < o) {
                    res += (cards[*j]*f(*j,*i))%M;
                    o -= cards[*j];
                    cards[*j] = 0;
                    res %= M;
                } else {
                    res += (o*f(*j,*i))%M;
                    cards[*j] -= o;
                    o = 0;
                    res %= M;
                    break;
                }
            }
        }
        cout << "Case #" << t << ": " << (norm-res+2*M)%M << "\n";
        res=norm=0;
        s.clear();
        s2.clear();
        in.clear();
        out.clear();
        cards.clear();
    }
    return 0;
}
