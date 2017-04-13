#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t<T; ++t)
	{
		string s;
		cin >> s;

// 		cout << s << endl;
		string tmpl = "0123456789";
		//if ((s[0]>='a')&&(s[0]<='z'))
		tmpl = "1023456789";
			
		char r['z'+1];
		for (char p = '0'; p<='z'; ++p)
			r[p] = '#';
			
		int cur = 0;
		for (int i = 0; i<s.length(); ++i)
		{
			if (r[s[i]] == '#')
			{
				r[s[i]] = tmpl[cur];
				++cur;
			}
		}

		for (int i = 0; i<s.length(); ++i)
		{
			s[i] = r[s[i]];
		}
// 		cout << s << endl;
		
		char max = '0';
		for (int i = 0; i<s.length(); ++i)
			if (s[i] > max)
				max = s[i];
		int di = int(max-'0');
		long long d = di+1;
		long long ans=0, tmp = 0;
		for (int i = 0; i<s.length(); ++i)
		{
			tmp = int(s[i] -'0');			
			ans = ans*d+tmp;
		}
		
		cout << "Case #" << t+1 << ": " << ans <<  endl;
	}
}
