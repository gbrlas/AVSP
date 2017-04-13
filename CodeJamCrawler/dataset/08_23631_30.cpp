#include <iostream>
#include <string>
#include <vector>
using namespace std;


int solve(vector<string> searchEngines, vector<string> queries)
{
	int solution = 0;
	int lastQuery = 0;

	while(lastQuery < (queries.size()))
	{
		int maxQueries = 0;
		int maxSearchEngine = 0;

		for(int i = 0; i < searchEngines.size(); i++)
		{
			int q = lastQuery;
			int numQueries = 0;
			while(q < queries.size() && searchEngines[i] != queries[q])
			{
				q++;
				numQueries++;
			}
			if(numQueries > maxQueries)
			{
				maxQueries = numQueries;
				maxSearchEngine = i;
			}
		}
		lastQuery += maxQueries;
		solution++;
	}
	if(solution > 0) solution--;
	return solution;
}
int main()
{
	int numCases = 0, numSearchEngines = 0, numQueries = 0;
	vector<string> searchEngines, queries;
	cin>>numCases;
	string s;
	for(int i = 1; i <= numCases; i++)
	{
		cin>>numSearchEngines;
		cin.ignore(1);
		for(int j = 0; j < numSearchEngines; j++)
		{
			getline(cin,s);
			searchEngines.push_back(s);
		}
		
		cin>>numQueries;
		cin.ignore(1);
		for(int j = 0; j < numQueries; j++)
		{
			getline(cin,s);
			queries.push_back(s);
		}
		
		int solution = solve(searchEngines,queries);
		cout<<"Case #"<<i<<": "<<solution<<endl;
		searchEngines.clear();
		queries.clear();

	}
	return 0;
}