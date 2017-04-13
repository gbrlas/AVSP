#include <iostream>

using namespace std;

int main(){
	char c[] = "yhesocvxduiglbkrztnwjpfmaq";
	
	int n;
	int m[256] = {0};
	
	cin >> n;
	cin.ignore();
	
	for(int i=0; i<26; ++i) m[i+'a'] = c[i];
	
	for(int q=1; q<=n; ++q){
		string s;
		getline(cin, s);
		
		cout << "Case #" << q << ": ";
		
		for(int i=0; i<s.size(); ++i){
			if(s[i] == ' ') cout << ' ';
			else cout << (char)m[s[i]];
		}
		cout << '\n';
	}
	
	return 0;
}
