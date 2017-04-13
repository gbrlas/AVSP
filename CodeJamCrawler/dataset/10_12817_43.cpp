#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
using namespace std;


struct sOrder
{
	// the passenger number in this order
	int iPassengerNum;			

	// point to the groupSizeVector to indicate the next start point
	vector<int>::iterator itNext; 

	sOrder(int iNumber, vector<int>::iterator it)
	{
		iPassengerNum = iNumber;
		itNext = it;
	}
};

int main () {

	int iCasesT = 0;
	int iRunTimesR = 0;
	int iMaxPeopleK = 0;
	int iGroupNumN = 0;
	int iTotalEuros = 0;

	int iGroupSize = 0;
	vector<int> groupSizeVector;
	groupSizeVector.reserve(10000000);

	map<vector<int>::iterator, sOrder> cacheMap;
	map<vector<int>::iterator, sOrder>::iterator itCatcheMap;

	fstream fileInput ("C-small-attempt0.in", fstream::in);
	fstream fileOutput ("C-small-attempt0.out", fstream::out);

	fileInput >> iCasesT;
	for (int i=0; i<iCasesT; i++)
	{
		fileInput >> iRunTimesR >> iMaxPeopleK >> iGroupNumN;
		
		groupSizeVector.resize(0);
		cacheMap.clear();
		iTotalEuros = 0;
		// Load group size into a vector
		for (int j=0; j<iGroupNumN; j++)
		{
			fileInput >> iGroupSize;
			groupSizeVector.push_back(iGroupSize);
		}

		// iRunTimesR
		vector<int>::iterator itCurrentOrder = groupSizeVector.begin(); 
		for (int r=0; r<iRunTimesR; r++)
		{
			itCatcheMap = cacheMap.find(itCurrentOrder);
			if (itCatcheMap != cacheMap.end())
			{
				iTotalEuros += itCatcheMap->second.iPassengerNum;
				itCurrentOrder = itCatcheMap->second.itNext;
			}
			else
			{
				int iCurrentPassengerNum = 0;
				vector<int>::iterator itBeginOrder = itCurrentOrder; 
				do
				{
					iCurrentPassengerNum += *itCurrentOrder;
					if (iCurrentPassengerNum < iMaxPeopleK)
					{						
						++itCurrentOrder;
						if (itCurrentOrder == groupSizeVector.end())
						{
							itCurrentOrder = groupSizeVector.begin(); 
						}
						if (itCurrentOrder == itBeginOrder)
						{
							break;
						}
					}
					else if (iCurrentPassengerNum == iMaxPeopleK)
					{						
						++itCurrentOrder;
						if (itCurrentOrder == groupSizeVector.end())
						{
							itCurrentOrder = groupSizeVector.begin(); 
						}
						break;
					}
					else
					{
						iCurrentPassengerNum -= *itCurrentOrder;
						break;
					}
				}while(1);

				iTotalEuros += iCurrentPassengerNum;
			    cacheMap.insert(make_pair(itBeginOrder, sOrder(iCurrentPassengerNum, itCurrentOrder)));
			}
		}		

		fileOutput << "Case #" << i+1 << ": " << iTotalEuros << endl;
	}

	fileInput.close();
	fileOutput.close();

	return 0;
}