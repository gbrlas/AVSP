#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool is_all(map <string, bool> mp) {
	for (map <string, bool>::iterator i = mp.begin(); i != mp.end(); i++)
		if (!i->second) return false;
	return true;
}

void reset_all(map <string, bool>& mp) {
	for (map <string, bool>::iterator i = mp.begin(); i != mp.end(); i++)
		i->second = false;
}

int main() {
	int n;
	cin >> n;
	for (int cases = 1; cases <= n; cases++) {
		cout << "Case #" << cases << ": ";

		int ns, nq, s=0;
		string tmp;
		map <string, bool> col;

		cin >> ns;
		cin.ignore(3,'\n');

		for (int i = 0; i < ns; i++) {
			getline(cin,tmp);
			col[tmp] = false;
		}

		cin >> nq;
		cin.ignore(3,'\n');

		for (int i = 0; i < nq; i++) {
			getline(cin,tmp);
			col[tmp] = true;
			if (is_all(col)) {
				s++;
				reset_all(col);
				col[tmp]=true;
			}
		}
		cout << s;
		cout << endl;
	}
	return 0;
}