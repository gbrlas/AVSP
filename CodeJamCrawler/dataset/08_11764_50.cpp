#include <stdio.h>
#include <stdlib.h>

#define debug

typedef struct {
    int time;
    int dat;
} table;

int N,Na,Nb,T;
int i,j,k,x,cnt,maxcnt;
table a[200],b[200];
FILE *in,*out;

int gettime(void);
int tablecmp(const void *, const void *);

int main(){
    in = fopen("B-small-attempt3.in","r");
    out = fopen("B-small-attempt3.out","w");
    fscanf(in,"%d",&N);
    for(k=0;k<N;k++){
        fprintf(out, "Case #%d: ",k+1);
        fscanf(in,"%d",&T);
        fscanf(in,"%d %d",&Na,&Nb);
        for(i=0;i<Na;i++){
            a[i].time = gettime();
            a[i].dat = -1;
            b[i].time = gettime() + T;
            b[i].dat = 1;
        }
        x = Na + Nb;
        for(i=Na;i<x;i++){
            b[i].time = gettime();
            b[i].dat = -1;
            a[i].time = gettime() + T;
            a[i].dat = 1;
        }
        qsort(a,x,sizeof(table),&tablecmp);
        qsort(b,x,sizeof(table),&tablecmp);
        cnt = 0; maxcnt = 0;
        for(i=0;i<x;i++){
            cnt += a[i].dat;
            maxcnt=cnt<maxcnt?cnt:maxcnt;
        }
        fprintf(out,"%d ",-maxcnt);
        cnt = 0; maxcnt = 0;
        for(i=0;i<x;i++){
            cnt += b[i].dat;
            maxcnt=cnt<maxcnt?cnt:maxcnt;
        }
        fprintf(out,"%d\n",-maxcnt);
    }
    system("pause");
    return 0;
}

int gettime(void){
    int hh,mm;
    fscanf(in,"%d:%d",&hh,&mm);
    return hh * 60 + mm;
}

int tablecmp(const void *a, const void *b){
    int temp;
    temp = ((table *)a)->time - ((table *)b)->time;
    if(temp)return temp;
    return ((table *)b)->dat - ((table *)a)->dat;
}
