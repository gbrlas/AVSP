
#define IN_FILE "RecycledNumbers_sm"  // ex, test, sm, lg, 
#define IN_FILE_EXT ".in"
#define OUT_FILE_EXT ".out"

#define READ_BUFSIZE 0x10000

#include <string>

#include <fstream>
#include <iostream>

#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include <conio.h>
#include <direct.h>
#include <tchar.h>


#include "Shared.h"
#include "Limits.h"

// boost
//#include <boost/dynamic_bitset.hpp>

using namespace std;
//using namespace boost;

//-----------------------------------------------------------------------------
typedef pair<unsigned int, unsigned int> QUIZ_DATA;

//-----------------------------------------------------------------------------
typedef vector<QUIZ_DATA> QUIZ_DATASET;

//-----------------------------------------------------------------------------
void Process(unsigned int iTestCases, vector<string>& rvLines, QUIZ_DATASET& rvQuizData)
{
    for (unsigned int i = 0; i < iTestCases; i++)
    {
        vector<unsigned int> vi;
        Split(rvLines[i], " " , vi);

        rvQuizData.push_back(make_pair(vi[0], vi[1]));
    }
}

//-----------------------------------------------------------------------------
typedef vector<pair<unsigned int, vector<unsigned int> > > RECYCLE_MAP;

//-----------------------------------------------------------------------------
inline bool FindRecylable(unsigned int in, vector<unsigned int>& rvOut)
{
    string s = ToString(in);
    unsigned int len = s.length();

    for (unsigned int i = 1; i < len; i++)
    {
        unsigned int from = len - i;
        if (s[from] != '0')
        {
            string cvrt = s.substr(from) + s.substr(0, len - i);

            unsigned int iCvrt = ToUInt(cvrt.c_str());

            if (in < iCvrt && iCvrt <= 2000000)
                rvOut.push_back(iCvrt);
        }
    }

    if (in % 10000 == 0)
        cout << in << endl;

    return !rvOut.empty();

    /*
    if (!rvOut.empty())
    {
        cout << in << ": ";

        for (unsigned int i = 0; i < rvOut.size(); i++)
        {
            cout << rvOut[i] << ", ";
        }

        cout << endl;

        return true;
    }

    return false;
    */
}
//-----------------------------------------------------------------------------
void CreateMap(RECYCLE_MAP& rMap)
{
    vector<unsigned int> vi;
    for (unsigned int i = 12; i <= 2000000; i++)
    {
        vi.clear();
        if (FindRecylable(i, vi))
        {
            rMap.push_back(make_pair(i, vi));
        }
    }
}
//-----------------------------------------------------------------------------
void Solve(QUIZ_DATA& rData, ostream& rOutput, RECYCLE_MAP& rMap)
{
    unsigned int a = 0;

    for (unsigned int i = 0; i < rMap.size(); i++)
    {
        if (rMap[i].first < rData.first)
            continue;

        if (rMap[i].first > rData.second)
            break;

        for (unsigned int j = 0; j < rMap[i].second.size(); j++)
        {
            if (rMap[i].second[j] <= rData.second)
                a++;
        }
    }

    rOutput << a;
    cout << a;
}
//-----------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs("DataFiles\\" IN_FILE IN_FILE_EXT);
    ofstream ofs("DataFiles\\" IN_FILE OUT_FILE_EXT);

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

        RECYCLE_MAP map;
        map.reserve(2000000);
        CreateMap(map);

        for (unsigned int i = 0; i < iTestCases; i++)
        {
            ofs << "Case #" << i + 1 << ": ";  
            cout << "Case #" << i + 1 << ": ";  

            Solve(dataset[i], ofs, map);

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

    getch();

	return 0;
}


