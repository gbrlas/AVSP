#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int palin(int n){
    int m,d,a=0;
    m=n;
    while(m>0){
        d=m%10;
        m=m/10;
        a=10*a+d;
    }
    if(n==a) return 1;
    return 0;
}
int main(){
    int tt,i,j,n,m,d;
    int a;
    FILE *q,*s;
    q=fopen("c:/Ruby193/ques.in","r");
    s=fopen("c:/Ruby193/sol.txt","w");
    fscanf(q,"%d",&tt);d=fgetc(q);
    i=1;
    while(tt--){
        fputs("Case #",s);
        fprintf(s,"%d",i);i++;
        fputs(": ",s);
        fscanf(q,"%d",&n);d=fgetc(q);
        fscanf(q,"%d",&m);d=fgetc(q);
        printf("%d",n);
        printf(" %d",m);
        a=0;
        j=sqrt(n);
        if(j*j<n) j++;
        while(1){
            //printf("hrere");
            if(palin(j*j)&&palin(j)){ a++;printf("\ninteger:%d palin:%d",j,j*j);}
            j++;
            if(j*j>m) break;
        }
        fprintf(s,"%d",a);
        fputs("\n",s);
    }
    return 0;
}
