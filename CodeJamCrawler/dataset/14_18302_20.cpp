#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dump(vector<int> v)
{
    cout << "[";
    bool first = true;
    for (int e : v) {
        cout << (first ? "" : ", ") << e;
        first = false;
    }
    cout << "]" << endl;
}

int solve()
{
    int N;
    cin >> N;
    vector<int>A(N);
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }

    set<vector<int>> cur_round{A};
    set<vector<int>> next_round;
    for (int count = 0; true; count++) {
        //cout << count << endl;
        for (auto v : cur_round) {
            int start, end;
            for (start = 0; start < N - 1 && v[start] < v[start + 1]; start++) {}
            for (end = N - 1; end >= 1 && v[end - 1] > v[end]; end--) {}
            //dump(v);
            //cout << start << ", " << end << endl;
            if (start >= end) {
                return count;
            }
            for (int i = start - 1; i < end; i++) {
                if (i < 0 || i >= N - 1) {
                    continue;
                }
                auto vv = v;
                swap(vv[i], vv[i + 1]);
                next_round.insert(vv);
            }
        }
        cur_round.clear();
        swap(cur_round, next_round);
    }

}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t < T + 1; t++) {
        int s = solve();
        cout << "Case #" << t << ": " << s << endl;
    }
}
