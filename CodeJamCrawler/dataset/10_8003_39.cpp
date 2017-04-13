#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int nCase;
char szMaze[100][100];
char szOrg[100][100];
int  rgCnt[100];

char szAns[4][50]= {"Neither","Red","Blue","Both"};
int mx[4] = {1, 1, 0, -1};
int my[4] = {0, 1, 1,  1};

int main()
{
    int x, y, z, nx, ny, c, m;
    int N, K;
    int nAns;
    char szSrc[100000];
    char *pToken;
    
    int nMaxCase;

    scanf("%d", &nMaxCase);
    for(nCase = 1; nCase <= nMaxCase; nCase++){
        scanf("%d%d", &N, &K);
        for(x = 0; x < N; x++){
            scanf("%s", szOrg[x]);
        }
        for(y = 0; y < N; y++){
            for(x = 0; x < N; x++){
                szMaze[y][x] = '.';
            }
            rgCnt[y] = 0;
        }
        for(y = N - 1, z = 0; y >= 0; y--, z++){
            for(x = N - 1; x >= 0; x--){
                if(szOrg[y][x] != '.'){
                    szMaze[rgCnt[N-1-y]++][N-1-y] = szOrg[y][x];
                }
            }
            szMaze[y][N] = 0;
        }
        /*
        for(y = 0; y < N; y++){
            printf("%s\n", szMaze[y]);
        }*/
        nAns = 0;
        for(y = 0; y < N; y++){
            for(x = 0; x < N; x++){
                if(szMaze[y][x] == '.') continue;
                for(m = 0; m < 4; m++){
                    c = 0;
                    nx = x;
                    ny = y;
                    for(c = 1; nx >= 0 && nx < N && ny >= 0 && ny < N && c <= K; c++){
                        if(szMaze[ny][nx] != szMaze[y][x]) break;
                        nx += mx[m];
                        ny += my[m];
                    }
                    if(c > K){
                        if(szMaze[y][x] == 'R') nAns |= 1;
                        if(szMaze[y][x] == 'B') nAns |= 2;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: %s\n", nCase, szAns[nAns]);
    }

    return 0;
}

