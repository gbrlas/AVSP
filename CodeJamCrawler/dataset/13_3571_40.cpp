#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

inline bool is_palin(long long n)
{
	stringstream sin;
	sin << n;
	string s = sin.str();
	for (unsigned int i = 0; i < s.size() / 2; i++) {
		if ( s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

void gene_list(vector<long long>& l)
{
	for (long long i = 0; i < pow(10,7); i++) 
		l.push_back(i*i);
}

int main()
{
	vector<long long> carres;
	gene_list(carres);
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		long long a,b;
		cin >> a >> b;
		cout << "Case #" << c << ": ";
		int cpt = 0;
		for (long long i = a; i <= b; i++) {
			if ( is_palin(i) && binary_search(carres.begin(), carres.end(), i) && is_palin(sqrt(i)))
				cpt++;
		}
		cout << cpt << endl;
	}
}
