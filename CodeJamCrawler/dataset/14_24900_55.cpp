
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberoftest;
    scanf("%d", &numberoftest);
    
    int a1;
    int a2;
    
    int c1[4][4];
    int c2[4][4];
    
    for(int i = 0; i < numberoftest; i++)
    {
        scanf("%d", &a1);
        scanf("%d %d %d %d", &c1[0][0], &c1[0][1], &c1[0][2], &c1[0][3]);
        scanf("%d %d %d %d", &c1[1][0], &c1[1][1], &c1[1][2], &c1[1][3]);
        scanf("%d %d %d %d", &c1[2][0], &c1[2][1], &c1[2][2], &c1[2][3]);
        scanf("%d %d %d %d", &c1[3][0], &c1[3][1], &c1[3][2], &c1[3][3]);
        
        scanf("%d", &a2);
        scanf("%d %d %d %d", &c2[0][0], &c2[0][1], &c2[0][2], &c2[0][3]);
        scanf("%d %d %d %d", &c2[1][0], &c2[1][1], &c2[1][2], &c2[1][3]);
        scanf("%d %d %d %d", &c2[2][0], &c2[2][1], &c2[2][2], &c2[2][3]);
        scanf("%d %d %d %d", &c2[3][0], &c2[3][1], &c2[3][2], &c2[3][3]);
        
        int count = 0;
        int solution = 0;
        
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(c1[a1-1][j] == c2[a2-1][k])
                {
                    solution = c1[a1-1][j];
                    count++;
                }
            }
        }
        
        if(count == 0)
        {
            printf("Case #%d: Volunteer cheated!\n", (i+1));
        }
        else if(count == 1)
        {
            printf("Case #%d: %d\n", (i+1), solution);
        }
        else
        {
            printf("Case #%d: Bad magician!\n", (i+1));
        }
    }
    
    return 0;
}