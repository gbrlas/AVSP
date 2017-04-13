#include <stdio.h>
#include <stdlib.h>

#define input "A-large.in"
#define output "A-large.out"

FILE *in,*out;
__int64 N,P,K,L;
__int64 dat[1001];
__int64 i,j,k,cnt,kpress;

int comp(const void *, const void *);

int main(){
    in = fopen(input,"r");
    out = fopen(output,"w");
    fscanf(in,"%I64d",&N);
    for(k=0;k<N;k++){
        fprintf(out,"Case #%I64d: ",k+1);
        fscanf(in, "%I64d %I64d %I64d", &P, &K, &L);
        cnt = 0; kpress = 0;
        for(i=0;i<L;i++)fscanf(in,"%I64d",&dat[i]);
        qsort(dat, L, sizeof(__int64), &comp);
        for(i=0;i<L;i++){
            if(!(i%K))cnt++;
            kpress += cnt * dat[i];
        }
        fprintf(out,"%I64d\n",kpress);
    }
    system("pause");
    return 0;
}

int comp(const void * a, const void * b){
    return *(int *)b - *(int *)a;
}
