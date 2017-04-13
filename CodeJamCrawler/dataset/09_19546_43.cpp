#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
line_count(char line[], char phrase[]);

int
main(int argc, char** argv)
{
    FILE *input;
    int N;
    int i;
    int j;
    int count;
    char line[501];
    char phrase[] = "welcome to code jam";
    char c;
    if (argc < 2)
    {

        return -1;
    }

    input = fopen (argv[1], "r");
    if (!input)
    {
        return -2;
    }
    fscanf(input, "%d\n", &N);

    for(i = 0; i < N; i++)
    {
        memset(line, 0, sizeof(char) * 501);
        j = 0;
        while('\n' != (c = fgetc(input)))
        {
            line[j] = c;
            j++;
        }

        count = line_count(line, phrase);
        printf("Case #%d: %04d\n", i + 1, count);
    }
        

  return 0;
}

int
line_count(char line[], char phrase[])
{
    char *iter;
    int count = 0;
    
    if(strlen(phrase) < 1)
    {
        return 1;
    }    
    iter = line;
    while(NULL != (iter = strchr(iter, phrase[0])))
    {
        iter++;
        count += line_count(iter, &(phrase[1]));
        count %= 10000;
    }
    
    return count;
}
