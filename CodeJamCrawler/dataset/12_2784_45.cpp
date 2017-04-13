
#define IN_FILE "SpeakingInTongues_sm"  // ex, test, sm, lg, 
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
int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifs("DataFiles\\" IN_FILE IN_FILE_EXT);
    ofstream ofs("DataFiles\\" IN_FILE "_A" IN_FILE_EXT);//, ios_base::binary | ios_base::out);

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

        string sFrom = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv zq";
        string sTo   = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up qz";

        map<char, char> mapping;

        for (unsigned int i = 0; i < sFrom.length(); i++)
        {
            mapping[sFrom[i]] = sTo[i];
        }

        map<char, char>::iterator itr = mapping.begin();

        while (itr != mapping.end())
        {
            cout << itr->first << " - " << itr->second << endl;
            ++itr;
        }


        int iCheck = mapping.size();

        for (unsigned int i = 0; i < iTestCases; i++)
        {
            ofs << "Case #" << i + 1 << ": ";  
            cout << "Case #" << i + 1 << ": ";  

            for (unsigned int j = 0; j < vsLines[i].length(); j++)
            {
                char c  = mapping[vsLines[i][j]];
                ofs << c;
                cout << c;
            }

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


    


	return 0;
}
