#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("out.txt", "w+", stdout);
	freopen("A-small-attempt0.in", "r", stdin);

	int nCases;
	cin >> nCases;
	cin.ignore();

	string destination = "yhesocvxduiglbkrztnwjpfmaq";
	string input;

	for(int i=1; i<=nCases; i++)
	{
		getline(cin, input);
		printf("Case #%d: ", i);
		for(int j = 0; j<input.size(); j++)
			if(input[j] == ' ')
				cout << ' ';
			else
				cout << destination[input[j]-'a'];
		cout << endl;
	}

	return 0;
}
