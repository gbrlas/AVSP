#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

const int N = 100;
const int INF = 1e9;

string s[N];

int cnt[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("outputAa.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        string need;
        bool bad = 0;
        for (int i = 0; i < n; i++) {
            string now;
            int to = 0;
            for (int j = 0; j < s[i].size(); ) {
                now += s[i][j];
                int l = j;
                for (; l < s[i].size() && s[i][l] == s[i][j]; l++);
                cnt[i][to++] = l - j;
                j = l;
            }
            if (need.empty())
                need = now;
            if (now != need) {
                bad = 1;
                break;
            }
        }
        if (bad) {
            cout << "Fegla Won" << endl;
            continue;
        }
        int ans = 0;
        for (int j = 0; j < need.size(); j++) {
            int mn = INF;
            for (int k = 1; k <= N; k++) {
                int now = 0;
                for (int i = 0; i < n; i++)
                    now += abs(cnt[i][j] - k);
                mn = min(mn, now);
            }
            ans += mn;
        }
        cout << ans << endl;
    }
    return 0;
}
