#include<cstdio>
#include<cstring>
char g[5][5];
int check_d1(){
    if(g[0][0]=='X'&&g[1][1]=='X'&&g[2][2]=='X'&&g[3][3]=='X'||
       g[0][0]=='X'&&g[1][1]=='X'&&g[2][2]=='X'&&g[3][3]=='T'||
       g[0][0]=='X'&&g[1][1]=='X'&&g[2][2]=='T'&&g[3][3]=='X'||
       g[0][0]=='X'&&g[1][1]=='T'&&g[2][2]=='X'&&g[3][3]=='X'||
       g[0][0]=='T'&&g[1][1]=='X'&&g[2][2]=='X'&&g[3][3]=='X')return 1;

    if(g[0][0]=='O'&&g[1][1]=='O'&&g[2][2]=='O'&&g[3][3]=='O'||
       g[0][0]=='O'&&g[1][1]=='O'&&g[2][2]=='O'&&g[3][3]=='T'||
       g[0][0]=='O'&&g[1][1]=='O'&&g[2][2]=='T'&&g[3][3]=='O'||
       g[0][0]=='O'&&g[1][1]=='T'&&g[2][2]=='O'&&g[3][3]=='O'||
       g[0][0]=='T'&&g[1][1]=='O'&&g[2][2]=='O'&&g[3][3]=='O')return 0;

       return -1;
}
int check_d2(){
    if(g[3][0]=='X'&&g[2][1]=='X'&&g[1][2]=='X'&&g[0][3]=='X'||
       g[3][0]=='X'&&g[2][1]=='X'&&g[1][2]=='X'&&g[0][3]=='T'||
       g[3][0]=='X'&&g[2][1]=='X'&&g[1][2]=='T'&&g[0][3]=='X'||
       g[3][0]=='X'&&g[2][1]=='T'&&g[1][2]=='X'&&g[0][3]=='X'||
       g[3][0]=='T'&&g[2][1]=='X'&&g[1][2]=='X'&&g[0][3]=='X')return 1;

    if(g[3][0]=='O'&&g[2][1]=='O'&&g[1][2]=='O'&&g[0][3]=='O'||
       g[3][0]=='O'&&g[2][1]=='O'&&g[1][2]=='O'&&g[0][3]=='T'||
       g[3][0]=='O'&&g[2][1]=='O'&&g[1][2]=='T'&&g[0][3]=='O'||
       g[3][0]=='O'&&g[2][1]=='T'&&g[1][2]=='O'&&g[0][3]=='O'||
       g[3][0]=='T'&&g[2][1]=='O'&&g[1][2]=='O'&&g[0][3]=='O')return 0;

       return -1;
}
int check_c(int c){
    if(g[0][c]=='X'&&g[1][c]=='X'&&g[2][c]=='X'&&g[3][c]=='X'||
       g[0][c]=='X'&&g[1][c]=='X'&&g[2][c]=='X'&&g[3][c]=='T'||
       g[0][c]=='X'&&g[1][c]=='X'&&g[2][c]=='T'&&g[3][c]=='X'||
       g[0][c]=='X'&&g[1][c]=='T'&&g[2][c]=='X'&&g[3][c]=='X'||
       g[0][c]=='T'&&g[1][c]=='X'&&g[2][c]=='X'&&g[3][c]=='X')return 1;

    if(g[0][c]=='O'&&g[1][c]=='O'&&g[2][c]=='O'&&g[3][c]=='O'||
       g[0][c]=='O'&&g[1][c]=='O'&&g[2][c]=='O'&&g[3][c]=='T'||
       g[0][c]=='O'&&g[1][c]=='O'&&g[2][c]=='T'&&g[3][c]=='O'||
       g[0][c]=='O'&&g[1][c]=='T'&&g[2][c]=='O'&&g[3][c]=='O'||
       g[0][c]=='T'&&g[1][c]=='O'&&g[2][c]=='O'&&g[3][c]=='O')return 0;

       return -1;
}
int check_r(int r){
    if(g[r][0]=='X'&&g[r][1]=='X'&&g[r][2]=='X'&&g[r][3]=='X'||
       g[r][0]=='X'&&g[r][1]=='X'&&g[r][2]=='X'&&g[r][3]=='T'||
       g[r][0]=='X'&&g[r][1]=='X'&&g[r][2]=='T'&&g[r][3]=='X'||
       g[r][0]=='X'&&g[r][1]=='T'&&g[r][2]=='X'&&g[r][3]=='X'||
       g[r][0]=='T'&&g[r][1]=='X'&&g[r][2]=='X'&&g[r][3]=='X')return 1;

    if(g[r][0]=='O'&&g[r][1]=='O'&&g[r][2]=='O'&&g[r][3]=='O'||
       g[r][0]=='O'&&g[r][1]=='O'&&g[r][2]=='O'&&g[r][3]=='T'||
       g[r][0]=='O'&&g[r][1]=='O'&&g[r][2]=='T'&&g[r][3]=='O'||
       g[r][0]=='O'&&g[r][1]=='T'&&g[r][2]=='O'&&g[r][3]=='O'||
       g[r][0]=='T'&&g[r][1]=='O'&&g[r][2]=='O'&&g[r][3]=='O')return 0;

       return -1;
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        bool complete(true);
        getchar();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                g[i][j]=getchar();
                if(g[i][j]=='.')complete=false;
            }
            getchar();
        }

        printf("Case #%d: ",kase);
        int res=-1;
        res=check_d1();
        if(res!=-1){
            if(res)printf("X won\n");
            else printf("O won\n");
            continue;
        }
        res=check_d2();
        if(res!=-1){
            if(res)printf("X won\n");
            else printf("O won\n");
            continue;
        }
        for(int i=0;i<4;i++){
           res=check_r(i);
            if(res!=-1){
                if(res)printf("X won\n");
                else printf("O won\n");
                break;
            }
            res=check_c(i);
            if(res!=-1){
                if(res)printf("X won\n");
                else printf("O won\n");
                break;
            }
        }
        if(res==-1){
            if(complete)printf("Draw\n");
            else printf("Game has not completed\n");
        }
    }
}
