#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include <math.h>

using namespace std;

//ifstream fin("../D-sample.in");
//#define cin fin

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int K, N;
        cin >> K >> N;
        vector<int> key_count(410, 0);
        for (int i = 0; i < K; ++i) {
            int key;
            cin >> key;
            key_count[key]++;
        }
        vector<int> key_type(N);
        vector<vector<int> > keys_inside(N);
        for (int i = 0; i < N; ++i) {
            int count;
            cin >> key_type[i] >> count;
            for (int j = 0; j < count; ++j) {
                int type;
                cin >> type;
                keys_inside[i].push_back(type);
            }
        }
        vector<vector<int> > adj(1<<N);
        for (int mask = 0; mask < (1<<N); ++mask) {
            vector<int> cur_count = key_count;
            for (int i = 0; i < N; ++i) if (mask & (1<<i)) {
                cur_count[key_type[i]]--;
                for (size_t j = 0; j < keys_inside[i].size(); ++j)
                    cur_count[keys_inside[i][j]]++;
            }
            for (int i = 0; i < N; ++i) if (!(mask & (1<<i)) && cur_count[key_type[i]] > 0)
                adj[mask].push_back(mask | (1<<i));
        }

        const int all = (1<<N) - 1;
        vector<int> back(1<<N, -2);
        list<int> q;
        q.push_back(0);
        back[0] = -1;
        while (!q.empty()) {
            int mask = q.front();
            q.pop_front();
            if (mask == all)
                break;
            for (size_t i = 0; i < adj[mask].size(); ++i) {
                int next = adj[mask][i];
                if (back[next] == -2) {
                    back[next] = mask;
                    q.push_back(next);
                }
            }
        }

        cout << "Case #" << t << ": ";

        if (back[all] == -2) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> path;
        path.push_back(all);
        while (path.back() != 0) {
            int next = back[path.back()];
            path.push_back(next);
        }

        for (size_t i = path.size()-1; i >= 1; --i) {
            int deg2 = path[i] ^ path[i-1];
            int d = 0;
            while (deg2 > 0) {
                deg2 /= 2;
                d++;
            }
            cout << d << " ";
        }

        cout << endl;

    }
    return 0;
}
