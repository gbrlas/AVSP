#include <stdio.h>
#define notcomplete 92
#define xwon 93
#define owon 94
#define draw 95

int result(char [4][4]);
int main()
{
        char arr[4][4];
        char c, str[5];
        unsigned t, i, j, m;
        int k;
        scanf("%d", &t);
        //fflush(stdin);
        for (m = 1; m <= t; m ++) {
                for (i = 0; i < 4; i++) {
                        scanf(" %[^\n]", arr[i]);
                }
		scanf("%c", &c);
		//fflush(stdin);
                k = result(arr);
		//k = 92;
                switch (k) {
                case notcomplete:
                        printf("Case #%u: Game has not completed\n", m);
                        break;
                case xwon:
                        printf("Case #%u: X won\n", m);
                        break;
                case owon:
                        printf("Case #%u: O won\n", m);
                        break;
                case draw:
                        printf("Case #%u: Draw\n", m);
                        break;
                }//printf("%u\n", m);

        }

        return 0;
}
int result(char arr[4][4])
{
        char c;
        int n, t, i, res, exp, j;
        /**row-wise check**/
        for (i = 0; i < 4; i ++) {
                n = 0;
                c = arr[i][0];
                exp = 0;
                if (c == '.') {
                        n = -1;
                }
                if (c == 'T') {
                        c = arr[i][1];
                        exp = 1;
                }
                for (j = 0; j < 4; j ++) {
                       if (arr[i][j] != c) {
                                if (arr[i][j] == 'T' && exp == 0) {
                                        exp = 1;
                                } else {
                                        n = 1;
                                }
                       }

                }
                if (n == -1) {
                        return notcomplete;
                }
                if (n == 0) {
                        if (c == 'X') {
                                return xwon;
                        } else if (c == 'O') {
                                return owon;
                        }
                }
        }
        /**column-wise check**/
        for (i = 0; i < 4; i ++) {
                n = 0;
                c = arr[0][i];
                exp = 0;
                if (c == '.') {
                        n = -1;
                }
                if (c == 'T') {
                        c = arr[1][i];
                        exp = 1;
                }
                for (j = 0; j < 4; j ++) {
                        if (arr[j][i] != c) {
                                if (arr[j][i] == 'T' && exp == 0) {
                                        exp = 1;
                                } else {
                                        n = 1;
                                }
                        }
                }
                if (n == -1) {
                        return notcomplete;
                }
                if (n == 0) {
                        if (c == 'X') {
                                return xwon;
                        } else if (c == 'O') {
                                return owon;
                        }
                }
        }
        /**rt-diagonal check**/
        for (i = 0; i < 1; i ++) {
                n = 0;
                c = arr[0][0];
                exp = 0;
                if (c == '.') {
                        n = -1;
                }
                if (c == 'T') {
                        c = arr[1][1];
                        exp = 1;
                }
                for (j = 0; j < 4; j ++) {
                        if (arr[i+j][i+j] != c) {
                                        if (arr[i+j][i+j] == 'T' && exp == 0) {
                                        exp = 1;
                                } else {
                                        n = 1;
                                }
                        }
                }
                if (n == -1) {
                        return notcomplete;
                }
                if (n == 0) {
                        if (c == 'X') {
                                return xwon;
                        } else if (c == 'O') {
                                return owon;
                        }
                }
        }
        /**left-diag check**/
        for (i = 0; i < 1; i ++) {
                n = 0;
                c = arr[0][3];
                exp = 0;
                if (c == '.') {
                        n = -1;
                }
                if (c == 'T') {
                        c = arr[1][2];
                        exp = 1;
                }
                for (j = 0; j < 4; j ++) {
                        if (arr[j][3-j] != c) {
                                        if (arr[j][3-j] == 'T' && exp == 0) {
                                        exp = 1;
                                } else {
                                        n = 1;
                                }
                        }
                }
                if (n == -1) {
                        return notcomplete;
                }
                if (n == 0) {
                        if (c == 'X') {
                                return xwon;
                        } else if (c == 'O') {
                                return owon;
                        }
                }
        }
        /**draw check**/
        for (i = 0; i < 4; i ++) {
                for (j = 0; j < 4; j ++) {
                        if (arr[i][j] == '.') {
                                return notcomplete;
                        }
                }
        }
        return draw;
}
