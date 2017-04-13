#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

int main() {
    int nt,nteste=1;
    vector<int> ans;
    bool us[20];
    cin>>nt;
    while (nt--) {
        memset(us,false,sizeof(us));
        ans.clear();
        int r;
        cin>>r;
        r--;
        for (int i=0; i<4; i++) {
            int d;
            for (int j=0; j<4; j++) {
                cin>>d;
                if (i == r) us[d] = true;
            }
        }
        cin>>r;
        r--;
        for (int i=0; i<4; i++) {
            int d;
            for (int j=0; j<4; j++) {
                cin>>d;
                if (i == r && us[d]) ans.push_back(d);
            }
        }
        
        printf("Case #%d: ",nteste++);
        if (ans.size() == 0) printf("Volunteer cheated!\n");
        else if (ans.size() == 1) printf("%d\n",ans[0]);
        else printf("Bad magician!\n");
    }
    
    return 0;
}
