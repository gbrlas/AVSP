#include <stdio.h>
#include <assert.h>

int heights[100][100];
char map[100][100];
int W, H;

void readBasin()
{
    int i,j;

    scanf("%d %d", &H, &W);

    for (i=0; i<H; i++)
    {
        for (j=0; j<W; j++)
        {
            scanf("%d", &heights[i][j]);
            map[i][j] = 0;
        }
    }
}

void flood(int x, int y, int from, char c)
{
    int dir, min;
    if (map[x][y] != 0)
        return;
    if (from != -1)
    {
        min = 10001;
        dir = -1;
        if (x > 0 && heights[x-1][y] < min)
        {
            dir = 0;
            min = heights[x-1][y];
        }
        if (y > 0 && heights[x][y-1] < min)
        {
            dir = 1;
            min = heights[x][y-1];
        }
        if (y < W-1 && heights[x][y+1] < min)
        {
            dir = 2;
            min = heights[x][y+1];
        }
        if (x < H-1 && heights[x+1][y] < min)
        {
            dir = 3;
        }
        if (dir != from)
            return;
    }
    map[x][y] = c;
    if (x > 0 && heights[x-1][y] > heights[x][y])
        flood(x-1,y,3,c);
    if (y > 0 && heights[x][y-1] > heights[x][y])
        flood(x,y-1,2,c);
    if (y < W-1 && heights[x][y+1] > heights[x][y])
        flood(x,y+1,1,c);
    if (x < H-1 && heights[x+1][y] > heights[x][y])
        flood(x+1,y,0,c);
}

void floodFromDrain(int x, int y, char c)
{
    int dir, min;
    min = heights[x][y];
    dir = -1;
    if (x>0 && heights[x-1][y] < min)
    {
        dir = 0;
        min = heights[x-1][y];
    }
    if (y>0 && heights[x][y-1] < min)
    {
        dir = 1;
        min = heights[x][y-1];
    }
    if (y < W-1 && heights[x][y+1] < min)
    {
        dir = 2;
        min = heights[x][y+1];
    }
    if (x < H-1 && heights[x+1][y] < min)
    {
        dir = 3;
        min = heights[x+1][y];
    }
    switch(dir)
    {
    case -1:
        flood(x,y,-1,c);
        break;
    case 0:
        floodFromDrain(x-1,y,c);
        break;
    case 1:
        floodFromDrain(x,y-1,c);
        break;
    case 2:
        floodFromDrain(x,y+1,c);
        break;
    case 3:
        floodFromDrain(x+1,y,c);
        break;
    }
}

int main()
{
    int T, i;
    int x,y;
    char c='a';
    scanf("%d", &T);
    for (i=1; i<=T; i++)
    {
        readBasin();
        c = 'a';
        for (x=0; x<H; x++)
        {
            for (y=0; y<W; y++)
            {
                if (map[x][y] == 0)
                {
                    floodFromDrain(x,y,c);
                    c++;
                }
            }
        }
        printf("Case #%d:\n", i);
        for (x=0; x<H; x++)
        {
            for (y=0; y<W; y++)
            {
                if (y != 0)
                    printf(" ");
                printf("%c", map[x][y]);
            }
            printf("\n");
        }
    }
    return 0;
}
