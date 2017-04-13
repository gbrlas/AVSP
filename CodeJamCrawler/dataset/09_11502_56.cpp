#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main ()
{
	freopen ("B-small.in", "r", stdin);
	freopen ("B-small.out", "w", stdout);
	int t;
	string st;
	cin>>t;
	for (int k = 1; k <= t; k++){
		cin>>st;
		st = "0" + st;
		while (next_permutation (st.begin(), st.end())){
			for (int i = 0; i < st.length(); i++){
				if (st[i] == '0')
					st = st.substr (1, st.length() - 1), i--;
				else
					break;
			}
			printf("Case #%d: %s\n", k, st.c_str());
			break;
		}
	}
}