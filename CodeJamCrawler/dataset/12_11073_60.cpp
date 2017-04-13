#include <stdio.h>
#include <string.h>

int exists(int array[7], int elm, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        if (array[i] == elm)
            return 1;

    return 0;
}

int main(void)
{
    int cases, i, j, k;
    int a, b;

    scanf("%d", &cases);
    for (i = 0; i < cases; i++)
    {
        scanf("%d %d", &a, &b);
        int cases = 0;
        char buffer[8];

        for (j = a; j <= b; ++j)
        {
            sprintf(buffer, "%d", j);
            int length = strlen(buffer);
            int known[7];
            for (k = 1; k < length; ++k)
            {
                char number[8];
                int inumber;
                strncpy(number + 1, buffer, length);
                number[0] = buffer[length - 1];
                number[length] = '\0';
                strcpy(buffer, number);

                inumber = atoi(number);
                if (exists(known, inumber, k))
                    continue;

                known[k] = inumber;
                if ((inumber > j) && (number[0] != '0') && inumber <= b)
                    cases++;
            }
        }
        
        printf("Case #%d: %d\n", i + 1, cases);
    }

    return 0;
}
