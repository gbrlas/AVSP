#include <stdio.h>
#include <string.h>

#define IN_PATH "D:\\home\\Downloads\\C-large.in"
#define OUT_PATH "D:\\home\\Downloads\\C-large.out"

int main(void)
{
    int T, N, caseNo=0;

    FILE *fp = fopen(IN_PATH, "r");
    if(!fp) return -1;

    FILE *out = fopen(OUT_PATH, "w");
    if(!out) return -2;

    fscanf(fp, "%d\n", &T);
    while(caseNo++<T)
    {
    	unsigned int result = 0, min = 1<<30, total=0, candy;
        fscanf(fp, "%d", &N);
        while(N-->0)
        {
            fscanf(fp,"%d", &candy);
            // TODO
            result ^= candy;
            total  += candy;
            if(candy<min) min = candy;
        }

        fprintf(out,"Case #%d: ",caseNo);
        if(!result) fprintf(out,"%d\n",total-min); else fprintf(out,"NO\n");
    }

    fclose(out);
    fclose(fp);

    return 0;
}
