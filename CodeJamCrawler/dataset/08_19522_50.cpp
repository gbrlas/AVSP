#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned N;
	cin >> N;
	for(unsigned cases = 0; cases < N; cases++)
	{
		unsigned S;
		unsigned Q;
		set<string> enginesSet;
		vector<string> queriesqueue;
		
		cin >> S;
		string tmp;
		getline(cin, tmp);
		for(unsigned engines = 0; engines < S; engines++)
		{
			string engineName;
			getline(cin, engineName);
			enginesSet.insert(engineName);
		}
		
		cin >> Q;
		getline(cin, tmp);
		string lastQuery = "";
		for(unsigned queries = 0; queries < Q; queries++)
		{
			string actualQuery;
			getline(cin, actualQuery);
			if(actualQuery!=lastQuery)
				queriesqueue.push_back(actualQuery);
			lastQuery = actualQuery;
		}
		
		unsigned minSwitches = 0;
		for(unsigned curpos = 0; curpos < queriesqueue.size();)
		{
			unsigned maxdistance = 0;
			for(set<string>::iterator it_m = enginesSet.begin(); it_m != enginesSet.end(); it_m++)
			{
				vector<string>::iterator firstOccurence = find(queriesqueue.begin()+curpos,queriesqueue.end(),*it_m);
				if(firstOccurence - queriesqueue.begin() > maxdistance)
					maxdistance = firstOccurence - queriesqueue.begin();
			}
			curpos = maxdistance;
			if(curpos<queriesqueue.size())
				minSwitches++;
		}

		cout << "Case #" << cases+1 << ": " << minSwitches << endl;
	}
	return 0;
}
