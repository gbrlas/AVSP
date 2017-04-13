
#include <stdio.h>

int checkColumn (char matrix[4][4])
{
    int i, j;
    char c;
    
    for (j = 0; j<4; j++)
    {
        c = matrix[0][j];
        
        if (c=='T')
            c = matrix[1][j];
        
        if (c=='.')
            continue;
        
        for(i = 0; i<4; i++)
        {
            if (matrix[i][j] == 'T')
                continue;
            if (matrix[i][j] != c)
                break;
        }
        
        if (i == 4)
        {
            if (c == 'X')
                return 1;
            else
                return 2;
        }
    }
    
    return 0;
}

int checkRow (char matrix[4][4])
{
    int i, j;
    char c;
    
    for (i = 0; i<4; i++)
    {
        c = matrix[i][0];
        
        if (c=='T')
            c = matrix[i][0];
            
        if (c=='.')
            continue;
        
        for(j = 0; j<4; j++)
        {
            if (matrix[i][j] == 'T')
                continue;
            if (matrix[i][j] != c)
                break;
        }
        
        if (j == 4)
        {
            if (c == 'X')
                return 1;
            else
                return 2;
        }
    }
    
    return 0;
}

int checkDiagonal (char matrix[4][4])
{
    int i, j;
    char c;
    
    c = matrix[0][0];
    
    if (c=='T')
        c = matrix[1][1];
    
    if (c=='.')
        goto L;
    
    for (j = 0; j<4; j++)
    {
        if (matrix[j][j] == 'T')
            continue;
        if (matrix[j][j] != c)
            break;
    }
        
    if (j == 4)
    {
        if (c == 'X')
            return 1;
        else
            return 2;
    }
    
    L:
    
    c = matrix[0][3];
        
    if (c=='T')
        c = matrix[1][2];
    
    if (c=='.')
        return 0;
    
    for (j = 0; j<4; j++)
    {
        if (matrix[j][3-j] == 'T')
            continue;
        if (matrix[j][3-j] != c)
            break;
    }
        
    if (j == 4)
    {
        if (c == 'X')
            return 1;
        else
            return 2;
    }
    
    return 0;
}

int main()
{
    int t, i, j, a, counter = 0;
    char matrix[4][4];
    int flag;
    
    scanf("%d", &t);
    
    while (t--)
    {
        counter++;
        getchar();
        
        flag = 0;
        
        for (i = 0; i<4; i++)
        {
            for(j = 0; j<4; j++)
            {
                scanf("%c", &matrix[i][j]);
                if (matrix[i][j] == '.')
                {
                    flag = 1;
                }
            }
            getchar();
        }
        
        a = checkColumn(matrix);
        
        if (a !=0)
        {
            if (a==1)
                printf("Case #%d: X won\n", counter);
            else
                printf("Case #%d: O won\n", counter);
            
            continue;
        }
        
        a = checkRow(matrix);
        
        if (a !=0)
        {
            if (a==1)
                printf("Case #%d: X won\n", counter);
            else
                printf("Case #%d: O won\n", counter);
            
            continue;
        }
        
        a = checkDiagonal(matrix);
        
        if (a !=0)
        {
            if (a==1)
                printf("Case #%d: X won\n", counter);
            else
                printf("Case #%d: O won\n", counter);
            
            continue;
        }
        
        if (flag == 1)
        {
            printf("Case #%d: Game has not completed\n", counter);
            continue;
        }
        
        printf("Case #%d: Draw\n", counter);
        
        //for (i = 0; i<4; i++)
        //{
            //for(j = 0; j<4; j++)
                //printf("%c", matrix[i][j]);
            //printf("\n");
        //}
    }
    
    return 0;
}
