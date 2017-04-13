#include <iostream>
#include <cstdio>

using namespace std;

int buf[1000];
int main(void) {
    int T, N, M;
    cin >> T;
    for (int ti=1; ti<=T; ++ti) {
        cin >> N >> M;
        for (int i=1; i<N; ++i) {
            buf[i] = 0; }
        int a, b, c;
        int as0 = 0;
        for (int i=0; i<M; ++i) { 
            cin >> a >> b >> c;
            as0 += (N+N+1+a-b)*(b-a)/2*c;
            for (int j=a; j<b; ++j) {
                buf[j] += c;
            }
        }
        int as1 = 0;
        int flag = 1;
        while (flag) {
            flag = 0;
            int i, j;
            for (i=1; i<=N; ++i) {
                if (buf[i]) {
                    flag =1;
                    break;
                }
            }
            j = i;
            while (j<=N && buf[j]) {
                --buf[j];
                ++j;
            }
            if (flag) {
                as1 += (N+N+1+i-j)*(j-i)/2;
            }
        } 
        cout << "Case #" << ti << ": " << as0 - as1 << endl;
    }
    return 0;
}
