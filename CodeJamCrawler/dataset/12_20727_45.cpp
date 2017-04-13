#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static char buffer[500];

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	char map[50];
	memset(map, 0, sizeof(map));

	vector<string> vg;
	vg.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	vg.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	vg.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

	vector<string> v;
	v.push_back("our language is impossible to understand");
	v.push_back("there are twenty six factorial possibilities");
	v.push_back("so it is okay if you want to just give up");

	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
		{
			if(v[i][j] == ' ')
				continue;
			map[int(vg[i][j]-'a')] = v[i][j];
		}
	}

	map['q'-'a'] = char('z');
	map['y'-'a'] = char('a');

	map['z' -'a'] = 'q';
	int T;
	gets(buffer);
	T = atoi(buffer);

	for(int c = 0; c < T; ++c)
	{
		string res;
		gets(buffer);

		for(int i = 0; i < strlen(buffer); ++i)
		{
			if( buffer[i] == ' ')
				res += " ";
			else
				res += map[buffer[i]-'a'];
		}

		cout << "Case #" << (c+1) << ": "<< res << endl;
	}

	return 0;
}