#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int line = 1; line <= t; line++) {
	int n, k;
	scanf("%d %d\n", &n, &k);
        char board[n][n];
        for(int j=n-1; j>=0; j--) {
            for(int i=0; i<n; i++) {
	        scanf("%c", &board[i][j]);
            }
        scanf("\n");
        }
        //for(int i=0;i<n;i++) {for(int j=0;j<n;j++) printf("%c", board[i][j]); printf("\n");}
        char newboard[n][n];
        for(int row=0; row<n; row++) {
            int level=n-1;
            for(int depth=n-1; depth>=0; depth--)
                if(board[depth][row] != '.') {
                    newboard[level][row] = board[depth][row];
                    level--;
                }
            while(level >= 0) {
                newboard[level][row] = '.';
                level--;
            }
        }
        //for(int i=0;i<n;i++) {for(int j=0;j<n;j++) printf("%c", newboard[i][j]); printf("\n");}
        bool red=false, blue=false;
        for(int row = 0; row < n; row++)
            for(int depth=n-1; depth >=0; depth--) {
                if(depth+1 >= k && newboard[depth][row] != '.') {
                    bool isR = newboard[depth][row] == 'R';
                    bool isSame = true;
                    int j;
                    if(isR && !red || !isR && !blue) {
                        for(j = depth-1; isSame && j > depth-k; j--) {
                            if(newboard[j][row] == '.') break;
                            isSame = isR == (newboard[j][row] == 'R');
                        }
                        if(isSame == true && j==depth-k)
                            if(isR == true) red = true;
                            else blue = true;
                    }
                }
                if(row+k<=n && newboard[depth][row] != '.') {
                    bool isR = newboard[depth][row] == 'R';
                    bool isSame = true;
                    int i;
                    if(isR && !red || !isR && !blue) {
                        for(i = row+1; isSame && i < row+k; i++) {
                            if(newboard[depth][i] == '.') break;
                            isSame = isR == (newboard[depth][i] == 'R');
                        }
                        if(isSame == true && i==row+k)
                            if(isR == true) red = true;
                            else blue = true;
                    }
                }
                if(row+k<=n && depth+1 >= k && newboard[depth][row] != '.') {
                    bool isR = newboard[depth][row] == 'R';
                    bool isSame = true;
                    int i, j;
                    if(isR && !red || !isR && !blue) {
                        for(i = row+1, j = depth-1; isSame && i < row+k && j > depth-k; i++, j--) {
                            if(newboard[j][i] == '.') break;
                            isSame = isR == (newboard[j][i] == 'R');
                        }
                        if(isSame == true && i==row+k)
                            if(isR == true) red = true;
                            else blue = true;
                    }
                }
                if(row-k+1>=0 && depth+1 >= k && newboard[depth][row] != '.') {
                    bool isR = newboard[depth][row] == 'R';
                    bool isSame = true;
                    int i, j;
                    if(isR && !red || !isR && !blue) {
                        for(i = row-1, j = depth-1; isSame && i > row-k && j > depth-k; i--, j--) {
                            if(newboard[j][i] == '.') break;
                            isSame = isR == (newboard[j][i] == 'R');
                        }
                        if(isSame == true && i==row-k)
                            if(isR == true) red = true;
                            else blue = true;
                    }
                }
            }
        printf("Case #%d: ", line);
        if(red && blue) printf("Both\n");
        else if (red) printf("Red\n");
        else if (blue) printf("Blue\n");
        else printf("Neither\n");

    }
}
