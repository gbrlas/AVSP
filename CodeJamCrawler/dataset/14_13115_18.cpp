#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    cin >> T;
    
    int a, b, k;
    
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t + 1 << ": ";
        
        int ans = 0;
        
        cin >> a >> b >> k;
        
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i & j) < k)
                    ans++;
                    
        cout << ans << endl;
    }
}
