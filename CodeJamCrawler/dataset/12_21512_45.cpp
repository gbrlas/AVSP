#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "C-small-attempt0.in"
#define FILE_OUT "C-small-attempt0.out"

#define DEBUG 0

unsigned char get_len(const unsigned int number)
{
        unsigned char len = 1;
        unsigned int aux = 10;

        len = 1;
        for(aux = 10; aux < 100001; aux *= 10)
        {
                if(aux > number)
                        return len;
                len++;
        }
        return ++len;
}

unsigned int get_recycled_count(const unsigned int a, const unsigned int b)
{
        unsigned char len, index_len, buff_count, buff_i, buff_j;
        unsigned int index, recycled_index, count, small_div, big_div;
        unsigned int buff[7];

        count = 0;
        for(index = a; index <= b; index++)
        {
                len = get_len(index);
                buff_count = 0;
                for(index_len = 1; index_len < len; index_len++)
                {
                        // abcde => abcde % 10^(5-1) * 10^1 + abcde/10^4
                        small_div = pow(10, index_len);
                        big_div = pow(10, len - index_len);
                        recycled_index = index % big_div * small_div + index/big_div;
                        if((index < recycled_index) && (recycled_index <= b))
                        {
#if DEBUG
                                fprintf(stdout, "len=%hhu, index_len=%hhu, index=%u\n",len, index_len, index);
#endif
                                buff[buff_count++] = recycled_index;
                                count++;
                        }
                }
                for(buff_i = 1; buff_i < buff_count; buff_i++)
                        for(buff_j = 0; buff_j < buff_i; buff_j++)
                                if(buff[buff_i] == buff[buff_j])
                                {
                                        count--;
                                        break;
                                }
        }
        return count;
}

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;
        unsigned char n, i;
        unsigned int a, b;

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        fscanf(file_in, "%hhu", &n);
        for(i = 1; i <= n; i++)
        {
                fscanf(file_in, "%u%u", &a, &b);
                fprintf(file_out, "Case #%hhu: %u\n", i, get_recycled_count(a, b));
        }

        fclose(file_in);
        fclose(file_out);

        return 0;
}

