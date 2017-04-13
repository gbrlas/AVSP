#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

int solve(vector<double> &a, vector<double> &b) {
    int ans = 0;
    set<double> S;
    for(auto tmp : b)
        S.insert(tmp);

    for(auto tmp : a) {
        auto match = S.upper_bound(tmp);
        if(match == S.end()) {
            ans++;
            S.erase(S.begin());
        } else
        S.erase(match);
    }

    return ans;
}

int main() {
    
    ifstream cin("testD.in");
    ofstream cout("testD.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        cout << "Case #" << t_case << ": ";
        int n; cin >> n;
        vector<double> A(n, 0), B(n, 0);

        for(int i = 0; i < n; ++i)
            cin >> A[i];
        for(int i = 0; i < n; ++i)
            cin >> B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int best = 0;

        for(int i = 0; i < n; ++i) {
            vector<double> newA(A.begin() + i, A.end());
            vector<double> newB(B.begin(), B.end() - i);
            int tmp = 0;
            for(int j = 0; j < n - i; ++j)
                if(newA[j] > newB[j])
                    tmp++;
            if(tmp > best)
                best = tmp;
        }

        cout << best << " " << solve(A, B) << "\n";
        if(t_case == 4) {
            for(auto tmp : A)
                cerr << tmp << " ";
            cerr << "\n";
            for(auto tmp : B)
                cerr << tmp << " ";
        }
    }

}
