#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    
    //ifstream cin("testA.in");
    //ofstream cout("testA.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        cout << "Case #" << t_case << ": ";
        int n, x; cin >> n >> x;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> v[i];
        sort(v.rbegin(), v.rend());
        
        int ans = n + 1;

        for(int fixed = 0; fixed < n; ++fixed) {
            int it = n - 1;
            vector<int> taken(n, 0);
            bool ok = true;
            int tmp = 0;

            for(int j = fixed; j < n; ++j) {
                if(taken[j])
                    continue;
                while(it > j && (v[it] + v[j] > x || taken[it]))
                    --it;
                if(it <= fixed) {
                    ++tmp;
                    continue;
                }
                taken[it] = 1;
                ++tmp;
            }

            if(ok)
                ans = min(ans, tmp + fixed);
        }
        cout << ans << "\n";
    }
}
