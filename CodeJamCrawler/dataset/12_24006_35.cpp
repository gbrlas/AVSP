#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    freopen("b2.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, s, p;
        cin >> n >> s >> p;
        int sc = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int pt;
            cin >> pt;
            switch (pt % 3) {
                case 0:
                    if (pt / 3 >= p) {
                        res++;
                    } else if (pt && sc < s && pt / 3 + 1 >= p) {
                        res++;
                        sc++;
                    }
                    break;
                case 1:
                    if (pt / 3 + 1 >= p) {
                        res++;
                    }
                    break;
                case 2:
                    if (pt / 3 + 1 >= p) {
                        res++;
                    } else if (sc < s && pt / 3 + 2 >= p) {
                        sc++;
                        res++;
                    }
                    break;
            }
        }
        printf("Case #%d: %d\n", t+1, res);
    }

    return 0;
}
