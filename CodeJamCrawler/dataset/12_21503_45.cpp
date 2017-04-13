#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "A-small-attempt1.in"
#define FILE_OUT "A-small-attempt1.out"

#define DEBUG 0

int main(int argc, char **argv)
{
        FILE *file_in, *file_out;
        unsigned char c, code[256];
        unsigned char n, k;

        c = 1;
        while(code[c] = c++);

        code['a'] = 'y';
        code['b'] = 'h';
        code['c'] = 'e';
        code['d'] = 's';
        code['e'] = 'o';
        code['f'] = 'c';
        code['g'] = 'v';
        code['h'] = 'x';
        code['i'] = 'd';
        code['j'] = 'u';
        code['k'] = 'i';
        code['l'] = 'g';
        code['m'] = 'l';
        code['n'] = 'b';
        code['o'] = 'k';
        code['p'] = 'r';
        code['q'] = 'z';
        code['r'] = 't';
        code['s'] = 'n';
        code['t'] = 'w';
        code['u'] = 'j';
        code['v'] = 'p';
        code['w'] = 'f';
        code['x'] = 'm';
        code['y'] = 'a';
        code['z'] = 'q';

        if(!(file_in = fopen(FILE_IN, "r")))
                return -1;

        if(!(file_out = fopen(FILE_OUT, "w")))
                return -1;

        // number of lines
        fscanf(file_in, "%hhu\n", &n);
        if(n)
                fprintf(file_out, "Case #1: ");

        k = 2;
        c=' ';

        while(n)
        {
                if('\n' == c)
                {
                        if(k > n)
                                break;
                        fprintf(file_out, "Case #%hhu: ", k);
                        k++;
                }

                fscanf(file_in, "%c", &c);
                fprintf(file_out, "%c", code[c]);
        }

        fclose(file_in);
        fclose(file_out);

        return 0;
}

