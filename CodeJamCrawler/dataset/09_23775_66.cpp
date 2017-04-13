#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Pattern
{
private:
	vector<string> pattern;
public:
	Pattern(const string &pttr)
	{
		for (int i=0;i<pttr.length();++i)
		{
			if (pttr[i] == '(')
			{
				int start = ++i;
				for (;pttr[i]!=')';++i);
				pattern.push_back(pttr.substr(start, i-start));
				sort(pattern.rbegin()->begin(), pattern.rbegin()->end());
			}
			else
			{
				pattern.push_back(pttr.substr(i,1));
			}
		}
	}
	
	bool match(const string &str)
	{
		for (int i=0;i<str.length();++i)
			if (!bsearch(pattern[i], str[i])) return false;
		return true;
	}

private:
	bool bsearch(const string &str, char c)
	{
		int l=0,r=str.length(),m;
		while (l<=r)
		{
			m=(l+r)/2;
			if (c == str[m]) return true;
			else if (c < str[m]) r=m-1;
			else l=m+1;
		}
		return false;
	}
};

int main()
{
	vector<string> words;
	int L, D, N;
	cin >> L >> D >> N;
	string word;
	for (int i=0;i<D;++i)
	{
		cin >> word;
		words.push_back(word);
	}
	
	string str_pttr;
	for (int caseno=1;caseno<=N;++caseno)
	{
		cin >> str_pttr;
		Pattern pattern(str_pttr);
		int count = 0;
		for (vector<string>::iterator it=words.begin();it!=words.end();++it)
			if (pattern.match(*it))
				++count;
		cout << "Case #" << caseno << ": " << count << endl;
	}
}
