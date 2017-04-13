#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int chk(int n, int m) {
    char buf[50];
    snprintf(buf, sizeof(buf), "%d%d", n, n);
    string sn = string(buf);
    snprintf(buf, sizeof(buf), "%d", m);
    string sm = string(buf);
//    cout << sn << "," << sm << endl;
    return (sn.find(sm) == string::npos) ? 0 : 1;
}

int main(int argc, char *argv[]) {
    int t, cnt = 0;
    scanf("%d\n", &t);
    while(cnt++ < t) {
        int a, b, n, m, ans = 0;
        scanf("%d%d\n", &a, &b);
        for(m = a+1; m <= b; m++) {
            for(n = a; n < m; n++) {
                ans += chk(n, m);
            }
        }
        printf("Case #%d: %d\n", cnt, ans);
    }
    return 0;
}

