#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;

void main()
{
	ifstream inputfile("test");
	ofstream outputfile("result");
	int nCase;
	string firstLine;
	getline(inputfile, firstLine);
	nCase = atoi(firstLine.c_str());
	
	for(int c = 0; c < nCase; c++)
	{
		string currLine;
		getline(inputfile, currLine);
		int nEngine = atoi(currLine.c_str());
		
		map<string, int> engines;
		for(int e = 0; e < nEngine; e++)
		{
			getline(inputfile, currLine);
			engines.insert(std::make_pair(currLine, 0));
		}

		getline(inputfile, currLine);
		int nQuery = atoi(currLine.c_str());

		int nOccupy = 0;
		int nSwitch = 0;

		for(int q = 0; q < nQuery; q++)
		{
			getline(inputfile, currLine);
			map<string, int>::iterator itr = engines.find(currLine);
			if(itr != engines.end())
			{
				if(itr->second == 0)
				{
					if(nOccupy == nEngine - 1)
					{
						nSwitch++;
						
						map<string, int>::iterator tempitr;
						for(tempitr = engines.begin(); tempitr != engines.end(); tempitr++)
						{
							tempitr->second = 0;
						}
						nOccupy = 1;
						itr->second = 1;
					}
					else
					{
						nOccupy++;
						itr->second = 1;
					}
				}
			}
		}
		outputfile<<"Case #"<<c+1<<": "<<nSwitch<<endl;
	}
}