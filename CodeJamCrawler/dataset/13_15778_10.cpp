#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void matAlloc(int m, int n, char ***M);
void matFree(char ***M);
int outcome(char **M);

int main(void)
{
    int caso_atual = 1;
    int num_casos = 0;
    char **M;
    int i, j;
    int val_outcome = 0;
    char c;
    char buffer[80];

    cin >> num_casos;
    matAlloc(4, 4, &M);

    while (num_casos > 0) {

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                cin >> M[i][j];
            }
        }

        val_outcome = outcome(M);
        printf("Case #%d: ", caso_atual);

        if (val_outcome == 0)
            printf("Game has not completed\n");
        else if (val_outcome == 1)
            printf("X won\n");
        else if (val_outcome == 2)
            printf("O won\n");
        else
            printf("Draw\n");

        caso_atual++;
        num_casos--;
    }

    matFree(&M);
    return 0;
}

int outcome(char **M)
{

    int s_linha;
    int s_coluna;
    int s_dp = 0;
    int s_ds = 0;
    int i, j;
    int tem_ponto = 0;

    for (i = 0; i < 4; i++) {
        s_linha = 0;
        s_coluna = 0;
        for (j = 0; j < 4; j++) {

            if (M[i][j] == 46)
                tem_ponto = 1;

            s_linha += M[i][j];
            s_coluna += M[j][i];

            if (i == j)
                s_dp += M[i][j];

            if (i + j == 3)
                s_ds += M[i][j];
        }

        if (s_linha == 352 || s_coluna == 352 || s_linha == 348 || s_coluna == 348)
            return 1;

        if (s_linha == 316 || s_coluna == 316 || s_linha == 321 || s_coluna == 321)
            return 2;
    }

    if (s_dp == 352 || s_ds == 352 || s_dp == 348 || s_ds == 348)
        return 1;

    if (s_dp == 316 || s_ds == 316 || s_dp == 321 || s_ds == 321)
        return 2;

    if (tem_ponto)
        return 0;

    return 3;
}

void matAlloc(int m, int n, char ***M)
{
    int i;

    *M = (char **) malloc(m * sizeof(char *));
    (*M)[0] = (char *) malloc(n * m * sizeof(char));

    for (i = 1; i < m; i++) {
        (*M)[i] = (*M)[i-1] + n;
    }
}

void matFree(char ***M)
{
    free((*M)[0]);
    free(*M);
}
