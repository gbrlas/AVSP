#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int T, ans1, ans2, ans;
    int arr1[4][4];
    int arr2[4][4];
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> ans1;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                cin >> arr1[j][k];
            }
        }
        cin >> ans2;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                cin >> arr2[j][k];
            }
        }
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (arr1[ans1-1][j] == arr2[ans2-1][k]) {
                    ans = arr1[ans1-1][j];
                    cnt++;
                }
            }
        }
        if (cnt == 1) {
            printf("Case #%d: %d\n", i, ans);
        } else if (cnt > 1) {
            printf("Case #%d: Bad magician!\n", i);
        } else {
            printf("Case #%d: Volunteer cheated!\n", i);
        }

    }
    return 0;
}
