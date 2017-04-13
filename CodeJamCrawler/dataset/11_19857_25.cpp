#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	freopen("input.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T, C, D, N;
	string s, in;
	pair<char, char> key;
	map< pair<char,char>, char> comb;
	map< pair<char,char>, bool> oppose;

	cin >> T;

	for(int t=1; t<=T; t++)
	{
		comb.clear();
		oppose.clear();

		cin >> C;
		for(int c=0; c<C; c++)
		{
			cin >> s;
			key.first = s[0];
			key.second = s[1];
			comb[key] = s[2];	
		}

		cin >> D;
		for(int d=0; d<D; d++)
		{
			cin >> s;
			key.first = s[0];
			key.second = s[1];
			oppose[key] = true;
		}

		cin >> N;
		cin >> in;

		string list = "";
		for(int i=0; i<N; i++)
		{
			list += in[i];

			if(list.length() >= 2) // combine
			{
				char c1 = list[list.length()-1];
				char c2 = list[list.length()-2];
				
				if( comb.count( make_pair(c1, c2) ) > 0)
				{
					list.erase(list.length()-2);
					list += comb[ make_pair(c1, c2) ];
					continue;
				}
				if( comb.count( make_pair(c2, c1) ) > 0)
				{
					list.erase(list.length()-2);
					list += comb[ make_pair(c2, c1) ];
					continue;
				}

				for(int c1i=0; c1i<list.length()-1; c1i++)
				{
					c2 = list[c1i];
					if( oppose.count( make_pair(c1, c2) ) > 0)
					{
						list = "";
						break;
					}
					if( oppose.count( make_pair(c2, c1) ) > 0)
					{
						list = "";
						break;
					}
				}
				// oppose
				
			}
		}

		// print output
		cout << "Case #" << t << ": [";
		for(int i=0; i<list.length(); i++)
		{
			cout << list[i];
			if(i != list.length()-1)
				cout << ", ";
		}
		cout << "]" << endl;
	}

	return 0;
}