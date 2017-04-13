#include <stdio.h>
#include <string.h>

#define IN_PATH "D:\\home\\Downloads\\B-small-attempt0.in"
#define OUT_PATH "D:\\home\\Downloads\\B-small-attempt0.out"

#define BASES "QWERASDF"

typedef struct letter
{
    int  oppose[9];
    char combine[9];
} letter;

int index(char ch)
{
	char *p = strchr(BASES,ch);
	return p ? p-BASES : 8;
}

int main(void)
{
    int T, C, D, N, i, caseNo=0,base1i,base2i;
    char base1,base2,nonbase,list[102];

    FILE *fp = fopen(IN_PATH, "r");
    if(!fp) return -1;

    FILE *out = fopen(OUT_PATH, "w");
    if(!out) return -2;

    fscanf(fp, "%d\n", &T);

    while(caseNo++<T)
    {
//    	printf("\n\nCase #%d:",caseNo);
        letter lookup[9];
        memset((void*)&lookup,0,sizeof(lookup));

        fscanf(fp, "%d", &C);
        while(C-->0)
        {
            fscanf(fp," %c%c%c", &base1,&base2,&nonbase);
            base1i = index(base1);
            base2i = index(base2);
            lookup[base1i].combine[base2i] = nonbase;
            lookup[base2i].combine[base1i] = nonbase;
        }
        fscanf(fp, "%d", &D);
        while(D-->0)
        {
            fscanf(fp," %c%c", &base1,&base2);
            base1i = index(base1);
            base2i = index(base2);
            lookup[base1i].oppose[base2i] = 1;
            lookup[base2i].oppose[base1i] = 1;
        }
        fscanf(fp, "%d ", &N);
        fscanf(fp, "%s", list);

        int w = 0, write;
        int r = 0, read;
        while(r++<N)
        {
//        	printf("\n  %c > ",list[r]);
            write = index(list[w]);
            read  = index(list[r]);

            if(lookup[read].combine[write]!='\0'){
                list[w] = lookup[read].combine[write];
//            	printf("combined to %c",list[w]);
            }
            else
            {
                for( i=w ; i>=0 ; i--)
                    if(lookup[read].oppose[index(list[i])])
                    {
//                    	printf("opposed to %c",BASES[index(list[i])]);
                        list[(w=0)] = list[++r];
                        break;
                    }
                if(i<0){
//                	printf("appended");
                    list[++w] = list[r];
                }
            }
        }

        N = strlen(list);
        fprintf(out,"Case #%d: [",caseNo);
        if(N>0)
        {
            fprintf(out,"%c",list[0]);
            for(i=1; i<N; i++)
                fprintf(out,", %c",list[i]);
        }
        fprintf(out,"]\n");
    }

    fclose(out);
    fclose(fp);

    return 0;
}
