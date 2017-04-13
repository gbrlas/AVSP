#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 2000000000;
#define REP(i, n) for(int i = 0;i<(n);i++)
#define ALL(u) (u).begin(),(u).end()

typedef long long LL;
typedef pair<LL,LL> PI;

LL calcworst(LL val, LL count) {
    LL pos = val, num = count;
    LL res = 0;
    while(pos > 0) {
        pos = (pos - 1)/2;
        num /= 2;
        res = (res * 2) + 1;
    }
    while(num > 1) {
        num /= 2;
        res = (res * 2) + 0;
    }
    return res;
}

LL calcbest(LL val, LL count) {
    return count - 1 - calcworst(count - val - 1, count);
}

LL findres(LL N, LL P, LL (*calc)(LL,LL)) {
    LL low = 0, high = ((1LL)<<N);
    while(high - low > 1) {
        LL test = (low + high)/2;
        if (calc(test, ((1LL)<<N)) >= P) high = test;
        else low = test;
    }
    return low;
}

void solve(int cas) {
    LL N, P;
    cin >> N >> P;
    LL low = findres(N, P, calcworst);
    LL high = findres(N, P, calcbest);
    cout << "Case #" << cas << ": " << low << " " << high << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i<=T;i++) solve(i);
    return 0;
}

