#include <iostream>

using namespace std;

int main(int, char**)
{
	char str[] = "yhesocvxduiglbkrztnwjpfmaq", str2[101];
	int n;
	cin >> n;
	cin.get();
	for(int i = 0; i < n; ++i)
	{
		cin.getline(str2, 101);
		cout << "Case #" << i + 1 << ": ";
		for(int j = 0; str2[j]; ++j)
		{
			if(str2[j] >= 'A' && str2[j] <= 'Z')
				cout << (char) (str[str2[j] - 'A'] + 'A' - 'a');
			else if(str2[j] >= 'a' && str2[j] <= 'z')
				cout << str[str2[j] - 'a'];
			else
				cout << str2[j];
		}
		cout << '\n';
	}
	return 0;
}