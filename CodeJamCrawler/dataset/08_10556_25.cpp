
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned int    uint;
typedef enum tagBOOL 
{  
    FALSE, 
    TRUE 
} BOOL;

#define LOCAL           static


#define ABSF(f)         (((f) >= 0.0) ? (f) : ((f) * -1.0))

typedef struct tagSInfo
{
    char strSearch[101];
    int iNumTo;
}SINFO;

/*
 * 
 */
int main(int argc, char** argv) 
{
    char strFileName[30];
    FILE *pF;
    
    char strTotal[101];
    uint uiTotalIn;
    uint uiCont;
    FILE *pfOutput;
    
    char strS[101];
    int iS;
    int iX;
    SINFO *ptrSInfoIni;
    SINFO *ptrSInfo;
    
    char strQ[101];
    int iQ;
    int iY;
    char *ptrQueriesIni;
    char *ptrQueries;
    
    FILE *pOut;
    int iSwitch;
    
    BOOL bOk;
    int iMax;
    int iLenQ;
    

    
    // try to get user's file
    if (argc > 1) {
        strcpy(strFileName, argv[1]);
    }
    // no one specified, use default
    else {
        strcpy(strFileName, "A-small-attempt3.in");
    }
    
    // if sucessfull open arqchive
    if ((pF = fopen(strFileName, "rt")) != NULL) {
        
        pOut = fopen("A-small.out", "wt");
        
        fgets(strTotal, 100, pF);
        uiTotalIn = atoi(strTotal);
        printf("Total Input: %u\n", uiTotalIn);
        
        for (   uiCont = 0; 
                uiCont < uiTotalIn; 
                //uiCont < 3; 
                ++uiCont) 
        {
            
            fgets(strS, 100, pF);
            iS = atoi(strS);
            printf("Num Search Engine: %u\n", iS);
            ptrSInfoIni = (SINFO *) malloc(sizeof(SINFO) * iS);
            
            for (iX = 0; iX < iS; ++iX) 
            {
                ptrSInfo = (ptrSInfoIni + iX);
                fgets(ptrSInfo->strSearch, 100, pF);
                ptrSInfo->strSearch[strlen(ptrSInfo->strSearch) - 1] = '\0';
                printf("\t%s\n", ptrSInfo->strSearch);                
            }
            
            fgets(strQ, 100, pF);
            iQ = atoi(strQ);
            printf("Num Queries: %u\n", iQ);
            ptrQueriesIni = malloc(101 * iQ);
            for (iY = 0; iY < iQ; ++iY) 
            {
                ptrQueries = (ptrQueriesIni + (iY *  101)) ;
                fgets(ptrQueries, 100, pF);
                ptrQueries[strlen(ptrQueries) - 1] = '\0';
                printf("\t\t%s\n", ptrQueries);                
            }
            
            fprintf(pOut, "Case #%i: ", (uiCont+1));

            iSwitch = -1;
            iLenQ = 0;
            do {
                

                for (iX = 0; iX < iS; ++iX) 
                {
                    ptrSInfo = (ptrSInfoIni + iX);
                    ptrSInfo->iNumTo = 0;
                }
                
                
                for (iX = 0; iX < iS; ++iX) 
                {
                    ptrSInfo = (ptrSInfoIni + iX);
                    bOk = TRUE;
                    for (iY = iLenQ; iY < iQ && bOk; ++iY) 
                    {
                        ptrQueries = (ptrQueriesIni + (iY *  101)) ;
                        
                        //printf("S:(%s) Q:(%s)\n", ptrSInfo->strSearch, ptrQueries);
                        if (strcmp(ptrSInfo->strSearch, ptrQueries) == 0) 
                        {
                            ptrSInfo->iNumTo = iY;
                            bOk = FALSE;
                            printf("\n\nACHOU iX = %i, iY = %i\n\n", iX, iY);
                        }                    
                    }
                    if (bOk == TRUE) {
                        ptrSInfo->iNumTo = iY;
                    }
                }

                iMax = 0;
                for (iX = 0; iX < iS; ++iX) 
                {
                    ptrSInfo = (ptrSInfoIni + iX);
                    if (ptrSInfo->iNumTo > iMax) {
                        iMax = ptrSInfo->iNumTo;
                    }
                }
                printf("iMax: %i\n", iMax);
                printf("iLenQ: %i\n", iLenQ);
                printf("iQ: %i\n", iQ);
                printf("iSwitch: %i\n", iSwitch);
                
                //getchar();
                
                iLenQ = iMax;
                iSwitch++;
          
            } while (iMax < iQ);



          
            fprintf(pOut, "%u\n", iSwitch);           
           
            free(ptrSInfoIni);
            free(ptrQueriesIni);            
            
        }
        
        
        fclose(pOut);
        
        fclose(pF);    
    }
    // Failures, warning the user
    else {
        fprintf(stderr, "ERROR: could not open file %s\n", strFileName);
    }

    
    return (EXIT_SUCCESS);
}

