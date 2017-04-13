#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int c[t], d[t], n[t];
	string *cs[t], *ds[t], inp[t];
	for (int i = 0; i < t; i++)
	{
		cin >> c[i];
		cs[i] = new string[c[i]];
		for (int j = 0; j < c[i]; j++)
			cin >> cs[i][j];
		cin >> d[i];
		ds[i] = new string[d[i]];
		for (int j = 0; j < d[i]; j++)
			cin >> ds[i][j];
		cin >> n[i];
		cin >> inp[i];
	}

	for (int i = 0; i < t; i++)
	{
		string out = "";
		char c1, c2, c3;
		char cc[26][26];
		for(int j = 0; j < 26; j++)
			for(int k = 0; k < 26; k++)
				cc[j][k] = 0;;
		for (int j = 0; j < c[i]; j++)
		{
			c1 = cs[i][j][0];
			c2 = cs[i][j][1];
			c3 = cs[i][j][2];
			cc[c1-'A'][c2-'A'] = cc[c2-'A'][c1-'A'] = c3;
		}
		char dd[26][26];
		for(int j = 0; j < 26; j++)
			for(int k = 0; k < 26; k++)
				dd[j][k] = 0;;
		for (int j = 0; j < d[i]; j++)
		{
			c1 = ds[i][j][0];
			c2 = ds[i][j][1];
			dd[c1-'A'][c2-'A'] = dd[c2-'A'][c1-'A'] = 1;
		}
		
		if (n[i] > 0)
		{
			string prev = "", curr = "";
			
			for (int j = 0; j < n[i]; j++)
			{
				curr += inp[i][j];
				if (prev == "")
					out.append(curr);
				else if (cc[prev[0]-'A'][curr[0]-'A'] != 0)
				{
					out.resize(out.length()-1);
					out.resize(out.length()+1, cc[prev[0]-'A'][curr[0]-'A']);
				}
				else
				{
					bool destroy = false;
					for (int k = 0; k < out.length(); k++)
					{
						if (dd[out[k]-'A'][curr[0]-'A'] == 1)
						{
							// out = out.substr(0, k);
							out = "";
							destroy = true;
							break;
						}
					}
					if (!destroy)
						out.append(inp[i].substr(j,1));
				}
				if (out.length() != 0)
					prev = out.substr(out.length()-1, 1);
				else
					prev = "";
				curr="";
			}
		}
		cout << "Case #" << i+1 << ": [";
		if (out.length() == 0)
			cout << "]" << endl;
		else
		{
			for(int j = 0; j < out.length()-1; j++)
				cout << out[j] << ", ";
			cout << out[out.length()-1] << "]"<<endl;
		}
	}
	
	
}

