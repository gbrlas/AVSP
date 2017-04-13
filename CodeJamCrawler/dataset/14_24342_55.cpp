#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    
    ifstream cin("testA.in");
    ofstream cout("testA.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        int n; cin >> n;
        
        vector<string> all(n);
        set<string> canonic;
        vector<int> v[1000];

        for(int i = 0; i < n; ++i) {
            cin >> all[i];
            string tmp;
            int now = 0;

            for(int j = 0; j < int(all[i].size()); ++j)
                if(j == 0 || (j > 0 && all[i][j] != all[i][j - 1])) {
                    v[i].push_back(now);
                    tmp += all[i][j];
                    now = 1;
                } else
                  ++now;
            v[i].push_back(now);
            canonic.insert(tmp);
        }
        
        cout << "Case #" << t_case << ": ";

        if(canonic.size() > 1) {
            cout << "Fegla Won\n";
            continue;
        }
        
        int ans = 0;

        for(int col = 0; col < (int) v[0].size(); ++col) {
            vector<int> to_solve;
            for(int i = 0; i < n; ++i)
                to_solve.push_back(v[i][col]);
            sort(to_solve.begin(), to_solve.end());
            int m = to_solve.size();

            int med = to_solve[m / 2];
            for(int i = 0; i < n; ++i)
                ans += abs(to_solve[i] - med);
            //cerr << col << " " << ans << "\n";
        }

        cout << ans << "\n";
    }
}
