#include <iostream>

using namespace std;

int T;

void solve(int n) {
    cout << "Case #" << n << ": ";
    
    int N;
    int a[1000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        res ^= a[i];
    }
    if (res != 0) {
        cout << "NO";
    } else {
        int sum = 0;
        int min = 0x7fffffff;
        for (int i = 0; i < N; i++) {
            sum += a[i];
            if (a[i] < min) {
                min = a[i];
            }
        }
        cout << (sum - min);
    }
    cout << endl;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
