#include <stdio.h>

int n;
int x,y;
int m[150][150];
bool dap[150];

bool lineChk(int n1, int n2){
    int i;
    bool c1=true,c2=true;

    for(i=0;i<x;i++){
        if(m[n1][i] > m[n1][n2]){
            c1=false;
            break;
        }
    }
    for(i=0;i<y;i++){
        if(m[i][n2] > m[n1][n2]){
            c2=false;
            break;
        }
    }
    if(c1 == false && c2 == false){
        return false;
    }
    return true;
}

bool chk(){
    int i,j;

    for(i=0;i<y;i++){
        for(j=0;j<x;j++){
            if(lineChk(i,j) == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int i,j,k;
    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    fscanf(in,"%d",&n);
    for(k=0;k<n;k++){
        fscanf(in,"%d%d",&y,&x);
        for(i=0;i<y;i++){
            for(j=0;j<x;j++){
                fscanf(in,"%d",&m[i][j]);
            }
        }
        dap[k]=chk();
    }
    fclose(in);
    for(i=0;i<n;i++){
        if(dap[i] == true)
            fprintf(out,"Case #%d: YES\n",i+1);
        else
            fprintf(out,"Case #%d: NO\n",i+1);
    }

    fclose(out);
    return 0;
}
