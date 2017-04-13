#include <stdio.h>
#include <string.h>

int g_Count;

void Update_Count(char *Input, char *String)
{
    char *pTempInput;
    char *pTempString;
    int len;

    pTempString = String;
    pTempInput  = strchr(Input, pTempString[0]);

    while (NULL != pTempInput)
    {
        if (1 == strlen(pTempString))
        {
            g_Count++;
            g_Count = g_Count % 10000;
        }
        else
        {
            Update_Count(pTempInput+1, pTempString+1);
        }

        pTempInput  = strchr(pTempInput+1, pTempString[0]);
    }

    return;
}

void C()
{
    FILE    *fpi;
    FILE    *fpo;
    int     Count;
    char    String[] = "welcome to code jam";
    int     i;
    char    Line[550] = {0};
    int     T;

    fpi = fopen("C-small-attempt0.in", "r");

    if (NULL == fpi)
    {
        return;
    }

    fpo = fopen("c.out", "w+");

    if (NULL == fpo)
    {
        fclose(fpi);
        return;
    }

    fscanf(fpi, "%d\n", &T);

    for (i = 1; i <= T; i++)
    {
        fgets(Line, sizeof(Line), fpi);
        g_Count = 0;
        Update_Count(Line, String);
        memset(Line, 0, sizeof(Line));
        fprintf(fpo, "Case #%d: %4.4d\n", i, g_Count);
    }

    fclose(fpi);
    fclose(fpo);
    return;
}

#if 1
void main()
{
    C();
}
#endif
