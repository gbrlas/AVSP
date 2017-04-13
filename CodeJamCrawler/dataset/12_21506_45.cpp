#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "B-small-attempt0.in"
#define FILE_OUT "B-small-attempt0.out"

char get_googlers_count(const char s, const char count_googler, const char count_might_be)
{
        if(s <= count_might_be)
                return count_googler + s;
        return count_googler + count_might_be;
}

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;
        char t, n, s, p, ti, i, j;
        char aux, count_googler, count_might_be;

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        fscanf(file_in, "%hhd", &t);
        
        for(i = 1; i <= t; i++)
        {
                fscanf(file_in, "%hhd%hhd%hhd", &n, &s, &p);

                count_googler = 0;
                count_might_be = 0;

                aux = p * 3 - 2;
                if(aux < 0)
                        aux = 0;

                for(j = 0; j < n; j++)
                {
                        fscanf(file_in, "%hhd", &ti);
                        if(aux <= ti)
                        {
                                count_googler++;
                                continue;
                        }
                        if(((aux - 2 == ti) && (ti > 1)) || ((aux - 1 == ti) && (ti > 2)))
                        {
                                count_might_be++;
                                continue;
                        }
                }

                fprintf(file_out, "Case #%hhd: %hhd\n", i, get_googlers_count(s, count_googler, count_might_be));
        }


        fclose(file_in);
        fclose(file_out);

        return 0;
}

