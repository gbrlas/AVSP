#include <iostream>
using namespace std;

int main() {
    int T, N, L, H;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N >> L >> H;
        int tab[N];
        for(int j = 0; j < N; j++) {
            cin >> tab[j];
        }

        bool ok = true;
        int num = 0;
        for(int j = L; j <= H; j++) {
            ok = true;
            for(int k = 0; k < N; k++) {
                if((j % tab[k] != 0) && (tab[k] % j != 0)) ok = false;
            }
            if(ok) {
                num = j;
                break;
            }
        }

        if(ok) {
            cout << "Case #" << (i + 1) << ": " << num << endl;
        } else cout << "Case #" << (i + 1) << ": NO" << endl;
    }
    return 0;
}
