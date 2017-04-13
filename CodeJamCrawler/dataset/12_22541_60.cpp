#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	// Build the cipher
	string cipher_text = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
	string plain_text  = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";
	map<char, char> cipher;
	for (int i = 0; i < cipher_text.length(); i++) {
		cipher[cipher_text[i]] = plain_text[i];
	}

	// Process input
	int T;
	cin >> T;

	char c;
	while (cin >> c, c == '\n');
	cin.unget();

	for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
		cout << "Case #" << caseNumber << ": ";
		string line;
		getline(cin, line);
		for (string::iterator i = line.begin(); i != line.end(); i++) {
			cout << cipher[*i];
		}
		cout << endl;
	}
}
