#include <stdio.h>
#include <string.h>

char engine[100][101] = {'\x0'};
int engine_num = 0;
char query[1000][101] = {'\x0'};
int query_num = 0;

int mm[100][1000] = {0};


int init()
{
    int i, j;
    for(i = 0; i < engine_num; i++)
    {
        //printf("query : %s", query[0]);
        //printf("engine : %s", engine[i]);
        if(strcmp(query[0], engine[i]) != 0)
            mm[i][0] = 0;
        else
            mm[i][0] = 1;
    }
    /*
        for(i = 0; i < engine_num; i++)
        {
            for(j = 0; j < query_num; j++)
            {
                //printf("%d ", mm[i][j]);
            }
                //printf("\n");
        }
    */
}
int min()
{
    init();
    int i,j,k;
    for(i = 1; i < query_num; i++)
    {
        int min = 9999;
        int temp = 0;
        for(j = 0; j < engine_num; j++)
        {
            min = 9999;
            temp = 0;
            for(k = 0; k < engine_num; k++)
            {
                temp = mm[k][i - 1];
                //printf("temp(%d, %d - 1) : %d\n", k, i, temp);
                if(k != j)
                {
                    //printf("From others +1\n");
                    temp++;
                }
                if(strcmp(query[i], engine[k]) == 0)
                {
                    //printf("Query +1\n");
                    temp = 9999;
                }
                //printf("temp < min : %d < %d\n", temp, min);
                if(temp < min)
                {
                    min = temp;
                }
            }
            //printf("m[%d][%d] = %d\n", j, i, min);
            mm[j][i] = min;
        }
    }
}
int main(int argc, char * args[])

{
    int i = 0;
    int j = 0;
    int k = 0;

    int n = 0;

    fscanf(stdin, "%d", &n);
    //printf("n : %d\n", n);

    for(i = 0; i < n; i++)
    {
        fscanf(stdin, "%d", &engine_num);
        fgetc(stdin);
        //printf("engine_num : %d\n", engine_num);
        for(j = 0; j < engine_num; j++)
        {
            fgets(engine[j], 100, stdin);
            //printf("engine %d : %s\n", j, engine[j]);
        }

        fscanf(stdin, "%d", &query_num);
        //printf("query_num : %d\n", query_num);
        fgetc(stdin);

        for(j = 0; j < query_num; j++)
        {
            //fscanf(stdin, "%s", &query[j]);
            fgets(query[j], 100, stdin);
            //printf("query %d : %s\n", j, query[j]);
        }

        min();

        int min_switch_count = 9999;
        for(j = 0; j < engine_num; j++)
        {
            if(min_switch_count > mm[j][query_num -1])
            {
                min_switch_count = mm[j][query_num - 1];
            }
        }
       if(engine_num == 0 || query_num ==0)
            min_switch_count = 0;
        fprintf(stdout, "Case #%d: %d\n", i + 1, min_switch_count);
        /*
        for(j = 0; j < query_num; j++)
        {
            printf("%c ", query[j][0]);
        }
        printf("\n");
        for(j = 0; j < engine_num; j++)
        {
            for(k = 0; k < query_num; k++)
            {
                printf("%d ", mm[j][k]);
            }
                printf("\n");
        }
        */
    }

    return 0;
}
