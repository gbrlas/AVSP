#include <climits>
#include <cstdio>

using namespace std;

#define valid(y, x) (y >= 0 && y < H && x >= 0 && x < W)

char fmap[110][110], smap[110][110], cur;
int map[110][110];
int T, yy, H, W, ii, jj, total;

char DFS(int y, int x)
{
    char temp;
    int lowest, lwy, lwx, t;

    if (smap[y][x])
    {
        if (fmap[y][x] == 0)
            fmap[y][x] = cur++;
        return fmap[y][x];
    }

    t = map[y][x];
    map[y][x] = INT_MIN;
    lowest = INT_MAX;
    if (valid(y - 1, x) && map[y - 1][x] != INT_MIN)
        if (map[y - 1][x] < lowest)
        {
            lowest = map[y - 1][x];
            lwy = y - 1;
            lwx = x;
        }
    if (valid(y, x - 1) && map[y][x - 1] != INT_MIN)
        if (map[y][x - 1] < lowest)
        {
            lowest = map[y][x - 1];
            lwy = y;
            lwx = x - 1;
        }
    if (valid(y, x + 1) && map[y][x + 1] != INT_MIN)
        if (map[y][x + 1] < lowest)
        {
            lowest = map[y][x + 1];
            lwy = y;
            lwx = x + 1;
        }
    if (valid(y + 1, x) && map[y + 1][x] != INT_MIN)
        if (map[y + 1][x] < lowest)
        {
            lowest = map[y + 1][x];
            lwy = y + 1;
            lwx = x;
        }

    if (lowest != INT_MAX)
    {
        temp = DFS(lwy, lwx);
        if (fmap[y][x] == 0)
            fmap[y][x] = temp;
    }
    map[y][x] = t;

    return fmap[y][x];
}

int main(void)
{
    scanf("%d\n", &T);
    for (yy = 1; yy <= T; yy++)
    {
        scanf("%d %d\n", &H, &W);
        for (ii = 0; ii < H; ii++)
            for (jj = 0; jj < W; jj++)
            {
                scanf("%d ", &map[ii][jj]);
                fmap[ii][jj] = 0;
                smap[ii][jj] = 0;
            }
        for (ii = 0; ii < H; ii++)
            for (jj = 0; jj < W; jj++)
            {
                total = 0;
                if (valid(ii - 1, jj) && map[ii - 1][jj] < map[ii][jj])
                    total++;
                if (valid(ii + 1, jj) && map[ii + 1][jj] < map[ii][jj])
                    total++;
                if (valid(ii, jj - 1) && map[ii][jj - 1] < map[ii][jj])
                    total++;
                if (valid(ii, jj + 1) && map[ii][jj + 1] < map[ii][jj])
                    total++;
                if (total == 0)
                    smap[ii][jj] = 1;
            }
        cur = 'a';
        for (ii = 0; ii < H; ii++)
            for (jj = 0; jj < W; jj++)
                    DFS(ii, jj);
        printf("Case #%d:\n", yy);
        for (ii = 0; ii < H; ii++)
        {
            for (jj = 0; jj < W; jj++)
            {
                if (jj > 0)
                    printf(" ");
                printf("%c", fmap[ii][jj]);
            }
            printf("\n");
        }
    }
    return 0;
}
