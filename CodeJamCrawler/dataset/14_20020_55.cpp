#include <bits/stdc++.h>
using namespace std;
const int N = 4;

int T;
int cards[N+1][N+1];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int ans1; scanf("%d", &ans1);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &cards[i][j]);
        int ans2; scanf("%d", &ans2);
        int numanswers = 0;
        int res = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int a;
                scanf("%d", &a);
                if (i+1 != ans2) continue;
                else {
                    for (int z = 0; z < 4; z++) 
                        if (cards[ans1-1][z] == a) {
                            numanswers++;
                            res = a;
                        }
                }
           }
        if (numanswers == 0)
            printf("Case #%d: Volunteer cheated!\n", t);
        else if (numanswers == 1)
            printf("Case #%d: %d\n", t, res);
        else
            printf("Case #%d: Bad magician!\n", t);
    }
    return 0;
}
