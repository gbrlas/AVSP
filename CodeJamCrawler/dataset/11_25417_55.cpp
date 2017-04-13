// I love natalia

#include <iostream>
#include <cstdio>
#include <string>
#include <list>

using namespace std;

int  aC['Z'+1]['Z'+1];
bool aD['Z'+1]['Z'+1];

int main() {
	freopen( "input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int    T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int    C;
		cin >> C;

		int  aC['Z'+1]['Z'+1];
		memset(aC, 0, sizeof(aC));

		for (int c = 0; c < C; c++) {
			string s;
			cin >> s;

			aC[s[0]][s[1]] = s[2];
			aC[s[1]][s[0]] = s[2];
		}

		int    D;
		cin >> D;

		bool aD['Z'+1]['Z'+1];
		memset(aD, 0, sizeof(aD));

		for (int d = 0; d < D; d++) {
			string s;
			cin >> s;

			aD[s[0]][s[1]] = true;
			aD[s[1]][s[0]] = true;
		}

		int    N;
		cin >> N;

		list <char> L;

		for (int n = 0; n < N; n++) {
			char   ch;
			cin >> ch;

			if ( L.size() > 0 ) {
				if ( aC[L.back()][ch] ) {
					L.back() = aC[L.back()][ch];
					continue;
				}

				if ( aC[ch][L.back()] ) {
					L.back() = aC[ch][L.back()];
					continue;
				}
			}

			L.push_back(ch);

			for (list <char>::iterator it = L.begin(); it != L.end(); it++)
				if ( aD[*it][ch] || aD[ch][*it] ) {
					L.clear();
					break;
				}
		}

		cout << "Case #" << t << ": [";

		for (list <char>::iterator it = L.begin(); it != L.end(); ) {
			char tmp = *it;

			it++;

			if ( it != L.end() )
				cout << tmp << ", ";
			else
				cout << tmp;
		}

		cout << "]" << endl;
	}

	return 0;
}
