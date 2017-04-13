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
int a, b, t;
int rgCnt[1100000];
int nLen;

void GCD(int a, int b)
{
    while(true){
        rgCnt[nLen++] = a / b;
        a %= b;
        if(a == 0) break;
        rgCnt[nLen++] = b / a;
        b %= a;
        if(b == 0) break;
    }
}

int main()
{
    int x, y, nAns;
    int nMaxA, nMaxB, nMinA, nMinB, A, B;
    
    int nMaxCase;
    int nWin = 1;

    scanf("%d", &nMaxCase);
    for(nCase = 1; nCase <= nMaxCase; nCase++){
        scanf("%d%d%d%d", &nMinA, &nMaxA, &nMinB, &nMaxB);
        nAns = 0;
        for(A = nMinA; A <= nMaxA; A++){
            for(B = nMinB; B <= nMaxB; B++){
                a = A;
                b = B;
                nLen = 0;
                if(a < b){
                    t = a;
                    a = b;
                    b = t;
                }
                GCD(a, b);
                nWin = 0;
                if(rgCnt[nLen - 1] > 1) nWin = 1;
                for(x = nLen - 2; x >= 0; x--){
                    if(rgCnt[x] > 1){
                        if(nWin == 1) continue;
                        nWin = 1 - nWin;
                    }else{
                        nWin = 1 - nWin;
                    }
                }
                /*
                for(x = 0; x < nLen; x++){
                    printf("%d ", rgCnt[x]);
                }
                printf("\n");
                if(nWin > 0) printf("+ %d %d\n", A, B);
                else         printf("- %d %d\n", A, B);
                */
                nAns += nWin;
            }
        }
        printf("Case #%d: %d\n", nCase, nAns);
        fflush(stdout);
    }

    return 0;
}

