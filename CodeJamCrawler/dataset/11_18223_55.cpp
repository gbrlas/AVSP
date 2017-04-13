#include <stdio.h>

#define IN_PATH "D:\\home\\Downloads\\A-large.in"
#define OUT_PATH "D:\\home\\Downloads\\A-large.out"

int main(void)
{
    int T, N, B, R, caseNo=0;

    FILE *fp = fopen(IN_PATH, "r");
    if(!fp) return -1;

    FILE *out = fopen(OUT_PATH, "w");
    if(!out) return -2;

    fscanf(fp, "%d\n", &T);

    while(caseNo++<T)
    {
    	int loc[]={1,1};
    	int lastMovTime[]={0,0}, now=0;

        fscanf(fp, "%d", &N);
//        printf("\n N: {R B} time[O] time[B] loc[O] loc[B] - now\n");
//        printf("%2d:        %5d %7d %6d %6d\n", N, lastMovTime[0], lastMovTime[1],loc[0],loc[1]);
        while(N-->0)
        {
        	fscanf(fp," %c %d", &R, &B);
//        	printf("%2d: %c %3d", N,R,B);
			R = (R=='B') ? 1 : 0;
        	int move = (B <= loc[R]) ? loc[R]-B : B-loc[R];
        	int time = lastMovTime[R] + move + 1;
        	now      = lastMovTime[R] = (time>now) ? time : now+1;
        	loc[R]   = B;
//			printf("  %5d %7d %6d %6d  - %3d\n", lastMovTime[0], lastMovTime[1],loc[0],loc[1],now);
		}
        //printf("Case #%d: %d\n",caseNo,now);
        fprintf(out,"Case #%d: %d\n",caseNo,now);
    }

    fclose(out);
    fclose(fp);

    return 0;
}
