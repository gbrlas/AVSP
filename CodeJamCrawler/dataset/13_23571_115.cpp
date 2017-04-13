#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

string itos(int n)
{
   stringstream ss;
   ss << n;
   return ss.str();
}

bool isPalindrome(string s) {
	int sz = s.size();
	int hfsz = sz/2;
	for(int i = 0; i < hfsz; i++)
		if(s[i] != s[sz-1-i])
			return false;
	return true;
}

int main() {
	int T, a, b, sa, sb, i, j, count;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> a >> b;
		sa = (int)ceil(sqrt(a));
		sb = (int)floor(sqrt(b));
		count = 0;
		for(i = sa; i <= sb; i++) {
			if(isPalindrome(itos(i)) && isPalindrome(itos(i*i))) count++;
		}
		cout << "Case #" << t << ": " << count << endl;
	}
	return 0;
}
