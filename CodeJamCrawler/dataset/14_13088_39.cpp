#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    int t;
    cin >> t;
    
    int ra[17], rb[17];
    vector < int > ans;
    
    for (int l = 0; l < t; l++) {
        cout << "Case #" << l + 1 << ": ";
        ans.clear();
        int x, y, e;
        cin >> x;
        
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &e);
                ra[e] = i;
            }
                
        cin >> y;
        
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &e);
                rb[e] = i;
            }
                
        for (int k = 1; k <= 16; k++) {
            if (ra[k] + 1 == x && rb[k] + 1 == y)
                ans.push_back(k);
        }
        
        if (ans.size() == 0)
            cout << "Volunteer cheated!\n";
        else
        if (ans.size() > 1)
            cout << "Bad magician!\n";
        else
            cout << ans[0] << endl;
    }
}
