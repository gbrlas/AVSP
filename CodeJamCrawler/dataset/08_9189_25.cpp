#include <stdio.h>

int 
findMinSwitches( char sName[][103], int qMatches[], int s, int q )
{
    int qIdx, sIdx, sMatch, othMinSw = 0;
    int switchCnt[100] = {0};
    
    for ( qIdx = q - 1; qIdx >= 0; qIdx--) {
        sMatch = qMatches[qIdx];
        othMinSw = q<<2;
        for ( sIdx = 0; sIdx < s; sIdx++ ) {
            if ( sIdx != sMatch && 
                 switchCnt[sIdx] < othMinSw ) {
                othMinSw = switchCnt[sIdx];
            }
        }
        switchCnt[sMatch] = othMinSw + 1;
    }
    return othMinSw;
}

main()
{
    char sName[100][103];
    char qStr[103];
    int  qMatches[1000];
    int n, s, q, c, sIdx, qIdx;
    int result;

    scanf("%d", &n);
    for ( c = 0; c < n; c++ ) {
        scanf("%d", &s);
        gets(qStr); // Skip new line
        for ( sIdx = 0; sIdx < s; sIdx++ ) {
            gets(sName[sIdx]);
        }
        scanf("%d", &q);
        gets(qStr); // Skip new line
        for ( qIdx = 0; qIdx < q; qIdx++ ) {
            gets(qStr);
            for ( sIdx = 0; sIdx < s; sIdx++ ) {
                if ( strcmp(sName[sIdx], qStr) == 0 ) {
                    qMatches[qIdx] = sIdx;
                    break;
                }
            }
        }
        result = findMinSwitches(sName, qMatches, s, q);
        printf("Case #%d: %d\n", c+1, result);
    }
}
