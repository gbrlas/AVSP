#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("outputB.txt", "w", stdout);
    int t, a, b, k;
    cin >> t;
    for (int l = 0; l < t; l++){
        cin >> a >> b >> k;
        int ans = 0;
        for (int i = 0; i < a; i++){
            for (int j = 0; j < b; j++){
                if ((i & j) < k)
                    ans++;
            }
        }
        cout << "Case #" << l + 1 << ": " << ans << endl;
    }
    return 0;
}
