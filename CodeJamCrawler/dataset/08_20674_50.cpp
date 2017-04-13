/* Programming Language = C++
 * Compiler = g++
 */
 
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int n, t, na, nb, testCase, cntA, cntB, cntPos, h, m, absTime, qtA, qtB;
	
	cin >> n;
	
	for(testCase = 0; testCase < n; testCase++)
	{
		cin >> t;
		cin.ignore(1,'\n');
		
		cin >> na;
		cin.ignore(1,'\n');

		cin >> nb;
		cin.ignore(1,'\n');
		
		int depA[na], depB[nb], arrA[na], arrB[nb];
		string schedule;
		
		for(cntA = 0; cntA < na; cntA++)
		{
			getline (cin, schedule);
			
			// departure
			stringstream(schedule.substr(0,2)) >> h;
			stringstream(schedule.substr(3,2)) >> m;
			absTime = (h * 60) + m;
			
			for(cntPos = cntA - 1; cntPos >= 0; cntPos--)
			{
				if(depA[cntPos] >= absTime)
				{
					depA[cntPos + 1] = depA[cntPos];
				}
				else
				{
					depA[cntPos + 1] = absTime;
					break;
				}
			}
			if (cntPos < 0)
			{
				depA[0] = absTime;
			}
			
			// arrival
			stringstream(schedule.substr(6,2)) >> h;
			stringstream(schedule.substr(9,2)) >> m;
			absTime = (h * 60) + m;
			absTime += t;
			
			for(cntPos = cntA - 1; cntPos >= 0; cntPos--)
			{
				if(arrA[cntPos] >= absTime)
				{
					arrA[cntPos + 1] = arrA[cntPos];
				}
				else
				{
					arrA[cntPos + 1] = absTime;
					break;
				}
			}
			if (cntPos < 0)
			{
				arrA[0] = absTime;
			}
		}

		for(cntB = 0; cntB < nb; cntB++)
		{
			getline (cin, schedule);
			
			// departure
			stringstream(schedule.substr(0,2)) >> h;
			stringstream(schedule.substr(3,2)) >> m;
			absTime = (h * 60) + m;
			
			for(cntPos = cntB - 1; cntPos >= 0; cntPos--)
			{
				if(depB[cntPos] >= absTime)
				{
					depB[cntPos + 1] = depB[cntPos];
				}
				else
				{
					depB[cntPos + 1] = absTime;
					break;
				}
			}
			if (cntPos < 0)
			{
				depB[0] = absTime;
			}
			
			// arrival
			stringstream(schedule.substr(6,2)) >> h;
			stringstream(schedule.substr(9,2)) >> m;
			absTime = (h * 60) + m;
			absTime += t;
			
			for(cntPos = cntB - 1; cntPos >= 0; cntPos--)
			{
				if(arrB[cntPos] >= absTime)
				{
					arrB[cntPos + 1] = arrB[cntPos];
				}
				else
				{
					arrB[cntPos + 1] = absTime;
					break;
				}
			}
			if (cntPos < 0)
			{
				arrB[0] = absTime;
			}
		}
		
		qtA = na;
		qtB = nb;
		
		// elimin b
		cntA = 0;
		cntB = 0;
		
		while((cntA < na) && (cntB < nb))
		{
			if (arrA[cntA] <= depB[cntB])
			{
				qtB--;
				cntA++;
				cntB++;
			}
			else
			{
				cntB++;
			}
		}
		
		// elimin a
		
		cntA = 0;
		cntB = 0;
		
		while((cntA < na) && (cntB < nb))
		{
			if (arrB[cntB] <= depA[cntA])
			{
				qtA--;
				cntA++;
				cntB++;
			}
			else
			{
				cntA++;
			}
		}

		cout << "Case #" << (testCase + 1) << ": " << qtA << " " << qtB << endl;
	}
	
	return(0);
}
