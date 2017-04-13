#include<stdio.h>
#define X1 'X'+'X'+'X'+'X'
#define X2 'X'+'X'+'X'+'T'
#define O1 'O'+'O'+'O'+'O'
#define O2 'O'+'O'+'O'+'T'

int T;
char M[10][10], en[2];
bool full;

bool cekX();
bool cekO();

int main() {
    //freopen("A.txt","r",stdin);
    //freopen("A.out","w",stdout);
    
    scanf("%d",&T);
    gets(en);
    for (int t = 0; t < T; t++) {
        full = true;
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                scanf("%c",&M[i][j]);
                if (M[i][j]=='.') full = false;
            }
            gets(en);
        }   gets(en);
        /*
        for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            printf("%c",M[i][j]);
            puts("");
        }   puts("");//*/
        bool xWin = cekX();
        bool oWin = cekO();
        printf("Case #%d: ",t+1);
        if (xWin) printf("X won\n");
        else if (oWin) printf("O won\n");
        else if (full) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}

bool cekO() {
    int o;
    bool oWin;
    for (int i = 1; i <= 4; i++) { //Horizontal
        o = 0;  oWin = false;
        for (int j = 1; j <= 4; j++) {
            o += M[i][j];
            if ( (o==O1)||(o==O2) ) {oWin = true; return oWin;}
        }
    }
    for (int i = 1; i <= 4; i++) { //Vertical
        o = 0;  oWin = false;
        for (int j = 1; j <= 4; j++) {
            o += M[j][i];
            if ( (o==O1)||(o==O2) ) {oWin = true; return oWin;}
        }
    }
    o = 0;  oWin = false;
    o += (M[1][1]+M[2][2]+M[3][3]+M[4][4]);
    if ( (o==O1)||(o==O2) ) {oWin = true; return oWin;}
    
    o = 0;  oWin = false;
    o += (M[1][4]+M[2][3]+M[3][2]+M[4][1]);
    if ( (o==O1)||(o==O2) ) {oWin = true; return oWin;}
    
    return oWin;
}
bool cekX() {
    int x;
    bool xWin;
    for (int i = 1; i <= 4; i++) {//Horizontal
        x = 0;  xWin = false;
        for (int j = 1; j <= 4; j++) {
            x += M[i][j];
            if ( (x==X1)||(x==X2) ) {xWin = true; return xWin;}
        }
    }
    for (int i = 1; i <= 4; i++) {//Vertical
        x = 0;  xWin = false;
        for (int j = 1; j <= 4; j++) {
            x += M[j][i];
            if ( (x==X1)||(x==X2) ) {xWin = true; return xWin;}
        }
    }
    x = 0;  xWin = false;
    x += (M[1][1]+M[2][2]+M[3][3]+M[4][4]);
    if ( (x==X1)||(x==X2) ) {xWin = true; return xWin;}
    
    x = 0;  xWin = false;
    x += (M[1][4]+M[2][3]+M[3][2]+M[4][1]);
    if ( (x==X1)||(x==X2) ) {xWin = true; return xWin;}
    
    return xWin;
}
