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
        int nTime = 0;
        int nOPos = 1;
        int nBPos = 1;
        int nBExtraTime = 0;
        int nOExtraTime = 0; 
        
        int nStepNum = 0;
        fileIn >> nStepNum;
        for(int i=0; i<nStepNum; ++i)
        {
             char  cRobutName;
             int   nDst;
             fileIn >> cRobutName;
             fileIn >> nDst;
             
             if(cRobutName == 'O')
             {                
                 nOExtraTime -=  abs(nDst -nOPos);
                 if(nOExtraTime >0)
                     nOExtraTime = 0;
                 nOExtraTime -= 1;
                 nTime -= nOExtraTime;
                 nBExtraTime -= nOExtraTime;
                 nOExtraTime = 0;
                 nOPos = nDst;
             }
             else
             {
                 nBExtraTime -=  abs(nDst -nBPos);
                 if(nBExtraTime >0)
                     nBExtraTime = 0;
                 nBExtraTime -= 1;
                 nTime -= nBExtraTime;
                 nOExtraTime -= nBExtraTime;
                 nBExtraTime = 0;
                 nBPos = nDst;
             }
        }
        fileOut << "Case #" << nCurCase << ": " << nTime << endl;
    }
    return 0;
}
                  
   

