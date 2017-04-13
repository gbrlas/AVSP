#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
#define ll long long

map<vector<int>, ll> M;

ll high(int a) {
    ll ans = 0;
    while((1LL << ans) < a)
        ++ans;
    if((1LL << ans) > a)
        --ans;
    return ans;
}

int set(int a, int bit) {
    if((1LL << bit) & a)
        return 1;
    return 0;
}

ll ret(int a, int b, int k) {
    ll highestBit = max(high(a), max(high(b), high(k)));
    vector<int> v;
    v.push_back(a), v.push_back(b), v.push_back(k);

    if(M.find(v) != M.end())
        return M[v];
    
    ll &ans = M[v];
    ans = 0;

    if(a <= 5 && b <= 5) {
        for(int i = 0; i <= a; ++i)
            for(int j = 0; j <= b; ++j)
                if((i & j) <= k)
                    ans++;
        return ans;
    }

    int bitA = set(a, highestBit);
    int bitB = set(b, highestBit);
    int bitC = set(k, highestBit);
    
    int new_mask = (1LL << highestBit) - 1;

    if(bitC == 0) {
        if(bitA == 1 && bitB == 1) {
            ans += ret(new_mask, b & new_mask, k & new_mask);
            ans += ret(a & new_mask, new_mask, k & new_mask);
            ans += ret(new_mask, new_mask, k & new_mask);
        } else if(bitA == 1 && bitB == 0) {
            ans += ret(new_mask, b & new_mask, k & new_mask);
            ans += ret(a & new_mask, b & new_mask, k & new_mask);
        } else if(bitA == 0 && bitB == 1) {
            ans += ret(a & new_mask, new_mask, k & new_mask);
            ans += ret(a & new_mask, b & new_mask, k & new_mask);
        } 
    } else {
        if(bitA == 1 && bitB == 1) {
            ans += ret(new_mask & a, new_mask & b, new_mask & k);
            ans += ret(new_mask & a, new_mask, new_mask);
            ans += ret(new_mask, new_mask & b, new_mask);
            ans += ret(new_mask, new_mask, new_mask);
        } else ans = 1LL * (a + 1) * (b + 1);
    }
        
    return ans;
}

int main() {
    
    ifstream cin("testB.in");
    ofstream cout("testB.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        cout << "Case #" << t_case << ": ";
        int a, b, k; cin >> a >> b >> k;
        cout << ret(a - 1, b - 1, k - 1) << "\n";
    }

}
