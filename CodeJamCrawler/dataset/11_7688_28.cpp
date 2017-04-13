#include <stdio.h>
#include <string.h>

static char pic[50][51];
static int blue_num, R, C;

void dfs(int r, int c)
{
    if (r < 0 || r + 1 >= R || c < 0 || c + 1 >= C || blue_num == 0)
        return;
    else if (pic[r][c] != '#' || pic[r][c+1] != '#' || pic[r+1][c] != '#' || pic[r+1][c+1] != '#')
        return;
    else
    {
        pic[r][c] = '/';
        pic[r][c+1] = '\\';
        pic[r+1][c] = '\\';
        pic[r+1][c+1] = '/';
        blue_num -= 4;
        dfs(r - 1, c);
        dfs(r + 1, c);
        dfs(r, c - 1);
        dfs(r, c + 1);
        /*dfs(r - 2, c - 2);
        dfs(r - 2, c + 2);
        dfs(r + 2, c - 2);
        dfs(r + 2, c + 2);
        pic[r][c] = pic[r][c+1] = pic[r+1][c] = pic[r+1][c+1] = '#';
        blue_num += 4;*/
    }
}

int main()
{
    int t, i, j, c = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &R, &C);getchar();
        for (i = 0; i < R; ++i)
        {
            for (j = 0; j < C; ++j)
            {
                scanf("%c", &pic[i][j]);
                if (pic[i][j] == '#') ++blue_num;
            }
            getchar();
        }
        
        printf("Case #%d:\n", ++c, blue_num);
        
        if (blue_num % 4 != 0)
            printf("Impossible\n");
        else
        {
            for (i = 0; i < R; ++i)
                for (j = 0; j < C; ++j)
                    dfs(i, j);
            
            if (blue_num == 0)
            {
                for (i = 0; i < R; ++i)
                    printf("%s\n", pic[i]);
            }
            else
                printf("Impossible\n");
        }
        
        memset(pic, 0, sizeof (pic));
        blue_num = 0;
    }
    
    return 0;
}
