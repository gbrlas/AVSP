#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void readSample(const string& google, const string& english, vector<int>& mapping)
{
	for (int i = 0; i < google.size(); i++)
	{
		if(google[i] != ' ')
		{
			assert(mapping[google[i]-'a'] == -1 || mapping[google[i]-'a'] == english[i]-'a');
			mapping[google[i]-'a']= english[i]-'a';
		}
	}

}

int main()
{
	vector<int> mapping(26,-1);
	mapping['y'-'a'] = 'a'-'a';
	mapping['e'-'a'] = 'o'-'a';
	mapping['q'-'a'] = 'z'-'a';

	readSample(
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"our language is impossible to understand",
		mapping
	);

	readSample(
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"there are twenty six factorial possibilities",
		mapping
	);

	readSample(
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
		"so it is okay if you want to just give up",
		mapping
	);

	mapping[25] = 16;

	char buf[10000];
	int n;
	scanf("%d ", &n);
	for (int tc = 1; tc <= n; tc++)
	{
		gets(buf);
		int s = strlen(buf);

		printf("Case #%d: ", tc);
		for (int i = 0; i < s; i++)
		{
			if (buf[i] == ' ') printf(" ");
			else printf("%c", (char)mapping[buf[i]-'a']+'a');
		}
		printf("\n");
	}
	return 0;
}