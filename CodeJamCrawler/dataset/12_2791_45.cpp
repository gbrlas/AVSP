
#define IN_FILE "DancingWithGooglers_sm"  // ex, test, sm, lg, 
#define IN_FILE_EXT ".txt"

#define READ_BUFSIZE 0x10000

#include <string>

#include <fstream>
#include <iostream>

#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include <direct.h>
#include <tchar.h>

#include "Shared.h"
#include "Limits.h"

// boost
//#include <boost/dynamic_bitset.hpp>

using namespace std;
//using namespace boost;

//-----------------------------------------------------------------------------
struct QUIZ_DATA
{
    vector<int> Scores;
    unsigned int Surprise;
    unsigned int MinBest;
};

//-----------------------------------------------------------------------------
typedef vector<QUIZ_DATA> QUIZ_DATASET;

//-----------------------------------------------------------------------------
void Process(unsigned int iTestCases, vector<string>& rvLines, QUIZ_DATASET& rvQuizData)
{
    for (unsigned int i = 0; i < iTestCases; i++)
    {
        vector<unsigned int> vi;
        Split(rvLines[i], " ", vi);

        QUIZ_DATA data;
        data.Surprise = vi[1];
        data.MinBest = vi[2];
        data.Scores.insert(data.Scores.begin(), vi.begin() + 3, vi.begin() + 3 + vi[0]);

        rvQuizData.push_back(data);
    }
}
//-----------------------------------------------------------------------------
unsigned int CanReach(unsigned int minResult, unsigned int total)
{
    unsigned int base = 0;
    unsigned int max = 0;

    if (total > 0)
    {
        switch (total % 3)
        {
        case 0:
            base = total / 3;
            max = base + 1;
            break;
        case 1:
            base = total / 3 + 1;
            max = base;
            break;
        case 2:
            base = total / 3 + 1;
            max = base + 1;
            break;
        }    
    }

    if (minResult <= base)
        return 2;
    else if (minResult <= max)
        return 1;

    return 0;
}
//-----------------------------------------------------------------------------
void Solve(QUIZ_DATA& rData, ostream& rOutput)
{
    unsigned int ok = 0;
    unsigned int maybe = 0;

    for (unsigned int i = 0; i < rData.Scores.size(); i++)
    {
        switch (CanReach(rData.MinBest, rData.Scores[i]))
        {
        case 2: 
            ok++;
            break;
        case 1:
            maybe++;
            break;
        default:
            break;
        }
    }
        
    unsigned int a = ok + min(maybe, rData.Surprise);

    rOutput << a;
    cout << a;
}
//-----------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs("DataFiles\\" IN_FILE IN_FILE_EXT);
    ofstream ofs("DataFiles\\" IN_FILE "_A" IN_FILE_EXT);

    char* pBuf = new char[READ_BUFSIZE];

    if (ifs.is_open() && ofs.is_open())
    {
        ifs.getline(pBuf, READ_BUFSIZE);

        unsigned int iTestCases = strtoul(pBuf, NULL, 0);

        vector<string> vsLines;
        vsLines.reserve(400); // random guess

        while (!ifs.eof())
        {
            ifs.getline(pBuf, READ_BUFSIZE);

            if (strlen(pBuf) > 0)
            {
                vsLines.push_back(pBuf);
            }
        }

        QUIZ_DATASET dataset;

        Process(iTestCases, vsLines, dataset);

        for (unsigned int i = 0; i < iTestCases; i++)
        {
            ofs << "Case #" << i + 1 << ": ";  
            cout << "Case #" << i + 1 << ": ";  

            Solve(dataset[i], ofs);

            ofs << endl;
            cout << endl;
        }
    }
    else
    {
        _getcwd(pBuf, READ_BUFSIZE);
        cout << "Check file path: " << pBuf << '\\' << IN_FILE << endl;
    }

    ofs.close();
    ifs.close();

    delete[] pBuf;

    char c;
    cin >> c;

	return 0;
}


