#include <stdio.h>

typedef struct tagMark
{
    char *ptr;
    int  mark;
}MARK_S;

int     L;
int     D;
int     N;
char    *Buf;
MARK_S  *Table;

int Get_Matches(char *Line)
{
    int     i, j;
    int     count = 0;
    char    *pTemp;

    for (i = 0; i < D; i++)
    {
        pTemp = Line;

        for (j = 0; j < L; j++)
        {
            char ch = Table[i].ptr[j];

            if (pTemp[0] == '(')
            {
                char *pClose;
                char *pChar;

                pTemp++;
                pClose = strchr(pTemp, ')');
                pChar  = strchr(pTemp, ch);

                if ((NULL == pChar) || (pChar > pClose))
                {
                    break;
                }

                pTemp = pClose;
            }
            else
            {
                if (ch != pTemp[0])
                {
                    break;
                }
            }

            pTemp++;
        }

        if (j == L)
        {
            count++;
        }
    }

    return count;
}

void A()
{
    FILE    *fpi;
    FILE    *fpo;
    char    *pCur;
    int     i;
    char    Line[10000] = {0};

    fpi = fopen("A-large.in", "r");

    if (NULL == fpi)
    {
        return;
    }

    fpo = fopen("a.out", "w+");

    if (NULL == fpo)
    {
        fclose(fpi);
        return;
    }

    fscanf(fpi, "%d %d %d\n", &L, &D, &N);

    Buf = malloc((L+1)*D);
    if (NULL == Buf)
    {
        fclose(fpi);
        fclose(fpo);
        return;
    }

    Table = malloc(sizeof(MARK_S) * D);
    if (NULL == Table)
    {
        free(Buf);
        fclose(fpi);
        fclose(fpo);
        return;
    }

    memset(Buf, 0, ((L+1)*D));
    memset(Table, 0, (sizeof(MARK_S) * D));

    pCur = Buf;

    for(i = 1; i <= D; i++)
    {
        fgets(pCur, (L+1), fpi);
        pCur[L] = NULL;
        fscanf(fpi,"\n");
        Table[i-1].ptr = pCur;
        pCur += (L+1);
    }

    for (i = 1; i <= N; i++)
    {
        int count;

        fgets(Line, sizeof(Line), fpi);
        count = Get_Matches(Line);
        fprintf(fpo, "Case #%d: %d\n", i, count);
		memset(Line, 0, sizeof(Line));
	}

    free(Buf);
    free(Table);
    fclose(fpi);
    fclose(fpo);
    return;
}

#if 1
void main()
{
    A();
}
#endif
