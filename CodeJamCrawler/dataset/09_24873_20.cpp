#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

const string word = "welcome to code jam";
unsigned long int ans;

void f(const string& lecode, int start=0, int c=0){
	if(c == word.size()){
		ans++;
		return;
	}
	for(unsigned int i=start; i<lecode.size(); i++){
		if(lecode[i] == word[c]){
			f(lecode, i+1, c+1);
		}
	}
	return;
}

int main(void){
	int N;
	cin >> N;
	cin.ignore();
	for(int i=0; i<N; i++){
		ans=0;
		string lecode = "";
		getline(cin, lecode);
		f(lecode);
		ans %= 10000;
		char s[4];
		sprintf(s, "%04d", ans);

		cout << "Case #" << i+1 << ": " << s << endl;
		ans = 0;
	}
	return 0;
}
