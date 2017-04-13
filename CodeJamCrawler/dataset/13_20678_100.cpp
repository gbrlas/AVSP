#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ok(const vector<vector<int> >& a) {
    const int n = a.size(), m = a[0].size();
    for (int i0 = 0; i0 < n; ++i0) for (int j0 = 0; j0 < m; ++j0) {
        const int h = a[i0][j0];
        bool ok = true;
        for (int i = 0; i < n; ++i) if (a[i][j0] > h) {
            ok = false;
            break;
        }
        if (ok)
            continue;
        ok = true;
        for (int j = 0; j < m; ++j) if (a[i0][j] > h) {
            ok = false;
            break;
        }
        if (!ok)
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;
        vector<vector<int> > a(N);
        for (int i = 0; i < N; ++i) {
            a[i].resize(M);
            for (int j = 0; j < M; ++j)
                cin >> a[i][j];
        }
        string result = ok(a) ? "YES" : "NO";
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
