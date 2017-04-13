#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NUM_LENGTH 7
#define TRUE 1
#define FALSE 0
#define MIRROR 2

int nNumLength, nNumA, nNumB;

int isPairable(int nNumber, int nReplaceLength ){

	char num[100],temp_num[100];
	int len,c,p,numToCheckWith;

	itoa(nNumber,num,10);
	len = strlen(num);

	c=0;
	for( p = len-nReplaceLength; p<len ;p++ )
		temp_num[c++] = num[p];
	for( p = 0; p<len-nReplaceLength;p++ )
		temp_num[c++] = num[p];
	temp_num[c] = 0;

	numToCheckWith = atoi(temp_num);
    if (numToCheckWith == nNumber)
        return MIRROR;
    if( numToCheckWith <= nNumB && numToCheckWith > nNumber )
        return TRUE;
    else
        return FALSE;
}

int main( void ){

    int nCase, i, j=1, count, nReplaceLength;
    int bFound, bMirrorFound;
    char sNumberOnOperation[NUM_LENGTH+1];


	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);


    scanf("%d",&nCase);
    while(j<=nCase){
        if(j!=1) printf("\n");
        printf("Case #%d: ", j);
        scanf("%d %d", &nNumA, &nNumB);

        if( nNumB < 10 ) { printf("0"); j++; continue;}

        i = nNumA;
        count = 0;
        while(i <= nNumB){
            sprintf(sNumberOnOperation, "%d", i);
            nNumLength = strlen(sNumberOnOperation);

            bFound = FALSE;
            nReplaceLength = 1;
            while(!bFound && nReplaceLength < nNumLength){

                if(sNumberOnOperation[nNumLength-nReplaceLength] == '0') {
                    nReplaceLength++;
                    continue;
                }

                bMirrorFound = 0;
                switch(isPairable(i, nReplaceLength)){
                    case TRUE:
                        count++;
                        break;
                    case MIRROR:
                        bMirrorFound = 1;
                    case FALSE:
                        break;
                }
                if( bMirrorFound ) {
                    break;
                }
                nReplaceLength++;
            }
            i++;
        }
        printf("%d",count);
        j++;
    }

    return 0;
}


