#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int T, C, D, N;

string solve()
{
	int i,j;
	string c, d;
	string s, ans;
	char invok[26][26];
	bool oppos[26][26];

	for (i = 0; i < 26; i++)
		for (j = 0; j < 26; j++)
		{
			invok[i][j] = '$';
			oppos[i][j] = false;
		}

	cin>>C;
	
	for (i = 0; i < C; i++)
	{
		cin>>c;
		invok[c[0] - 'A'][c[1] - 'A'] = c[2];
		invok[c[1] - 'A'][c[0] - 'A'] = c[2];
	}
	
	cin>>D;

	for (i = 0; i < D; i++)
	{
		cin>>d;
		oppos[d[0] - 'A'][d[1] - 'A'] = true;
		oppos[d[1] - 'A'][d[0] - 'A'] = true;
	}

	cin>>N>>s;
	ans = "";

	for (i = 0; i < N; i++)
	{
		if (ans.length() == 0)			//结果集为空的情况,初始状态或者被清空
		{
			ans += s[i];
			continue;
		}

		if (invok[s[i]-'A'][ans[ans.length()-1]-'A']=='$')
			ans += s[i];
		else
		{
			ans[ans.length()-1] = invok[s[i]-'A'][ans[ans.length()-1]-'A'];		
			continue;
		}

		for (j = 0; j < ans.length(); j++)
		{
			if (oppos[s[i]-'A'][ans[j]-'A'])
			{
				ans = "";		
				break;
			}
		}
		
	}
	return ans;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		string ans = solve();
		int len = ans.length();
		cout<<"Case #"<<i<<": [";
		for (int j = 0; j < len; j++)
		{
			cout<<ans[j];
			if (j < len - 1)
				cout<<", ";
		}
		cout<<"]\n";
	}
	return 0;
}