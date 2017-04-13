#include<iostream>
#include<fstream>
#include<cstring>
#include<map>

using namespace std;

int main(){
	int noCases = 0;
	cin >> noCases;
//	cout << "noCases: " << noCases << endl; 
	ofstream fout("output");

	for(int i=0; i<noCases; i++ ){
		int noSwitches=0;

		int noSearch = 0;
		cin >> noSearch;
//		cout << "noSearch: " << noSearch << endl;		
		
		string clean;
		getline(cin, clean);

		map<string, bool> searchMap;
		string searchNames[noSearch];

		for(int j=0; j<noSearch; j++){
			getline(cin,searchNames[j]);
//			cout << j << " " << searchNames[j] << endl; 
			searchMap[searchNames[j]] = false;
			}

		int noQuery = 0;
		cin >> noQuery;
//		cout << "noQuery: " << noQuery << endl;

		getline(cin, clean);

		for(int k=0; k<noQuery; k++){
			string currName;
			getline(cin,currName);
//			cout << currName << endl;
			searchMap[currName] = true;

			bool Switch = true;
			for(int k2=0; k2<noSearch; k2++){
				Switch &= searchMap[searchNames[k2]];
//				cout << "boolSwitch: " << Switch << endl;
				}
//			cout << "boolSwitch: " << Switch << endl;
			if(Switch){ 
				for(int k3 = 0; k3<noSearch; k3++)
					searchMap[searchNames[k3]] = false;
				searchMap[currName] = true;
				++noSwitches;
				}
			}

		fout << "Case #" << i+1 << ": " << noSwitches << endl;
		}

	return 0;
	}
