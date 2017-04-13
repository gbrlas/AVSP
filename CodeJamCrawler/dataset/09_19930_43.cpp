#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT  100
#define MAX_WIDTH   100

typedef struct CELL_s CELL_st, *PCELL_st;
struct CELL_s 
{
    PCELL_st pNext;
    char s8Label;
};

int main ()
{
    int s32NumTestCases;
    int s32TestCase;
    int s32Height;
    int s32Width;
    int as32Altitude[MAX_HEIGHT][MAX_WIDTH];
    CELL_st aCells[MAX_HEIGHT][MAX_WIDTH];
    int i, j;
    int s32MinAlt;
    int s32LabelSeq;
    PCELL_st pNextCell, pCurCell, pSinkCell;

    scanf("%d\r\n", &s32NumTestCases);
    
    for (s32TestCase=0; s32TestCase<s32NumTestCases; s32TestCase++)
    {
        scanf("%d %d\r\n", &s32Height, &s32Width);   
        
        for (i=0; i<s32Height; i++)
        {
            for (j=0; j<s32Width; j++)
            {
                scanf("%d", &as32Altitude[i][j]);
            }
            scanf("\r\n");
        }

        memset(aCells, 0, sizeof(aCells));
        for (i=0; i<s32Height; i++)
        {
            for (j=0; j<s32Width; j++)
            {
                s32MinAlt = as32Altitude[i][j];
                // compare with north.
                if (i!=0 && as32Altitude[i-1][j]<s32MinAlt)
                {
                    aCells[i][j].pNext = &aCells[i-1][j];
                    s32MinAlt = as32Altitude[i-1][j];
                }
                // compare with west.
                if (j!=0 && as32Altitude[i][j-1]<s32MinAlt)
                {
                    aCells[i][j].pNext = &aCells[i][j-1];
                    s32MinAlt = as32Altitude[i][j-1];
                }        
                // compare with east.
                if (j!=s32Width-1 && as32Altitude[i][j+1]<s32MinAlt)
                {
                    aCells[i][j].pNext = &aCells[i][j+1];
                    s32MinAlt = as32Altitude[i][j+1];
                }        
                // compare with south.
                if (i!=s32Height-1 && as32Altitude[i+1][j]<s32MinAlt)
                {
                    aCells[i][j].pNext = &aCells[i+1][j];
                    s32MinAlt = as32Altitude[i+1][j];
                }
            }
        }

        // label brainage basins.
        printf("Case #%d:\r\n", s32TestCase+1);
        aCells[0][0].s8Label = 'a';
        s32LabelSeq = 1;
        for (i=0; i<s32Height; i++)
        {
            for (j=0; j<s32Width; j++)
            {
                if (0 == aCells[i][j].s8Label)
                {
                    pSinkCell = &aCells[i][j];
                    while (pSinkCell)
                    {
                        if (pSinkCell->pNext)
                        {
                            pSinkCell = pSinkCell->pNext;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (0 != pSinkCell->s8Label)
                    {
                        aCells[i][j].s8Label = pSinkCell->s8Label;
                    }
                    else
                    {
                        aCells[i][j].s8Label = 'a' + s32LabelSeq;
                        s32LabelSeq++;
                    }
                }

                pCurCell  = &aCells[i][j];
                pNextCell = aCells[i][j].pNext;
                while (pNextCell)
                {
                    pNextCell->s8Label = pCurCell->s8Label;
                    pCurCell  = pNextCell;
                    pNextCell = pNextCell->pNext;
                }
                printf("%c ", aCells[i][j].s8Label);
            }
            printf("\r\n");
        }
    }
}