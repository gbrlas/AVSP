#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin>>T;

    for (int tt = 1; tt <= T; ++tt) {
        int L, N, C;
        ll t;
        cin>>L>>t>>N>>C;

        vector<int> a(C);
        for (int i = 0; i < C; i++) {
            cin>>a[i];
            a[i] *= 2;
        }

        vector<vector<int> > dp(N + 1, vector<int>(L + 1, 0));
        for (int i = 1; i <= N; ++i) {
            int index = (i - 1) % C;
            for (int j = L; j >= 0; j--) {
                dp[i][j] = dp[i - 1][j] + a[index];
                if (j < L && dp[i - 1][j + 1] + a[index] >= t) {
                    ll d = max((ll)0, t - dp[i - 1][j + 1]);
                    dp[i][j] = min(dp[i][j], (int)(dp[i - 1][j + 1] + d + (a[index] - d) / 2));
                }
            }
        }

        cout<<"Case #"<<tt<<": "<<dp[N][0]<<endl;
    }

    return 0;
}
