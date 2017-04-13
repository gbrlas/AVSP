#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T;
    cin>>T;

    for (int k = 1; k <= T; k++) {
        int N;
        cin>>N;

        int c = 0;
        for (int i = 0; i < N; i++) {
            int a;
            cin>>a;
            a--;
            if (a != i) {
                c++;
            }
        }

        printf("Case #%d: %.06f\n", k, (double)c);
    }

    return 0;
}
