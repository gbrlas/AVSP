#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	int numberOfTestcases = 0;

	fin >> numberOfTestcases;

	map<string, bool> candidateSearchEngines;

	int i = 0, j = 0;

	int numberOfSearchEngines;
	int numberOfQueries, numberOfContextSwitchesRequired;
	string * searchEngines;
	string currentSearchEngine;
	char buf[100];
	for (i = 0; i < numberOfTestcases; i++) {
	// for each testcase
		fin >> numberOfSearchEngines; 
		fin.getline(buf, 100);

		searchEngines = new string[numberOfSearchEngines];
		for (j=0; j<numberOfSearchEngines; j++) {
		//read all the search engines and add them to the map..
			fin.getline(buf, 100);
			searchEngines[j] = string(buf);
			candidateSearchEngines[searchEngines[j]] = true;
		}

		fin >> numberOfQueries;
		fin.getline(buf, 100);

		numberOfContextSwitchesRequired = 0;
		for (j=0; j<numberOfQueries; j++) {
			//read all the queries..
			
			fin.getline(buf, 100);
			string currentQuery(buf);

			map<string, bool>::iterator iter = candidateSearchEngines.find(currentQuery);
			// if query is same as any of the candidate search engines it is no longer a candidate
			if (iter != candidateSearchEngines.end()) {
				candidateSearchEngines.erase(iter);
			} else if (currentSearchEngine == currentQuery) {
				currentSearchEngine = string("");
			}

			// there are no more candidate search engines, time to switch the search engine and refill the candidate search engines
			if(candidateSearchEngines.empty()) {
				++numberOfContextSwitchesRequired;

				for (int k=0; k<numberOfSearchEngines; k++) {
					candidateSearchEngines[searchEngines[k]] = true;
				}
				candidateSearchEngines.erase(currentQuery);
				currentSearchEngine = currentQuery;
			}
			
		}

		fout << "Case #" << i+1 << ": " <<  numberOfContextSwitchesRequired << endl;
		delete [] searchEngines;
		searchEngines = NULL;
		candidateSearchEngines.clear();
	}

	fout.close();
	fin.close();

	return 0;
}
