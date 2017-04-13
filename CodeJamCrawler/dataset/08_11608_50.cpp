#include<stdio.h>
int judge(char dt[],char at[],int t) {
    int dh,dm,ah,am;
    sscanf(dt,"%d:%d",&dh,&dm);
    sscanf(at,"%d:%d",&ah,&am);
    am+=t;
    while(am>=60) {
        ah++;
        am-=60;
    }
    if(ah<dh || (ah==dh && am<=dm))
        return 1;
    else
        return 0;
}

int cmp(const void *a,const void *b) {
    char *p1=(char *)a;
    char *p2=(char *)b;
    return strcmp(p1,p2);
}

int main(void) {
    FILE* out=fopen("e:/ctd/gcjam/bout","w");
    int n,na,nb,t,x;
    char adt[120][10],bdt[120][10],aat[120][10],bat[120][10];
    int atrain[120],btrain[120],ause[120],buse[120];
    scanf("%d",&n);
    for(x=0;x<n;x++) {
        memset(atrain,0,120*sizeof(int));
        memset(btrain,0,120*sizeof(int));
        memset(ause,0,120*sizeof(int));
        memset(buse,0,120*sizeof(int));
        int anum=0,bnum=0;
        scanf("%d",&t);
        scanf("%d %d",&na,&nb);
        int i,j;
        for(i=0;i<na;i++) {
            scanf("%s %s",adt[i],aat[i]);
        }
        for(i=0;i<nb;i++) {
            scanf("%s %s",bdt[i],bat[i]);
        }
        qsort(adt,na,10*sizeof(char),cmp);
        qsort(bdt,nb,10*sizeof(char),cmp);
        qsort(aat,na,10*sizeof(char),cmp);
        qsort(bat,nb,10*sizeof(char),cmp);
        for(i=0;i<na;i++) {
            int flag=0;
            for(j=nb-1;j>=0;j--) {
                if(buse[j]!=1 && judge(adt[i],bat[j],t)==1) {
                    flag=1;
                    buse[j]=1;
                    break;
                }
            }
            if(flag==0) {
                atrain[i]=1;
            }
        }
        for(i=0;i<nb;i++) {
            int flag=0;
            for(j=na-1;j>=0;j--) {
                if(ause[j]!=1 && judge(bdt[i],aat[j],t)==1) {
                    flag=1;
                    ause[j]=1;
                    break;
                }
            }
            if(flag==0) {
                btrain[i]=1;
            }
        }
        for(i=0;i<na;i++) {
            anum+=atrain[i];
        }
        for(i=0;i<nb;i++) {
            bnum+=btrain[i];
        }
        fprintf(out,"Case #%d: %d %d\n",x+1,anum,bnum);
    }
    system("pause");
    return 0;
}
       
