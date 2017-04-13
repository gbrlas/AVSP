#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    int A[4][4];
    int row_a;
    int B[4][4];
    int row_b;
    int cnt[20];
    cin >> t;

    for (int Case = 1; Case <= t; ++Case) {
        memset(cnt, 0, sizeof(cnt));

        cin >> row_a;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> A[i][j];
            }
        }

        cin >> row_b;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> B[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            cnt[A[row_a-1][i]] += 1;
        }
        for (int i = 0; i < 4; ++i) {
            cnt[B[row_b-1][i]] += 1;
        }


        int ans = -1;
        int cnt_dup = 0;
        for (int i = 1; i <= 16; ++i) {
            if (cnt[i] == 2) {
                cnt_dup += 1;
                ans = i;
            }
        }


        printf("Case #%d: ", Case);

        if (ans == -1)
            printf("Volunteer cheated!\n");
        else if (cnt_dup == 1) 
            printf("%d\n", ans);
        else 
            printf("Bad magician!\n");
    }


    return 0;
}
