#include <stdio.h>

int main()
{
    int t, m, n, i, j, max, k = 0, flag;
    
    scanf("%d", &t);
    
    while (t--)
    {
        k++;
        scanf("%d%d", &m, &n);
        
        int matrix[m][n];
        int max_rows[m];
        int max_cols[n];
        
        for(i = 0; i<m; i++)
        {
            max = 0;
            for(j = 0; j<n; j++)
            {
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] > max)
                    max = matrix[i][j];
            }
            max_rows[i] = max;
        }
        
        for(i = 0; i<n; i++)
        {
            max = 0;
            for(j = 0; j<m; j++)
            {
                if (matrix[j][i] > max)
                    max = matrix[j][i];
            }
            max_cols[i] = max;
        }
        
        int new_matrix[m][n];
        
        for(i = 0; i<m; i++)
        {
            for (j = 0; j<n; j++)
                new_matrix[i][j] = max_rows[i];
        }
        
        for(i = 0; i<n; i++)
        {
            for (j = 0; j<m; j++)
                if (new_matrix[j][i] > max_cols[i])
                    new_matrix[j][i] = max_cols[i];
        }
        
        flag = 0;
        
        for(i = 0; i<m; i++)
        {
            for (j = 0; j<n; j++)
            {
                if (!(new_matrix[i][j] == matrix[i][j]))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        
        if (flag == 0)
            printf("Case #%d: YES\n", k);
        else
            printf("Case #%d: NO\n", k);
        
    }
    
    return 0;
}
