#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int t; scanf("%d", &t);
    for (int _ = 1; _ <= t; ++_) {
        int N, K; scanf("%d%d", &N, &K);
        vector<int> inp;
        vector<int> was(N, 0);
        for (int i = 0; i < N; ++i) {
            int s; scanf("%d", &s); inp.push_back(s);
        }
        sort(inp.rbegin(), inp.rend());
        int cnt = 0;
        for (int i = 0; i < inp.size(); ++i) {
            if (was[i]) continue;
            int taken = inp[i]; was[i] = true; ++cnt;
            for (int j = i + 1; j < inp.size(); ++j) {
                if (!was[j] && taken + inp[j] <= K) {
                    was[j] = true;
                    break;
                }
            }
        }
        cout << "Case #" << _ << ": " << cnt << endl;
    }
    return 0;
}
