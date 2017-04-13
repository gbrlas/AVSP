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


int main()
{
    int x, y;
    char szInput[100000];
    char *pToken;
    long long K, N;
    long long rgP2[40];
    rgP2[0] = 1;
    for(int x = 1; x < 40; x++){
        rgP2[x] = rgP2[x - 1] * 2;
    }
    
    int nMaxCase;

    scanf("%d", &nMaxCase);
    for(nCase = 1; nCase <= nMaxCase; nCase++){
        scanf("%lld%lld", &N, &K);
        K %= rgP2[N];
        if(K != rgP2[N] - 1){
            printf("Case #%d: OFF\n", nCase);
        }else{
            printf("Case #%d: ON\n", nCase);
        }
    }

    return 0;
}

