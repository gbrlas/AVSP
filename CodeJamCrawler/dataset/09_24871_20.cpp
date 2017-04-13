#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<string> ans;
set<string> language;

bool startWith(string t, string s){
	for(unsigned int i=0; i<s.size(); i++){
		if(t[i] != s[i]) return false;
	}
	return true;
}

void getWord(const vector<string>& cases,string s="",int a=0){
	for(unsigned int i=0; i<cases[a].size(); i++){
		s.push_back(cases[a][i]);
		int c=0;
		for each (string t in language){
			if(startWith(t, s)){
				c++;
				break;
			}
		}
		if(c==0){
			s.erase(s.end()-1);
			continue;
		}
		if(a == cases.size()-1){
			ans.push_back(s);
		}else{
			getWord(cases, s, s.size());
		}
		s.erase(s.end()-1);
	}
}

int main(void){
	int L, D, N;
	cin >> L;
	cin >> D;
	cin >> N;
	cin.ignore();

	for(int i=0; i<D; i++){
		string tmp;
		getline(cin,tmp);
		language.insert(tmp);
	}
	for(int i=0; i<N; i++){
		string lecode;
		getline(cin, lecode);
		vector<string> cases(0);
		int count=0;	
		istringstream iss(lecode);
		char c;
		while(iss.get(c)){
			ostringstream value;
			if(c == '('){
				iss.get(c);
				while(c != ')'){
					value << c;
					iss.get(c);
				}
			}else{
				value << c;
			}
			cases.push_back(value.str());
		}
		getWord(cases);
	
		for(unsigned int j=0; j<ans.size(); j++){
			if(language.find(ans[j]) != language.end()) count++;
		}
		ans.clear();
		cout << "Case #" << i+1 << ": " << count << endl;
	}
	return 0;
}
