#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        long long A, B, K;
        cin >> A >> B >> K;
        long long cnt = 0;
        for(long long j = 0; j < A; ++j) {
            for(long long k = 0; k < B; ++k) {
                long long tmp = j & k;
                //cout << tmp << endl;
                if(tmp < K) {
                    cnt++;
                    //cout << j << " " << k << endl;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << cnt << endl;
    }
    return 0;
}