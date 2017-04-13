#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ifstream cin("testB.in");
    ofstream cout("testB.out");

    int t; cin >> t;

    for(int t_case = 1; t_case <= t; ++t_case) {
        cout << "Case #" << t_case << ": ";
        int a, b, k; cin >> a >> b >> k;
        int ans = 0;
        for(int i = 0; i < a; ++i)
            for(int j = 0; j < b; ++j)
                if((i & j) < k)
                    ans++;
        cout << ans << "\n";
    }

}
