#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char board[4][4];
int N, num;
int over_flag, x_win, o_win, is_unFilled, win_flag;
int main()
{
//	freopen ("data.in", "r",stdin);
//	freopen ("data.out","w",stdout);
    scanf("%d", &N);
    getchar();
    for (int num = 1; num <= N; num++)
    {
        over_flag = 1;
        o_win =0;
        x_win =0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            scanf("%c", &board[i][j]);
            getchar();
        }
        getchar();
        for (int i = 0; i < 4; i++)
        {
            int idx;
            char temp;
            is_unFilled = 0;
            win_flag = 1;
            for (int j = 0; j < 4; j++)
            {
                if(board[i][j] == '.')
                {
                    over_flag = 0;
                    is_unFilled =1;
                    break;
                }
                if(board[i][j] != 'T')
                {
                    temp = board[i][j];
                    idx = j;
                    break;
                }
            }
            if (!is_unFilled)
            {
                for ( int k = idx; k < 4; k++)
                {
                    if (board[i][k] != temp && board[i][k] != 'T')
                    {
                        win_flag = 0;
                        break;
                    }
                }
                if (win_flag == 1)
                {
                    if(temp == 'O') { o_win = 1; break;}
                    if(temp == 'X') { x_win = 1; break;}
                }

            }

    }
        if(!x_win && (!o_win))
        {
            for (int j = 0; j < 4; j++)
            {
                int idx;
                char temp;
                is_unFilled = 0;
                win_flag = 1;
                for (int i = 0; i < 4; i++)
                {
                    if(board[i][j] == '.')
                    {
                        over_flag = 0;
                        is_unFilled =1;
                        break;
                    }
                    if(board[i][j] != 'T')
                    {
                        temp = board[i][j];
                        idx = i;
                        break;
                    }
                }
                if (!is_unFilled)
                {
                    for ( int k = idx; k < 4; k++)
                    {
                        if (board[k][j] != temp && board[k][j] != 'T')
                        {
                            win_flag = 0;
                            break;
                        }
                    }
                    if (win_flag == 1)
                    {
                        if(temp == 'O') { o_win = 1; break;}
                        if(temp == 'X') { x_win = 1; break;}
                    }

                }

            }
        }
        if(!x_win && (!o_win))
        {
            int idx;
            char temp;

            for (int i = 0; i < 4; i++)
            {
                win_flag = 1;
                is_unFilled = 0;
                if (board[i][i] == '.')
                {
                    over_flag = 0;
                    is_unFilled = 1;
                    break;
                }
                if(board[i][i] != 'T')
                {
                    temp = board[i][i];
                    idx = i;
                    break;
                }
            }
            if (!is_unFilled)
                {
                    for ( int k = idx; k < 4; k++)
                     {
                        if (board[k][k] != temp && board[k][k] != 'T')
                        {
                            win_flag = 0;
                            break;
                        }
                     }
                    if (win_flag == 1)
                    {
                        if(temp == 'O') { o_win = 1;}
                        if(temp == 'X') { x_win = 1;}
                    }
                }

        }
       if(!x_win && (!o_win))
        {
            int idx;
            char temp;

            for (int i = 0; i < 4; i++)
            {
                win_flag = 1;
                is_unFilled = 0;
                if (board[3-i][i] == '.')
                {
                    over_flag = 0;
                    is_unFilled = 1;
                    break;
                }
                if(board[3-i][i] != 'T')
                {
                    temp = board[3-i][i];
                    idx = i;
                    break;
                }
            }
            if (!is_unFilled)
                {
                    for ( int k = idx; k < 4; k++)
                      {

                        if (board[3-k][k] != temp && board[3-k][k] != 'T')
                        {
                            win_flag = 0;
                            break;
                        }
                      }
                    if (win_flag == 1)
                    {
                        if(temp == 'O') { o_win = 1; }
                        if(temp == 'X') { x_win = 1; }
                    }
                }

        }

        if(o_win || x_win)
        {
            if( o_win)
            printf("Case #%d: O won\n", num);
            if( x_win)
            printf("Case #%d: X won\n", num);
        }
        else {
            if(over_flag)
            {
                for (int i = 1; i < 4; i++)
                    for (int j = 1; j < 4; j++)
                if(board[i][j] == '.') over_flag = 0;
            }
            if (over_flag ) printf("Case #%d: Draw\n", num);

            else printf("Case #%d: Game has not completed\n", num);
        }
    }
	return 0;
}
