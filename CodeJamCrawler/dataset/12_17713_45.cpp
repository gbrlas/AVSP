#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main() {

	freopen("D://A-small-attempt1.in", "r", stdin);
	freopen("D://A-small-attempt1.out", "w", stdout);

	string in  = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	map<char, char> m;
	for(int i = 0; i < in.size(); ++i) 
		m.insert(make_pair(in[i], out[i]));
	m.insert(make_pair('z', 'q'));
	m.insert(make_pair('q', 'z'));

	int n;
	cin >> n;
	getchar();
	string tmp;
	int i = 1;
	while(n--) {
		getline(cin, tmp);

		for(int i = 0; i < tmp.size(); ++i) 
			tmp[i] = m[tmp[i]];

		cout << "Case #" << (i++) << ": " << tmp << endl;
	}

	return 0;
}