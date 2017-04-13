#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fileIn("in.txt");
    ofstream fileOut("out.txt");
    int nCaseNum = 0;
    fileIn >> nCaseNum;
    for(int nCurCase = 1; nCurCase<=nCaseNum; ++nCurCase)
    {
        int nPieceNum = 0;
        fileIn >> nPieceNum;
        
        int nMinNum = 1000001;
        int nSum = 0;
        int nSpecialSum = 0;
        int nCurNum = 0;
        for(int i=0; i<nPieceNum; ++i)
        {
            fileIn >> nCurNum;
            nSum += nCurNum;          
            nSpecialSum = nSpecialSum ^ nCurNum;
            if(nCurNum < nMinNum)
                nMinNum = nCurNum;
        }
        if(0 == nSpecialSum)
        {
            nSum -= nMinNum;
            fileOut << "Case #" << nCurCase << ": " << nSum << endl;
        }
        else
        {
            fileOut << "Case #" << nCurCase << ": " << "NO" << endl;
        }
    }
    return 0;
}
