#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int matrix1[4][4], matrix2[4][4], cnt[17];

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int p1, p2;
        scanf("%d", &p1);
        for (int j = 0; j < 4; j++)
            for (int d = 0; d < 4; d++)
                scanf("%d", &matrix1[j][d]);
        scanf("%d", &p2);
        for (int j = 0; j < 4; j++)
            for (int d = 0; d < 4; d++)
                scanf("%d", &matrix2[j][d]);

        for (int j = 0; j < 4; j++)
        {
            cnt[matrix1[p1 - 1][j]]++;
            cnt[matrix2[p2 - 1][j]]++;
        }

        int answer = -1;
        for (int j = 1; j <= 16; j++)
        {
            if (cnt[j] == 2)
            {
                if (answer == -1)
                    answer = j;
                else
                    answer = -2;
            }

            cnt[j] = 0;
        }

        printf("Case #%d: ", i + 1);
        if (answer > 0)
            printf("%d\n", answer);
        else if (answer == -1)
            printf("Volunteer cheated!\n");
        else
            printf("Bad magician!\n");
    }


    return 0;
}
