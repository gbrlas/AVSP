#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        cout<<"Case #"<<tt<<": ";
        ll n, p;
        cin>>n>>p;
        ll pos = (1 << n) - p;
        ll a1 = -1, a2 = -1;
        if (p == 1) {
            a1 = a2 = 0;
        } else if (pos == 0) {
            a1 = a2 = (1 << n) - 1;
        } else {
            ll ct0 = 0, ct1 = 0;
            while (((1 << (n - ct0 - 1)) & pos) == 0) {
                ++ct0;
            }
            while (((1 << (n - ct1 - 1)) & pos) > 0) {
                ++ct1;
                pos -= (1 << (n - ct1));
            }
            if (pos) {
                ++ct1;
            }
            a1 = (1 << (ct0 + 1)) - 2;
            a2 = (1 << n) - (1 << ct1);
        }
        cout<<a1<<" "<<a2<<endl;
    }
    return 0;
}

