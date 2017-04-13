#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <set>

using namespace std;


static vector<string> dictionary;
static int L,D,N;

int calculate(string pattern){
	vector<set<char> > vecMap;
	vector<string> strVec;
	string::iterator it;
	int i=0;
	int count = 0;

	string buffer;
	//cout << "==============" << endl;

	if (pattern.find('(') == string::npos){
		//cout << pattern << endl;
		for (int c=0;c<dictionary.size();++c){
			if (dictionary[c] == pattern){
				return 1;
			}
		}
		return 0;
	}
	else {
		//cout << pattern << endl;
		while (i < pattern.length()){
			if (pattern[i] == '('){
				i++;
				set<char> set1;
				while (pattern[i] != ')'){
					set1.insert(pattern[i]);
					//cout << pattern[i];
					i++;
				}
				//cout << endl;
				vecMap.push_back(set1);
				i++;
			}
			else {
				set<char> set1;
				set1.insert(pattern[i]);
				vecMap.push_back(set1);
				//cout << pattern[i] << endl;
				i++;
			}
		}



		for (int i=0;i<dictionary.size();i++){
			for (int j=0;j<dictionary[i].size(); j++){
				if (vecMap[j].find(dictionary[i][j]) == vecMap[j].end()) {
					break;
				}
				else {
					if (j == dictionary[i].size()-1){
						//cout << dictionary[i] << endl;
						++count;
					}
				}
			}
		}
	}
	return count;
}


int main(){


	char buffer[256];


	fstream fin("in1",fstream::in);

	fin >> buffer;
	L = atoi(buffer);
	fin >> buffer;
	D = atoi(buffer);
	fin >> buffer;
	N = atoi(buffer);
	//cout << L << " " << D << " " << N << endl;
	for (int i=0;i< D; ++i){
		string tmp;
		fin >> tmp;
		dictionary.push_back(tmp);
	}

	for (int X=1;X<=N;++X){
		string pattern;
		fin >> pattern;
		//cout << pattern << endl;

		int K = calculate(pattern);
		cout << "Case #" << X  <<  ": " << K << endl;
	}
	fin.close();
}
