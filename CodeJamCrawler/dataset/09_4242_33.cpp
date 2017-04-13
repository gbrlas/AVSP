//code jam

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdarg>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> allwords;
vector<string> table;
string mkja;
int matches = 0;

void create_test_subjects(string expr){
cout  << endl << "create_test_subjects expression: " << expr << endl;
	
	string::iterator itr = expr.begin();

	while(itr != expr.end()){
		if(*itr != '('){
			table.push_back(string(itr,itr+1));
		}else{
			++itr;

			string::iterator itrfind = find(itr, expr.end(), ')');
			string temp(itr, itrfind);

			table.push_back(temp);
			itr = itrfind;
		}
		++itr;
	}
/*	
cout << "table-begin:" << endl;
	vector<string>::iterator itrtab = table.begin();
	while(itrtab != table.end()){
		cout << *itrtab << endl;
		++itrtab;
	}
cout << "table-end" << endl;
*/
}

int main(int argc, char **argv)
{
	if(!(argc > 1)){ cout << "missing filename" << endl; return 1; }
	
	cout << "opening: " << argv[1] << endl;

	ifstream input(argv[1], ios_base::in);

	if(!input.is_open()){ cout << "cannot open file" << endl; return 1; }

//parameters
	int test_cases = 0, word_count = 0, word_length = 0;

cout << "reading parameters" << endl;
	input >> word_length >> word_count >> test_cases;

cout << "test_cases: " << test_cases << ", word_count: " << word_count << ", word_length: " << word_length << endl;
	
	
cout << "reading words" << endl;
	//	pair<set<string::iterator>, bool> result;
	for(int d = 0; d < word_count; ++d){
		string word;
		input >> word;

		allwords.push_back(word);
	}

cout << "testing" << endl;

	ofstream output("out", ios_base::trunc);

	for(int t = 0; t < test_cases; ++t){
		cout << endl << "case " << test_cases << "/"<< t +1 << ":" << endl;
		string expression;
		input >> expression;
		
		create_test_subjects(expression);
		
		matches = 0;
		for(vector<string>::iterator ti = allwords.begin(); ti != allwords.end(); ++ti){

			string::size_type si = 0;
			for(; si != (*ti).length(); ++si){
				
				if(table[si].find((*ti)[si]) == string::npos) break;
			}
			
			if(si == (*ti).length()) ++matches;
		}
		
		output << "Case #" << t+1 << ": " << matches << endl;

		table.erase(table.begin(), table.end());
//		if(allwords.find(expression) != allwords.end()) cout << " MEGVAN" << endl; else cout << " NINCS" << endl;
	}
}

/*
Case #1: Foo
Case #2: 9
Case #3: 10011
Case #4: JAM!
*/