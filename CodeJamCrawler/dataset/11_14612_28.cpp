//Squaretiles

#include <stdio.h>

int height, width;
bool possible;
char map[55][55];

bool canPlace(int r, int c) {
    if (r+1 == height || c+1 == width)
        return false;
    if (map[r][c+1] != '#' || map[r+1][c] != '#' || map[r+1][c+1] != '#')
        return false;
    map[r][c] = map[r+1][c+1] = '/';
    map[r+1][c] = map[r][c+1] = '\\';
    return true;
}

int main() {
    int cases, r, c;
    scanf("%d", &cases);
    for (int caseNo = 1; caseNo <= cases; caseNo++) {
        printf("Case #%d:\n", caseNo);
        scanf("%d %d", &height, &width);
        for (r = 0; r < height; r++)
            scanf("%s", map[r]);
        possible = true;
        for (r = 0; r < height && possible; r++)
            for (c = 0; c < width && possible; c++)
                if (map[r][c] == '#' && !canPlace(r, c)) {
                    possible = false;
                }
        if (!possible) printf("Impossible\n");
        else
            for (r = 0; r < height; r++)
                printf("%s\n", map[r]);
    }
    return 0;
}
