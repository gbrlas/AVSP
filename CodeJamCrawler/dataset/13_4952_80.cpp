#include <stdio.h>
#define N 1000

int n;
int m[N+1][5][5];
int dap[N+1];
bool is_end=true;

int check(int k){
    int i,j;
    int cntO=0,cntX=0;
    bool winO=false,winX=false;

    for(i=0;i<4;i++){
        cntO=0;
        cntX=0;
        for(j=0;j<4;j++){
            if(m[k][i][j] == 1 || m[k][i][j] == 3){
                cntO++;
            }
            if(m[k][i][j] == 2 || m[k][i][j] == 3){
                cntX++;
            }
        }
        if(cntO == 4)
            winO=true;
        if(cntX == 4)
            winX=true;
        //---
        cntO=0;
        cntX=0;
        for(j=0;j<4;j++){
            if(m[k][j][i] == 1 || m[k][j][i] == 3){
                cntO++;
            }
            if(m[k][j][i] == 2 || m[k][j][i] == 3){
                cntX++;
            }
        }
        if(cntO == 4)
            winO=true;
        if(cntX == 4)
            winX=true;
    }
    //-----------------//
    cntO=0;
    cntX=0;
    for(i=0;i<4;i++){
        if(m[k][i][i] == 1 || m[k][i][i] == 3)
            cntO++;
        if(m[k][i][i] == 2 || m[k][i][i] == 3)
            cntX++;
    }
    if(cntO == 4)
        winO=true;
    if(cntX == 4)
        winX=true;

    cntO=0;
    cntX=0;
    for(i=0;i<4;i++){
        if(m[k][i][3-i] == 1 || m[k][i][3-i] == 3)
            cntO++;
        if(m[k][i][3-i] == 2 || m[k][i][3-i] == 3)
            cntX++;
    }
    if(cntO == 4)
        winO=true;
    if(cntX == 4)
        winX=true;
    //-----------------//
    if(winO == false && winX == false){
        if(is_end == false)
            return -1;
        return 0;
    }else if(winO == true && winX == true){
        return 0;
    }else if(winO == true)
        return 1;
    return 2;
}

int main(){
    int i,j,k;
    char tp;
    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    fscanf(in,"%d",&n);

    for(k=0;k<n;k++){
        fscanf(in,"%c",&tp);
        is_end=true;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                fscanf(in,"%c",&tp);
                //printf("%d[%c] ",tp,tp);
                switch(tp){
                    case 'O' : m[k][i][j]=1;break;
                    case 'X' : m[k][i][j]=2;break;
                    case 'T' : m[k][i][j]=3;break;
                    case '.' : m[k][i][j]=0;is_end=false;
                    //default : m[k][i][j]=123;
                }
                //f
            }
            fscanf(in,"%c",&tp);
        }
        dap[k]=check(k);/*
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                printf("%d ",m[k][i][j]);
            }
            printf("\n");
        }*/
    }

    fclose(in);

    for(i=0;i<n;i++){
        switch(dap[i]){
            case -1 : fprintf(out,"Case #%d: Game has not completed\n",i+1);break;
            case 0 : fprintf(out,"Case #%d: Draw\n",i+1);break;
            case 1 : fprintf(out,"Case #%d: O won\n",i+1);break;
            case 2 : fprintf(out,"Case #%d: X won\n",i+1);break;
        }
    }
    fclose(out);
    return 0;
}
