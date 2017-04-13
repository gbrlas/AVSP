#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

typedef struct {
    bool bStartA;
    int  start;
    int  end;
}TrainSchedule;

int compare(const void * src, const void * dst)
{
    TrainSchedule * pSrc = *(TrainSchedule **) src;
    TrainSchedule * pDst = *(TrainSchedule **) dst;
    return pSrc->start - pDst->start;
}


int main()
{
    int nA,nB,interval,n;
    int i,j,k;
    int caseCnt = 0,minCntA,minCntB;
    TrainSchedule * pSchedule = new TrainSchedule[200];
    static TrainSchedule * pTable[200];
    TrainSchedule * pCurrent;
    TrainSchedule **pTableEntry = NULL,**pTableStart,**pEntrySwap;
    cin>>n;
    while( n-- ){
        int hour,minute,currentSize;
        char c;
        cin>>interval>>nA>>nB;
        pCurrent = pSchedule;
        pTableStart = pTable;
        minCntA = minCntB = 0;
        for ( i = 0; i < nA ; i++ ) {
            pCurrent->bStartA = true;
            cin>>hour>>c>>minute;
            pCurrent->start = hour * 60 + minute;
            cin>>hour>>c>>minute;
            pCurrent->end = hour * 60 + minute;
            *pTableStart++ = pCurrent;
            pCurrent++;
        }

        for ( i = 0; i < nB ; i++ ) {
            pCurrent->bStartA = false;
            cin>>hour>>c>>minute;
            pCurrent->start = hour * 60 + minute;
            cin>>hour>>c>>minute;
            pCurrent->end = hour * 60 + minute;
            *pTableStart++ = pCurrent;
            pCurrent++;
        }
        currentSize = nA + nB;
        qsort(pTable,currentSize, sizeof(TrainSchedule *),compare);
        pTableStart =pTable;
        while ( currentSize ) {
            int entryCnt = 1;
            if ( currentSize == 1 ) {
                pTableStart[0]->bStartA?minCntA++:minCntB++;
                break;
            }
            pTableEntry = pTableStart+1;
            pCurrent = pTableStart[0];
            pEntrySwap = pTableEntry;
            pCurrent->bStartA?minCntA++:minCntB++;
            while ( pTableEntry != pTableStart + currentSize ) {
                if ( pTableEntry[0]->bStartA != pCurrent->bStartA &&
                     pTableEntry[0]->start - pCurrent->end >= interval ) {
                    pCurrent = pTableEntry[0];
                    pTableEntry[0] = pEntrySwap[0];
                    pEntrySwap++;
                    entryCnt++;
                }
                pTableEntry++;
            }
            currentSize -= entryCnt;
            pTableStart += entryCnt;
            qsort(pTableStart,currentSize,sizeof(TrainSchedule *),compare);
        }
        cout<<"Case #"<<++caseCnt<<": "<<minCntA<<" "<<minCntB<<endl;
    }
    delete [] pSchedule;
    return 0;
}