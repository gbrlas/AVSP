#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
    int tt,i,j,k,d,n,m,c,r;
    int a[11][11];
    FILE *q,*s;
    q=fopen("c:/Ruby193/ques.in","r");
    s=fopen("c:/Ruby193/sol1.txt","w");
    fscanf(q,"%d",&tt);d=fgetc(q);
    i=1;
    while(tt--){
        fputs("Case #",s);
        fprintf(s,"%d",i);i++;
        fputs(": ",s);
        fscanf(q,"%d",&n);d=fgetc(q);
        fscanf(q,"%d",&m);d=fgetc(q);
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                fscanf(q,"%d",&a[j][k]);d=fgetc(q);
            }
            //d=fgetc(q);
        }
        //d=fgetc(q);
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                printf("%d",a[j][k]);
            }
            printf("\n");
        }

        while(1){
            //rows
            for(j=1;j<=n;j++){
                c=0;r=0;
                for(k=1;k<=m;k++){
                    if(a[j][k]==2) c=1;
                    if(a[j][k]==1) r=1;
                }
                if(c==0&&r==1) break;
            }
            if(c==0&&r==1){
                //jth row contailns all1
                printf("%d row\n",j);

                for(k=1;k<=m;k++){
                    a[j][k]=3;
                }
            }else c=1;
            //columns
            for(j=1;j<=m;j++){
                d=0;r=0;
                for(k=1;k<=n;k++){
                    if(a[k][j]==2) d=1;
                    if(a[k][j]==1) r=1;
                }
                if(d==0&&r==1)
                    break;
            }
            if(d==0&&r==1){
                printf("%d column\n",j);
                //jth column contailns all 1
                for(k=1;k<=n;k++){
                    a[k][j]=3;
                }
            }else d=1;
            if(d==1&&c==1) break;
        }
        c=0;
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                if(a[j][k]==1)
                    c=1;
            }
        }
        if(c==1) fputs("NO\n",s);
        else fputs("YES\n",s);
    }
    return 0;
}
