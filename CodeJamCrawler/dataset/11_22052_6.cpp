#include <iostream>
#include <fstream>
using namespace std;

bool Smaller(int& nUp,int& nDown)
{
    if(nUp == 0)
    {
        nDown = 1;
        return true;
    }
    bool bRet = false;
    for(int i=2; i<=nUp; ++i)
    {
        if(nUp%i == 0 && nDown%i == 0)
        {
            nUp = nUp/i;
            nDown = nDown/i;
            bRet = true;
            break;
        }
    }
    return bRet;
}
    

int main()
{
    ifstream fileIn("in.txt");
    ofstream fileOut("out.txt");
    int nCaseNum = 0;
    fileIn >> nCaseNum;
    for(int nCurCase = 1; nCurCase<=nCaseNum; ++nCurCase)
    {
        bool bPossible = false;
        int nMaxGame = 0;
        int nPd = 0;
        int nPg = 0;
        fileIn >> nMaxGame;
        fileIn >> nPd;
        fileIn >> nPg;
        
        if((nPg == 100 && nPd < 100) || (nPg == 0 && nPd > 0))
            bPossible = false;
        else
        {
            int nUp = nPd;
            int nDown = 100;
            while(nDown>nMaxGame)
            {
                if(!Smaller(nUp,nDown))
                    break;
            }
            bPossible = (nDown <= nMaxGame);
        }
        if(bPossible)
            fileOut << "Case #" << nCurCase << ": Possible" << endl;
        else
            fileOut << "Case #" << nCurCase << ": Broken" << endl;
    }
    return 0;
}      
            
            
            
            
