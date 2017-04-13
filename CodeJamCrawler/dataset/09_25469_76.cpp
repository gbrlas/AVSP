#include <stdio.h>
#include <string.h>

#define D_Index(i, j)   ((i)*(W+2)+(j))

#define GET_MIN_2(a,b)  ((a<b)?a:b)
#define GET_MIN_3(a,b,c)  ((a<b)?(GET_MIN_2(a,c)):(GET_MIN_2(b,c)))
#define GET_MIN_4(a,b,c,d)  ((a<b)?(GET_MIN_3(a,c,d)):(GET_MIN_3(b,c,d)))
#define GET_MIN_5(a,b,c,d,e) ((a<b)?(GET_MIN_4(a,c,d,e)):(GET_MIN_4(b,c,d,e)))

typedef struct tagCell
{
    int     Count;
    char    cMark;
    char    cVisited;
    char    Pad[2];
}CELL_S;

char g_Mark;

char Get_Mark(CELL_S* pTable, int j, int k, int H, int W)
{
    char    cMark;
    int     min;

    if (1 == pTable[D_Index(j, k)].cVisited)
    {
        return (pTable[D_Index(j, k)].cMark);
    }

    min = GET_MIN_5(pTable[D_Index(j, k)].Count,
                    pTable[D_Index(j-1, k)].Count,
                    pTable[D_Index(j+1, k)].Count,
                    pTable[D_Index(j, k-1)].Count,
                    pTable[D_Index(j, k+1)].Count);

    if (min == pTable[D_Index(j, k)].Count)
    {
        pTable[D_Index(j, k)].cVisited  = 1;
        pTable[D_Index(j, k)].cMark     = g_Mark;
        g_Mark++;
        return (pTable[D_Index(j, k)].cMark);
    }

    if (min == pTable[D_Index(j-1, k)].Count)
    {
        cMark = Get_Mark(pTable, j-1, k, H, W);
    }
    else if (min == pTable[D_Index(j, k-1)].Count)
    {
        cMark = Get_Mark(pTable, j, k-1, H, W);
    }
    else if (min == pTable[D_Index(j, k+1)].Count)
    {
        cMark = Get_Mark(pTable, j, k+1, H, W);
    }
    else
    {
        cMark = Get_Mark(pTable, j+1, k, H, W);
    }

    pTable[D_Index(j, k)].cMark     = cMark;
    pTable[D_Index(j, k)].cVisited  = 1;
    return cMark;
}

void All_Mark(CELL_S *pTable, int H, int W)
{
    int j, k;

    for (j = 1; j <= H; j++)
    {
        for (k = 1; k <= W; k++)
        {
            Get_Mark(pTable, j, k, H, W);
        }
    }

    return;
}

void B()
{
    FILE    *fpi;
    FILE    *fpo;
    char    *pCur;
    int     i, j, k;
    char    Line[10000] = {0};
    int     T;
    CELL_S  *pTable;
    char    pBuf;

    fpi = fopen("B-large.in", "r");

    if (NULL == fpi)
    {
        return;
    }

    fpo = fopen("b.out", "w+");

    if (NULL == fpo)
    {
        fclose(fpi);
        return;
    }

    fscanf(fpi, "%d\n", &T);

    for (i = 1; i <= T; i++)
    {
        int H, W;

        fscanf(fpi, "%d %d\n", &H, &W);

        pTable = malloc(sizeof(CELL_S) * (H+2) * (W+2));
        if (NULL == pTable)
        {
            fclose(fpi);
            fclose(fpo);
            return;
        }

        memset(pTable, 0, (sizeof(CELL_S) * (H+2) * (W+2)));

        for (j = 0; j <= (H+1); j++)
        {
            pTable[D_Index(j, 0)].Count     = 0x7FFFFFFF;
            pTable[D_Index(j, W+1)].Count   = 0x7FFFFFFF;
        }

        for (k = 0; k <= (W+1); k++)
        {
            pTable[D_Index(0, k)].Count     = 0x7FFFFFFF;
            pTable[D_Index(H+1, k)].Count   = 0x7FFFFFFF;
        }

        for (j = 1; j <= H; j++)
        {
            for (k = 1; k <= W; k++)
            {
                int count;

                fscanf(fpi, "%d", &count);
                pTable[D_Index(j, k)].Count = count;
            }
        }

        g_Mark = 'a';
        All_Mark(pTable, H, W);

        fprintf(fpo, "Case #%d:\n", i);

        for (j = 1; j <= H; j++)
        {
            for (k = 1; k <= W; k++)
            {
                fprintf(fpo, "%c ", pTable[D_Index(j, k)].cMark);
            }

            fprintf(fpo, "\n");
        }

        free(pTable);
    }

    fclose(fpi);
    fclose(fpo);
    return;
}

#if 1
void main()
{
    B();
}
#endif
