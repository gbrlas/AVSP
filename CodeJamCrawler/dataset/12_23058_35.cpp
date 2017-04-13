#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(){
	const string mapping = "yhesocvxduiglbkrztnwjpfmaq";
	int n;
	cin >> n;
	string tmp;
	getline(cin, tmp);
	
	for(int i = 0; i < n; i++){
		string str;
		getline(cin, str);
		
		for(int j = 0; j < str.length(); j++){
			if(str[j] == ' ') continue;
			str[j] = mapping[str[j] - 'a'];
		}
		cout << "Case #" << i+1 << ": " << str << endl;
	}
	
	return 0;
}