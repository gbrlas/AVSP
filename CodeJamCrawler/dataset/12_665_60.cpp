#include <iostream>
#include <cassert>

using namespace std;

char english[] = {
'y',
'h',
'e',
's',
'o',
'c',
'v',
'x',
'd',
'u',
'i',
'g',
'l',
'b',
'k',
'r',
'z',
't',
'n',
'w',
'j',
'p',
'f',
'm',
'a',
'q'
};

void handle_case(int case_nbr) {
	 cout << "Case #" << case_nbr << ": ";

	 string line;
	 getline(cin, line);

	 for (size_t i = 0; i < line.length(); i++) {
		  if (line[i] >= 'a' && line[i] <= 'z') {
				cout << english[line[i]-'a'];
		  }
		  else if (line[i] == ' ') {
				cout << line[i];
		  }
		  else {
				assert(false);
		  }
	 }
	 cout << endl;
}

int main(void) {

	 int T;

	 cin >> T;
	 string str;
	 getline(cin, str);

	 for (int i = 0; i < T; i++) {
		  handle_case(i+1);
	 }
	 
	 return 0;
}
