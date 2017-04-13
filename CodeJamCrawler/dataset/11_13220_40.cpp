#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return (b != 0)? gcd(b, a % b): a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int T;
    cin>>T;

    for (int tt = 1; tt <= T; ++tt) {
        int N, L, H;
        cin>>N>>L>>H;

        vector<int> fs(N);
        for (int i = 0; i < N; ++i) {
            cin>>fs[i];
        }

        int ans = -1;
        for (int i = L; i <= H; ++i) {
            bool ok = true;
            for (int j = 0; j < N; ++j) {
                if (fs[j] % i == 0 || i % fs[j] == 0) {
                    continue;
                }
                ok = false;
                break;
            }
            if (ok) {
                ans = i;
                break;
            }
        }

        cout<<"Case #"<<tt<<": ";
        if (ans == -1) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<ans<<endl;
        }
    }

    return 0;
}
