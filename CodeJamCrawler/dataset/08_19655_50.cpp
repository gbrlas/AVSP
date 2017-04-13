#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	string str;
	int n;
	getline(cin, str);
	stringstream(str) >> n;
//cout << "n: " << n << endl;
	for (int i=0; i<n; ++i)
	{
		int s;
		getline(cin, str);
		stringstream(str) >> s;
//cout << "s: " << s << endl;
//vector<string> engines(s);
		map<string, int> m;
		for (int j=0; j<s; ++j)
		{
			getline(cin, str);
//engines[j] = str;
//cout << "engine: " << str << endl;
			m[str] = j;
		}

		int q;
		getline(cin, str);
		stringstream(str) >> q;
		vector<int> qs(q);
		for (int j=0; j<q; ++j)
		{
			getline(cin, str);
//cout << "query: " << str << endl;
			qs[j] = m[str];
		}
		
		int num = 0;
		for (int j=0; j<q;)
		{
			vector<bool> poss(s, true);
			int numposs = s;
			while (j<q)
			{
				if (poss[qs[j]]) numposs--;
				if (numposs == 0) break;
				poss[qs[j]] = false;
				j++;
			}
			if (j<q) num++;
//			for (int k=0; k<s; ++k)
//			{
//				if (poss[k])
//				{
//					cout << "switch to: " << engines[k] << endl;
//					break;
//				}
//			}
		}
		cout << "Case #" << i+1 << ": " << num << endl;
	}
}
