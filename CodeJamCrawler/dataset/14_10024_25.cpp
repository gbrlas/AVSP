#include <stdio.h>
#include <algorithm>
using namespace std;

int T, R1, R2;
int arr1[5][5];
int arr2[5][5];

int main() {
    scanf("%d", &T);
    for (int _42=1; _42<=T; _42++) {
        scanf("%d", &R1);

        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                scanf("%d", &arr1[i][j]);

        scanf("%d", &R2);

        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                scanf("%d", &arr2[i][j]);

        printf("Case #%d: ", _42);

        int card = -1;
        bool bad_mag = false;

        for (int col=0; col<4; col++) {
            int tmp_card = arr1[R1-1][col];

            for (int j=0; j<4; j++)
                if (arr2[R2-1][j] == tmp_card) {
                    if (card == -1) card = tmp_card;
                    else bad_mag = true;
                }
        }

        if (card != -1) {
            if (!bad_mag) printf("%d\n", card);
            else printf("Bad magician!\n");
        }
        else printf("Volunteer cheated!\n");
    }

    return 0;
}
