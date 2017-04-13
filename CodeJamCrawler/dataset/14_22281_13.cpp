#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

int main() {
    long long N;
    cin >> N;
    for(long long kase = 0; kase < N; kase++) {
        long long n; cin >> n;
        long long x; cin >> x;
        long long *w = new long long[x+1];
        for(long long j=0; j<=x; j++) {
            w[j] = 0;
        }
        for(long long j=0; j<n; j++) {
            long long z; cin >> z;
            w[z]++;
        }
        long long ans = 0;
        for(long long i=x; i>=0; i--) {
            for(long long j=x-i; j>=0; j--) {
                while(w[i]>0 && w[j]>0 && i!=j || w[i]>1 && i==j) {
                    w[j]--; w[i]--;
                    // cerr << i << " " << j << " / " << x << endl;
                    ans++;
                }
            }
            ans += w[i];
            w[i] = 0;
        }
        cout << "Case #" << kase+1 << ": " << ans << endl;
    }
    return 0;    
}
