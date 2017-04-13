#include <iostream>
#include <set>
#include <string>
#include <map>
#include <string>
using namespace std;

typedef map<pair<char, char>, char> mmap;
typedef set<pair<char, char> > sset;

int main()
{

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int t;
	cin >> t;

	

	for(int test = 0; test< t; ++test)
	{
		mmap combo;
		sset opposed;
		int c, d, n;
		cin >> c;
		for(int i=0; i<c; ++i)
		{
			char c1, c2, r;
			cin >> c1 >> c2 >> r;
			combo.insert(make_pair(make_pair(c1, c2), r)); 
			combo.insert(make_pair(make_pair(c2, c1), r));
		}
		cin >> d;
		for(int i = 0; i<d; ++i)
		{
			char c1, c2;
			cin >> c1 >> c2;
			opposed.insert(make_pair(c1, c2));
			opposed.insert(make_pair(c2, c1));
		}
		cin >> n;
		string s;
		for(int i=0; i<n; i++)
		{
			char c;
			cin >> c;
			if(s.empty())
			{
				s += c;
				continue;
			}
			
			mmap::iterator f = combo.find(make_pair(c, s[s.length() - 1]));
			if(f != combo.end())
			{
				s[s.size()-1] = f->second;
				continue;
			}
			s += c;
			for(int j=0; j<s.length(); j++)	
			{
				sset::iterator sf = opposed.find(make_pair(c, s[j]));
				if(sf != opposed.end())
				{
					s.clear();
					break;
				}
			}
			
			
		}

		cout << "Case #" << test+1 << ": [";
		if(s.empty())
			cout << "]\n";
		else 
		{
			for(int j=0; j<s.length()-1; j++)
				cout << s[j] << ", ";
			cout << *s.rbegin() << "]\n";
		}
	}

	return 0;
}