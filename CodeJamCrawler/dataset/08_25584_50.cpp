// universe.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int numCases,numEngines,numQueries,i,j;
	string tmpString;
	ifstream ifs ( "input.txt" , ifstream::in );
	ofstream ofs ( "output.txt" , ofstream::out );
	ifs >> numCases;
	//cout << "numCases : " << numCases << endl;

	vector<string> engines;
	vector<string> queries;

	for(i=0;i<numCases;i++){
		engines.clear();
		queries.clear();
		ifs >> numEngines;
		//cout << "numEngines : " << numEngines << endl;
		getline(ifs,tmpString);
		for(j=0;j<numEngines;j++){
			getline(ifs,tmpString);
			engines.push_back(tmpString);
			//cout << tmpString << endl;
		}
		ifs >> numQueries;
		if(numQueries!=0){
		getline(ifs,tmpString);
		for(j=0;j<numQueries;j++){
			getline(ifs,tmpString);
			queries.push_back(tmpString);
			//cout << tmpString << endl;
		}
		}

		int curPos = 0;
		bool end = false;
		int numChange = -1;
		//cout << numEngines;
		//cout << numQueries;

		if(numQueries == 0){
			end = true;
			numChange = 0;
		}

		while(!end){
			numChange++;
			vector<int> curEngines;
			for(j=0;j<numEngines;j++){
				curEngines.push_back(j);
			}
			while(!curEngines.empty()){
				//cout << queries[curPos] << endl;
				for(j=0;j<curEngines.size();j++){
					if(engines[curEngines[j]].compare(queries[curPos])==0){
						//cout << engines[curEngines[j]] << " ** ";
						curEngines.erase(curEngines.begin()+j);	
						break;
					}
				}
					//cout << curEngines.size() << endl;
				if(!curEngines.empty())	
					curPos++;
				//cout << curPos <<endl;
				if(curPos == numQueries){
					end = true;
					break;
				}
			}
			//cout << endl;
		}
		ofs << "Case #" << i+1 << ": " << numChange << endl;
	}


    ifs.close();
	ofs.close();


	return 0;
}

