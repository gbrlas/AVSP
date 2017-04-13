#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <utility>
#include <complex>

#define foreach(i, s, w) for(int i = (s); i < int((w).size()); ++i)

using namespace std;

int main() {
    int T, N, K;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        cin >> N >> K;
        int state = K % (1 << N);
        if(state == (1 << N) - 1)
            printf("Case #%u: ON\n", t + 1);
        else
            printf("Case #%u: OFF\n", t + 1);
    }
    return 0;
}
