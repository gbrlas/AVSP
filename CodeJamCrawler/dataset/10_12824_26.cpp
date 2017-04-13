#include <iostream>
#include <fstream>
#include <math.h>
#include <map>
#include <vector>
#include <list>
#include <string>
using namespace std;

//class path
//{
//	string	   m_Name;
//	list<path> m_childPath;
//};

int main () {

	int iCasesT = 0;
	int iExistN = 0;
	int iCreateM = 0;
	string sPath;
	string sTempPath;
	string delim("/");
	map< string, int > existPath;
	map< string, int >::iterator it;

	fstream fileInput ("A-small-attempt1.in", fstream::in);
	fstream fileOutput ("A-small-attempt1.out", fstream::out);

	
	fileInput >> iCasesT;
	for (int i=0; i<iCasesT; i++)
	{
		existPath.clear();
		fileInput >> iExistN >> iCreateM;

		for (int j=0; j<iExistN; j++)
		{
			
			fileInput >> sPath;
			existPath[sPath] = 1;
		}

		int iCreateTimes = 0;
		for (int k=0; k<iCreateM; k++)
		{						
			fileInput >> sPath;
			it = existPath.find(string(sPath));
			if (it == existPath.end())
			{
				iCreateTimes++;
				existPath[sPath] = 1;

				string::size_type iBeg=0;
				string::size_type iEnd=0;

				iBeg = sPath.find_first_not_of(delim);
				while (iEnd != string::npos)
				{
					iEnd = sPath.find_first_of(delim, iBeg);

					if (iEnd != string::npos)
					{
						sTempPath = sPath.substr(0, iEnd);
						it = existPath.find(string(sTempPath));
						if (it == existPath.end())
						{
							existPath[sTempPath] = 1;
							iCreateTimes++;
						}
						iBeg = iEnd+1;
					}
				}
			}
		}

		fileOutput << "Case #" << i+1 << ": " << iCreateTimes << endl;
	}

	fileInput.close();
	fileOutput.close();

	return 0;
}