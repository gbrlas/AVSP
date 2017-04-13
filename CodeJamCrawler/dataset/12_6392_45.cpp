#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
char r[] = "yhesocvxduiglbkrztnwjpfmaq";
void test(int tn)
{
	string s;
	getline(cin, s);
	for(int i = 0; i <s.size(); i++)
		if(isalpha(s[i]))
			s[i] = r[s[i] - 'a'];
	cout << "Case #" << tn << ": " << s << "\n";
}
int main()
{
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}
