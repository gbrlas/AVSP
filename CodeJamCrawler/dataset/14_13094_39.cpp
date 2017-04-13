#include <iostream>
#include <vector>

using namespace std;

const double EPS = 1e-7;

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    
    int t;
    cin >> t;
    double c, f, x, ans;
    int k;
    
    for (int l = 0; l < t; l++) {
        cout << "Case #" << l + 1 << ": ";
        cin >> c >> f >> x;     
           
        k = int(x/c - 2.0/f + EPS);
        
        if (k < 0)
            k = 0;
        
        cout.setf(ios::fixed);
        cout.precision(7);
        
        ans = 0;
        
        for (int i = 0; i < k; i++)
            ans += c / (2 + f * i);            
        ans += x / (2 + f * k);
        
        cout << ans << endl;
    }
}
