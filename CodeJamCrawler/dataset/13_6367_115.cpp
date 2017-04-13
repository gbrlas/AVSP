#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define SIZE 4
class TicTacToe
{
    char matrix[SIZE][SIZE+1];
    int row[SIZE];
    int col[SIZE];
    int diag[2];
public:
    void solution(char*,char*);
    void input();
    void output();
    void find_result();
};

void TicTacToe::find_result()
{
    int game_comp = 1;
    for(int i=0;i<SIZE;i++) {
        if(row[i]<0) {
            game_comp = 0;
        }
        else if(row[i]%13==0) {
            printf("X won\n");
            return;
        }
        else if(row[i]%7==0) {
            printf("O won\n");
            return;
        }
        if(col[i]<0) {
        }
        else if(col[i]%13==0) {
            printf("X won\n");
            return;
        }
        else if(col[i]%7==0) {
            printf("O won\n");
            return;
        }
    }
    for(int i=0;i<2;i++) {
        if(diag[i]<0) {
        }
        else if(diag[i]%13==0) {
            printf("X won\n");
            return;
        }
        else if(diag[i]%7==0) {
            printf("O won\n");
            return;
        }
    }
    if(game_comp == 0) {
        printf("Game has not completed\n");
    }
    else {
        printf("Draw\n");
    }
}
void TicTacToe::input()
{
    for(int i=0;i<SIZE;i++) {
        scanf("%s",matrix[i]);
        for(int j=0;j<SIZE;j++) {
            switch(matrix[i][j])
            {
                case 'X':
                    matrix[i][j] = 13;
                break;
                case 'O':
                    matrix[i][j] = 7;
                break;
                case '.':
                    matrix[i][j] = -52;
                break;
                case 'T':
                    matrix[i][j] = 0;
                break;
            }
        }
    }
}
void TicTacToe::output()
{
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%d  ",matrix[i][j]);
        }
        printf("\n");
    }
}
void TicTacToe::solution(char *in,char *out)
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        input();
        memset(row,0,4*SIZE);
        memset(col,0,4*SIZE);
        memset(diag,0,4*2);
        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE;j++) {
                if(i==j) {
                    diag[0] += matrix[i][j];
                }
                if(i+j==SIZE-1) {
                    diag[1] += matrix[i][j];
                }
                row[i] += matrix[i][j];
                col[j] += matrix[i][j];
            }
        }
        //output();
        printf("Case #%d: ",t);
        find_result();
    }
}
int main()
{
    TicTacToe ttt;
    ttt.solution("A-small-attempt0.in","out.txt");
    return 0;
}
