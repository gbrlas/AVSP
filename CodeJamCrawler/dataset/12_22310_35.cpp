#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main() 
{
		int t;
		char c;
		cin >> t;
		string trocas = "yhesocvxduiglbkrztnwjpfmaq";
		scanf("%c", &c);
		for(int i = 1; i <= t; i++) {
				cout << "Case #" << i << ": ";
/*				string linha, palavra;
				getline (cin,linha);
				stringstream ss (linha, stringstream::in | stringstream::out);
				while(ss >> palavra) {
*/
				while(scanf("%c", &c) && c != '\n') {
						if (c > 96 && c < 123) {
								cout << trocas[c-97];
						}
						else 
						{
								cout << c;
						}
				}
				cout << endl;
				}
}

