#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
int main() {
	int cases;

	cin >> cases;
	for( int i = 1; i <= cases; i++ ) {
		string input;
		stringstream ss;

		cin >> input;

		ss << input;
		long long vbef;
		ss >> vbef;
		next_permutation( input.begin(), input.end() );
	
/*	
		cout << "After ";
		cout << input << endl;
*/
		stringstream numss;
		int zero = 0;
		int intozero = 1;
		int putzero = 0;
		for( int x = 0; x < input.size(); x++ ) {
			if(intozero == 1 && input[x] == '0') {
				zero++;
				putzero = 1;
			}
			else {
				intozero = 0;
				numss << input[x];
				if( putzero == 1) {
					for( int z = 0; z <= zero; z++) {
						numss << 0;
					}
					putzero = 0;
				}
			}
		}

		long long vaft;
		numss >> vaft;
		input = numss.str();
		if( vaft <= vbef) {
			stringstream ss3;
			ss3 << "Case #" << i << ": ";
			ss3 << input[0];
			ss3 << 0;
			ss3 << input.substr(1);
			ss3 << endl;  
			cout << ss3.str();
		} else {
			cout << "Case #" << i << ": " << input << endl;
		}
	}

	return 0;
}
