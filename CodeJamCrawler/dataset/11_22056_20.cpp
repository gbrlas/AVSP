#include <iostream>
#include <fstream>
using namespace std;

enum Result { NO, WIN, LOSE };

int main()
{
    int nTeamNum;
    double WP[100];
    double OWP[100];
    double OOWP[100];
    Result Tbl[100][100];
    int TOTAL[100];
    int W[100];
    
    
    ifstream fileIn("in.txt");
    ofstream fileOut("out.txt");
    int nCaseNum = 0;
    fileIn >> nCaseNum;
    for(int nCurCase = 1; nCurCase<=nCaseNum; ++nCurCase)
    {
        fileIn >> nTeamNum;
        for(int nCurTeam=0; nCurTeam<nTeamNum; ++nCurTeam)
        {
            char tmp;
            int nSum = 0;
            int nWin = 0;
            for(int i=0; i<nTeamNum; ++i)
            {
                fileIn >>tmp;
                if(tmp == '1')
                {
                    Tbl[nCurTeam][i] = WIN;
                    ++nSum;
                    ++nWin;
                }
                else if(tmp == '0')
                {
                    Tbl[nCurTeam][i] = LOSE;
                    ++nSum;
                }
                else
                    Tbl[nCurTeam][i] = NO;
            }
            TOTAL[nCurTeam] = nSum;
            W[nCurTeam] = nWin;
            WP[nCurTeam] = double(nWin)/double(nSum);
        }
        for(int nCurTeam = 0; nCurTeam<nTeamNum; ++nCurTeam)
        {
            double tmp = 0;
            for(int i=0; i<nTeamNum; ++i)
            {
                    
                if(Tbl[nCurTeam][i] == WIN)
                    tmp += (double(W[i])/double(TOTAL[i]-1))/double(TOTAL[nCurTeam]);
                else if(Tbl[nCurTeam][i] == LOSE)    
                    tmp += (double(W[i]-1)/double(TOTAL[i]-1))/double(TOTAL[nCurTeam]);    
            }
            OWP[nCurTeam] = tmp;
        }
        for(int nCurTeam = 0; nCurTeam<nTeamNum; ++nCurTeam)
        {
            double tmp = 0;
            for(int i=0; i<nTeamNum; ++i)
            {
                if(Tbl[nCurTeam][i] != NO)
                    tmp += (double(OWP[i])/double(TOTAL[nCurTeam]));
            }
            OOWP[nCurTeam] = tmp;
        }
        fileOut << "Case #" << nCurCase << ":" << endl;  
        for(int i=0; i<nTeamNum; ++i)
        {
            fileOut <<  0.25*WP[i] + 0.50*OWP[i] + 0.25*OOWP[i] <<endl;
        }
    }
    return 0;
}     
             
