#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#include <map>

void combine(string& str, vector<string>& cmb)
{
	int n = str.length();
	if(n < 2) return;
	for(int i = 0; i < cmb.size(); i++)
	{
		if(cmb[i][0] == str[n-1] && cmb[i][1] == str[n-2])
			str = str.substr(0, n-2) + cmb[i][2];
		if(cmb[i][0] == str[n-2] && cmb[i][1] == str[n-1])
			str = str.substr(0, n-2) + cmb[i][2];
	}
}

void opposite(string& str, vector<vector<char> >& dell)
{
	int n = str.length();
	for(int i = n-2; i >= 0; i--)
	{
		if(dell[str[i]-'A'][str[n-1]-'A'])
		{
			//str = str.substr(0, i);
			str = "";
			return;
		}
	}
}

int main()
{
	int T; cin >> T;
	for(int No = 1; No <= T; No++)
	{
		int C; cin >> C;
		vector<string> cmb(C);
		for(int i = 0; i < C; i++)
			cin >> cmb[i];

		int D; cin >> D;
		vector<vector<char> > dell(26, vector<char>(26));
		for(int i = 0; i < D; i++)
		{
			string tmp; cin >> tmp;
			dell[tmp[0]-'A'][tmp[1]-'A'] = 1;
			dell[tmp[1]-'A'][tmp[0]-'A'] = 1;
		}

		int N; cin >> N;
		string str; cin >> str;
		string ans;

		map<char,int> latest;
		for(int i = 0; i < str.length(); i++)
		{
			char c = str[i];
			ans += c;
			combine(ans, cmb);
			opposite(ans, dell);
		}
		cout << "Case #" << No << ": [";
		for(int i = 0; i < ans.length(); i++)
			cout << (i == 0 ? "" : ", ") << ans[i];
		cout << "]" << endl;
	}
	return 0;
}
