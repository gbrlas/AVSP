#include <vector>
#include <string>
#include <iostream>
using namespace std;



int main()
{
	vector<string> queries;
	vector<string> searchEngines;
	int numOfSearchEngs = 0;
	int numOfQueries = 0;
	int numOfCases = 0;
	string sEngine;
	string sQuery;
	int switches, latestIndex, startIndex;
	//char buffer[100] = "";

	
	cin>>numOfCases;
	
	for(int i = 0; i < numOfCases; i++)
	{
		queries.clear();
		searchEngines.clear();
		switches = 0;
		latestIndex = 0;
		startIndex = 0;
		
		cin>>numOfSearchEngs;
		cin.ignore(1);
		for(int j = 0; j < numOfSearchEngs; j++)
		{
			getline(cin,sEngine);
			searchEngines.push_back(sEngine);
			//cout<<sEngine<<endl;
		}
		
		cin>>numOfQueries;
		cin.ignore(1);		
		for(int k = 0; k < numOfQueries; k++)
		{
			getline(cin,sQuery);
			queries.push_back(sQuery);
		}
				
		while(latestIndex < (int)queries.size())
		{
			for(int l = 0; l < (int)searchEngines.size(); l++)
			{
				for(int m = startIndex; m < (int)queries.size(); m++)
				{
					if(searchEngines[l] == queries[m])
					{
						if(m > latestIndex) latestIndex = m - 1;
						m = (int)queries.size();
					}
					else 
					{	
						if(m > latestIndex)
						{
							if(m == (int)queries.size() - 1 &&
								searchEngines[l] != queries[m])
							{
								latestIndex = m + 1;
							}
							else
							{
								latestIndex = m;
							}
						}
					}
				}
				//cout<<"###"<<searchEngines[l]<<" : "<<latestIndex<<endl;
			}
			
			if(latestIndex < (int)queries.size())
			{
				switches++;
				startIndex = latestIndex + 1;	
			}
			
		}
	
		cout<<"Case #"<<i+1<<": "<<switches<<endl;
		
	}
	
	


	return 0;
}