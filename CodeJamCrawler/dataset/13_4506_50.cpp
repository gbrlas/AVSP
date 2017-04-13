#include<stdio.h>
#include<stdlib.h>

int main(){
    int tt,i,j,k,x,o,t,d,w;
    char a[4][4];
    short c[4];
    FILE *q,*s;
    q=fopen("c:/Ruby193/ques.in","r");
    s=fopen("c:/Ruby193/sol1.txt","w");
    fscanf(q,"%d",&tt);d=fgetc(q);
    i=1;
    while(tt--){
        fputs("Case #",s);
        fprintf(s,"%d",i);i++;
        fputs(": ",s);
        for(j=0;j<4;j++){
            for(k=0;k<4;k++){
                a[j][k]=fgetc(q);
            }
            d=fgetc(q);
        }
        d=fgetc(q);

        for(j=0;j<4;j++) c[j]=0;
        w=0;d=0;
        //row
        for(j=0;j<4&&w==0;j++){
            o=0;t=0;x=0;
            for(k=0;k<4;k++){
                if(a[j][k]=='T') t++;
                else if(a[j][k]=='O') o++;
                else if(a[j][k]=='X') x++;
                else {d=1;c[k]=1;break;}
            }
            if(o==4||(t==1&&o==3)){
                w=1;fputs("O won",s);
            }
            else if(x==4||(x==3&&t==1)){
                w=1;fputs("X won",s);
            }
        }

        //column
        for(k=0;k<4&&w==0;k++){
            o=0;t=0;x=0;
            for(j=0;j<4&&c[k]==0;j++){
                if(a[j][k]=='T') t++;
                else if(a[j][k]=='O') o++;
                else if(a[j][k]=='X') x++;
                else {d=1;break;}
            }
            if(o==4||(t==1&&o==3)){
                w=1;fputs("O won",s);
            }
            else if(x==4||(x==3&&t==1)){
                w=1;fputs("X won",s);
            }
        }

        o=0;t=0;x=0;
        for(j=0;j<4&&w==0;j++){
            if(a[j][j]=='T') t++;
            else if(a[j][j]=='O') o++;
            else if(a[j][j]=='X') x++;
            else {d=1;break;}
        }
        if(o==4||(t==1&&o==3)){
           w=1;fputs("O won",s);
        }
        else if(x==4||(x==3&&t==1)){
           w=1;fputs("X won",s);
        }


        o=0;t=0;x=0;
        for(j=0;j<4&&w==0;j++){
            if(a[j][3-j]=='T') t++;
            else if(a[j][3-j]=='O') o++;
            else if(a[j][3-j]=='X') x++;
            else {d=1;break;}
        }
        if(o==4||(t==1&&o==3)){
           w=1;fputs("O won",s);
        }
        else if(x==4||(x==3&&t==1)){
           w=1;fputs("X won",s);
        }

        if(w==0&&d==1){
            //game not complete
            fputs("Game has not completed",s);
        }
        else if(w==0&&d==0){
            //draw
            fputs("Draw",s);
        }
        fputs("\n",s);
    }
    return 0;
}
