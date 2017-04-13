#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * dat;
    int index;
} ENTRY;


FILE *in,*out;
int N,S,Q;
int i,j,k,ii,scnt,cnt;
ENTRY a[100];
int b[100];
char buff[101];

void readline(char buffer[]);
int search(char *);
int ENTRYcmp(const void *, const void *);

int main(){
    in = fopen("A-large.in","r");
    out = fopen("A-large.out","w");
    fscanf(in,"%d\n",&N);
    for(i=0;i<100;i++)a[i].dat = malloc(101*sizeof(char));
    
    for(k=0;k<N;k++){
        /*printf("In CASE %d:\n",k+1);*/
        fprintf(out,"Case #%d: ",k+1);
        fscanf(in,"%d\n",&S);
        /*printf("We have %d servers\nThey are:\n",S);*/
        for(i=0;i<S;i++){
            readline(a[i].dat);
            a[i].index = i;
            b[i]=0;
            /*printf("%s\n",a[i].dat);*/
        }
        cnt=0;scnt=0;
        qsort(a,S,sizeof(ENTRY),&ENTRYcmp);
        fscanf(in,"%d\n",&Q);
        /*printf("We got %d queries\n",Q);*/
        for(i=0;i<Q;i++){
            readline(buff);
            j = search(buff);
            if(!b[j]){
                b[j]=1;
                scnt++;
            }
            if(scnt==S){
                cnt++;
                for(ii=0;ii<S;ii++)b[ii]=0;
                b[j]=1;
                scnt=1;
            }
        }
        fprintf(out,"%d\n",cnt);
    }
    
    for(i=0;i<100;i++)free(a[i].dat);
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}

void readline(char buffer[]){
    char character;
    int i=0;
    character = fgetc(in);
    if(character!='\n')buffer[i++]=character;
    do
    {
        character = fgetc(in);
        buffer[i] = character;
        ++i;
    }
    while(character!='\n');
    buffer[i-1] = '\0';
    /*printf("String \"%s\" read\n",buffer);*/
}

int ENTRYcmp(const void *a, const void *b){
    ENTRY *x,*y;
    x = (ENTRY *)a;
    y = (ENTRY *)b;
    return strcmp(x->dat,y->dat);
}

int search(char *buffer){
    ENTRY *t;
    ENTRY x;
    x.dat = buffer;
    x.index = -1;
    t = (ENTRY *)bsearch(&x, a, S, sizeof(ENTRY), &ENTRYcmp);
    /*if(t==NULL){
        printf("search of term %s\n",buffer);
        printf("Not found\n");return 0;}
    else*/ return t->index;
}
