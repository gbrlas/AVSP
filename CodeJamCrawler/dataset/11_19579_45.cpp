#include <iostream>

using namespace std;

char getHallway() {
    char c = '\0';
    while (cin >> c) {
        if (c == 'B' || c == 'O') break;
    }
    return c;
}

int getButton() {
    int n;
    cin >> n;
    return n;
}

void solve(int n) {
    cout << "Case #" << n << ": ";
    
    int N;
    char h[100];
    int b[100];
    cin >> N;
    for (int i = 0; i < N; i++) {
        h[i] = getHallway();
        b[i] = getButton();
    }
    
    int cnt = 0;
    int idx = 0;
    int ib = 1;
    int io = 1;
    while (idx < N) {
        cnt++;
        if (h[idx] == 'B') {
            if (ib == b[idx]) {
                idx++;
            } else {
                if (ib < b[idx]) {
                    ib++;
                } else {
                    ib--;
                }
            }
            int next = -1;
            for (int i = idx; i < N; i++) {
                if (h[i] == 'O') {
                    next = i;
                    break;
                }
            }
            if (next != -1) {
                if (io < b[next]) {
                    io++;
                } else if (io > b[next]) {
                    io--;
                }
            }
            continue;
        }
        if (h[idx] == 'O') {
            if (io == b[idx]) {
                idx++;
            } else {
                if (io < b[idx]) {
                    io++;
                } else {
                    io--;
                }
            }
            int next = -1;
            for (int i = idx; i < N; i++) {
                if (h[i] == 'B') {
                    next = i;
                    break;
                }
            }
            if (next != -1) {
                if (ib < b[next]) {
                    ib++;
                } else if (ib > b[next]) {
                    ib--;
                }
            }
            continue;
        }
    }
    cout << cnt;
    
    cout << endl;
}

int T;

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
