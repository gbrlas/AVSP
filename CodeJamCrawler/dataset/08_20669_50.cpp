/* Programming Language = C++
 * Compiler = g++
 */
 
#include <iostream>

using namespace std;

int main()
{
	int n, s, q, testCase, cntName, cntPosition, cntQuery, cntSwitches, highPosition;
	
	cin >> n;
	
	for(testCase = 0; testCase < n; testCase++)
	{
		cin >> s;
		cin.ignore(1,'\n');
		string searchEngine[s];

		for(cntName = 0; cntName < s; cntName++)
		{
			getline (cin, searchEngine[cntName]);
		}

		cin >> q;
		cin.ignore(1,'\n');
		int query[q];
		string name;
		
		for(cntQuery = 0; cntQuery < q; cntQuery++)
		{
			getline(cin, name);
			for(cntName = 0; cntName < s; cntName++)
			{
				if(name.compare(searchEngine[cntName]) == 0)
				{
					query[cntQuery] = cntName;
					break;
				}
			}
		}
		
		cntSwitches = 0;
		cntPosition = 0;
		
		while(cntPosition < q)
		{
			highPosition = cntPosition;
			for(cntName = 0; cntName < s; cntName++)
			{
				for(cntQuery = cntPosition; cntQuery < q; cntQuery++)
				{
					if(query[cntQuery] == cntName)
					{
						if(highPosition < cntQuery)
						{
							highPosition = cntQuery;
						}
						break;
					}
				}
				if(cntQuery == q)
				{
					break;
				}
			}
			if(cntName == s)
			{
				cntPosition = highPosition;
				cntSwitches++;
			}
			else
			{
				cntPosition = q;
			}			
		}
		cout << "Case #" << (testCase + 1) << ": " << cntSwitches << endl;		
	}
	
	return(0);
}
