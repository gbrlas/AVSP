#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10;
const int K = 26;

string s[N];
int n, curr[N], pred[K];

bool check() {
    for (int i = 0; i < K; i++)
        pred[i] = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[curr[i]].size(); j++) {
            int c = s[curr[i]][j] - 'a';
            if (pred[c] != -1 && pred[c] != cnt - 1)
                return 0;
            pred[c] = cnt++;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);
    int t;
    cin >> t;
    for (int l = 0; l < t; l++) {
        cout << "Case #" << l + 1 << ": ";
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            curr[i] = i;
        int ans = 0;
        do { ans += check(); }
        while (next_permutation(curr, curr + n));
        cout << ans << endl;
    }
    return 0;
}
