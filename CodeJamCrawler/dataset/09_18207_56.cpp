#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <numeric>
#include <iterator>
#include <bitset>
#include <cmath>
 
#define foreach(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        string s1, ans;
        cin >> s1;

        ans = s1;
        next_permutation(ans.begin(), ans.end());
        
        cout << "Case #" << i+1 << ": ";
        if(ans > s1) {
            cout << ans << endl;
        } else {
            if(ans[0] == '0') {
                int p;
                for(p = 0; ans[p] == '0'; ++p);
                swap(ans[0], ans[p]);
            }
            cout << ans[0] << "0" << ans.substr(1) << endl;
        }
    }

    return 0;
}
