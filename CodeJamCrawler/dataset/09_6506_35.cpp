#include <iostream>
#include <string>

using namespace std;

string digsort (string x)
{
	for (int i = 0; i<x.length(); ++i)
		for (int j = 0; j<x.length()-i-1; ++j)
			if (x[j] > x[j+1])
				swap (x[j], x[j+1]);
	return x;
}

int main()
{
	int k;
// 	cout << "!" << endl;
	cin >> k;
	for (int t = 0; t<k; ++t)
	{
		string s;
		cin >> s;
		s = "0" + s;

		int i = s.length() - 2;
		for (; s[i] >= s[i+1]; --i)
		{
		}
		int j = s.length() - 1;
		for (; s[i] >= s[j]; --j)
		{
		}
//  		cout << s << " " <<  i << " " << s[i] << " " << j << " " << s[j] << endl;
		swap(s[i], s[j]);
//  		cout << s << " " << s.substr(0, i+1) << " " << s.substr(i+1, s.length() - i) << endl;
		s = s.substr(0, i+1) + digsort(s.substr(i+1, s.length() - i));
				
		if (s[0] == '0')
			s = s.substr(1, s.length() - 1);

		cout << "Case #" << t+1 << ": " << s << endl;
	}
}
