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
        int dancerNum, surpriseNum, p;
        fileIn >> dancerNum;
        fileIn >> surpriseNum;
        fileIn >> p;
        
        int high = 3*p-2;
        int low = 3*p-4;
        
        int result = 0;
        for(int i=0; i<dancerNum; ++i)
        {
            int score;
            fileIn >> score;
            if(score >= high)
                ++result;
            else if(score >= low)
            {
                 if(score >0 && surpriseNum-- >0)
                     ++result;
            }
        }
        fileOut << "Case #" << nCurCase << ": " << result << endl;
    }
    return 0;
}
                 
                         
        
