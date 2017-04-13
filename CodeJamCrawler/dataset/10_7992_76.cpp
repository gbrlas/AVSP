#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int nCase;
int rgMark[2000];
unsigned long long rgSale[2000];
int rgNext[2000];
unsigned long long rgGroup[2000];
int nGroup;
unsigned long long nRound, nCap;
unsigned long long nAns;

int main()
{
    int x, y;
    unsigned long long R, nAns;
    unsigned long long nSpace, nSale;
    char szInput[100000];
    char *pToken;
    
    int nMaxCase;
    int p, nPos;

    scanf("%d", &nMaxCase);
    for(nCase = 1; nCase <= nMaxCase; nCase++){
        scanf("%llu%llu%d", &nRound, &nCap, &nGroup);
        for(x = 0; x < nGroup; x++){
            scanf("%llu", &rgGroup[x]);
        }
        nAns = 0; nPos = 0;   
        for(R = nRound; R > 0; R--){
            if(rgMark[nPos] == nCase){
                nAns += rgSale[nPos];
            }else{
                rgMark[nPos] = nCase; 
                nSale = 0;
                nSpace = nCap;
                for(p = nPos; p < nPos + nGroup; p++){
                    if(nSpace < rgGroup[p % nGroup]) break;
                    nSale  += rgGroup[p % nGroup];
                    nSpace -= rgGroup[p % nGroup];
                }
                rgNext[nPos] = p % nGroup;
                rgSale[nPos] = nSale;
                nAns += rgSale[nPos];
            }
            nPos  = rgNext[nPos];
        }

        printf("Case #%d: %llu\n", nCase, nAns);

    }

    return 0;
}

