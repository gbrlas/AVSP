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

int groups[1010];
long long sum[1010];

int main() {
    int T, times_per_day, coaster_size, num_groups;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        scanf("%d%d%d", &times_per_day, &coaster_size, &num_groups);
        sum[0] = 0;
        for(int i = 0; i < num_groups; ++i) {
            scanf("%d", &groups[i]);
            sum[i + 1] = sum[i] + groups[i];
        }
        sum[num_groups + 1] = 1000000000000000000ll;
        long long result = 0;
        if(sum[num_groups] <= coaster_size)
            result = times_per_day * sum[num_groups];
        else {
            int at = 1, pos;
            long long need;
            for(int i = 0; i < times_per_day; ++i) {
                need = coaster_size;
                if(sum[num_groups] - sum[at - 1] <= need) {
                    need -= sum[num_groups] - sum[at - 1];
                    result += sum[num_groups] - sum[at - 1];
                    at = 1;
                    //cout << "less" << endl;
                }
                //cout << "need " << need << endl;
                pos = upper_bound(sum + at + 1, sum + num_groups + 1, need + sum[at - 1]) - sum - 1;
                //cout << "pos = " << pos << endl;
                if(need >= groups[pos - 1]) {
                    result += sum[pos] - sum[at - 1];
                    if((at = ++pos) > num_groups)
                        at = 1;
                }
                //cout << at << " " << result << endl;
            }
        }
        cout << "Case #" << (t + 1) << ": " << result << endl;
    }
    return 0;
}
