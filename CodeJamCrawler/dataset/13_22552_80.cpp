// fas.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
    int t=0;
    char arr[4][4];
    char ch;
    int rc[2][4];
    int dots = 0;
    int ld=0, rd=0;

    scanf("%d", &t);

    for (int i=0; i<t; ++i)
    {
        for (int j=0; j<2; ++j)
        {
            for (int k=0; k<4; ++k)
            {
                rc[j][k] = 1;
            }
        }
        ld = 1;
        rd = 1;

        dots = 0;

        for (int j=0; j<4; ++j)
        {
            for (int k=0; k<4; ++k)
            {
                scanf("%c", &ch);
                if ('\n' == ch)
                {
                    scanf("%c", &ch);
                    if ('\n' == ch)
                    {
                        scanf("%c", &arr[j][k]);
                    }
                    else
                    {
                        arr[j][k] = ch;
                    }
                }
                else
                {
                    arr[j][k] = ch;
                }
                if ('.' == arr[j][k])
                {
                    ++dots;
                    rc[0][j] = 0;
                    rc[1][k] = 0;
                    if (j == k)
                    {
                        ld = 0;
                    }
                    else if (3 == j+k)
                    {
                        rd = 0;
                    }
                }
            }
        }

        if (10 < dots)
        {
            printf("Case #%d: Game has not completed\n", i+1);
            continue;
        }

        int brk = 0;

        //check rows
        for (int j=0; j<4; ++j)
        {
            if (rc[0][j])
            {
                //check for X
                if ( ('X' == arr[j][0] || 'T' == arr[j][0]) && ('X' == arr[j][1] || 'T' == arr[j][1]) && ('X' == arr[j][2] || 'T' == arr[j][2]) && ('X' == arr[j][3] || 'T' == arr[j][3]) )
                {
                    printf("Case #%d: X won\n", i+1);
                    brk = 1; break;
                }
                //check for O
                if ( ('O' == arr[j][0] || 'T' == arr[j][0]) && ('O' == arr[j][1] || 'T' == arr[j][1]) && ('O' == arr[j][2] || 'T' == arr[j][2]) && ('O' == arr[j][3] || 'T' == arr[j][3]) )
                {
                    printf("Case #%d: O won\n", i+1);
                    brk = 1; break;
                }
            }
        }
        if (brk)
        {
            continue;
        }

        //check columns
        for (int k=0; k<4; ++k)
        {
            if (rc[1][k])
            {
                //check for X
                if ( ('X' == arr[0][k] || 'T' == arr[0][k]) && ('X' == arr[1][k] || 'T' == arr[1][k]) && ('X' == arr[2][k] || 'T' == arr[2][k]) && ('X' == arr[3][k] || 'T' == arr[3][k]) )
                {
                    printf("Case #%d: X won\n", i+1);
                    brk = 1; break;
                }
                //check for O
                if ( ('O' == arr[0][k] || 'T' == arr[0][k]) && ('O' == arr[1][k] || 'T' == arr[1][k]) && ('O' == arr[2][k] || 'T' == arr[2][k]) && ('O' == arr[3][k] || 'T' == arr[3][k]) )
                {
                    printf("Case #%d: O won\n", i+1);
                    brk = 1; break;
                }
            }
        }
        if (brk)
        {
            continue;
        }

        //check left diagonal
        if (ld)
        {
            //check for X
            if ( ('X' == arr[0][0] || 'T' == arr[0][0]) && ('X' == arr[1][1] || 'T' == arr[1][1]) && ('X' == arr[2][2] || 'T' == arr[2][2]) && ('X' == arr[3][3] || 'T' == arr[3][3]) )
            {
                printf("Case #%d: X won\n", i+1);
                continue;
            }
            //check for O
            if ( ('O' == arr[0][0] || 'T' == arr[0][0]) && ('O' == arr[1][1] || 'T' == arr[1][1]) && ('O' == arr[2][2] || 'T' == arr[2][2]) && ('O' == arr[3][3] || 'T' == arr[3][3]) )
            {
                printf("Case #%d: O won\n", i+1);
                continue;
            }
        }

        //check right diagonal
        if (rd)
        {
            //check for X
            if ( ('X' == arr[0][3] || 'T' == arr[0][3]) && ('X' == arr[1][2] || 'T' == arr[1][2]) && ('X' == arr[2][1] || 'T' == arr[2][1]) && ('X' == arr[3][0] || 'T' == arr[3][0]) )
            {
                printf("Case #%d: X won\n", i+1);
                continue;
            }
            //check for O
            if ( ('O' == arr[0][3] || 'T' == arr[0][3]) && ('O' == arr[1][2] || 'T' == arr[1][2]) && ('O' == arr[2][1] || 'T' == arr[2][1]) && ('O' == arr[3][0] || 'T' == arr[3][0]) )
            {
                printf("Case #%d: O won\n", i+1);
                continue;
            }
        }

        if (0 < dots)
        {
            printf("Case #%d: Game has not completed\n", i+1);
        }
        else
        {
            printf("Case #%d: Draw\n", i+1);
        }
    }

	return 0;
}
