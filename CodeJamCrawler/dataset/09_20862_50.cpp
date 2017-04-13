#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void) {
	int T, prob = 0;
	for (cin >> T; T; T--) {
		string message;
		cin >> message;
		vector< char > digits;
		for (int i = 0; i < message.length(); i++) {
			bool flag = true;
			for (int j = 0; j < digits.size(); j++) {
				if (message[i] == digits[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				digits.push_back(message[i]);
		}
		if (digits.size() == 1) {
			if (digits[0] != '0')
				digits.push_back('0');
			else
				digits.push_back('A');
		}
		if (digits.size() > 1) {
			char tmp = digits[1];
			digits[1] = digits[0];
			digits[0] = tmp;
		}else {
			cout << "NOTICE!" << endl;
		}
		/*
		cout << "digits: ";
		for (int i = 0; i < digits.size(); i++)
			cout << digits[i] << " ";
		cout << endl;
		*/
		map< char, int > table;
		for (int i = 0; i < digits.size(); i++)
			table[digits[i]] = i;
		/*
		cout << "table:  ";
		for (int i = 0; i < digits.size(); i++)
			cout << table[digits[i]] << " ";
		cout << endl;
		*/
		long long ans = 0;
		for (int i = 0; i < message.length(); i++) {
			ans *= (long long)digits.size();
			ans += (long long)table[message[i]];
			//cout << table[message[i]] << " ";
		}
		//cout << endl;
		cout << "Case #" << ++prob << ": ";
		cout << ans;
		//cout << "(" << message << ")";
		cout << endl;
	}
	return 0;
}
