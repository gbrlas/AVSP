#include <iostream>
#include <string>
using namespace std;

int c, d, n;
char invoke[330][330];
bool opp[330][330]; 
string str;

int main()
{
	int t, id = 0;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &c);
		memset (invoke, 0, sizeof(invoke));
		memset (opp, false, sizeof(opp));
		for (int i = 0; i < c; i++)
		{
			char tmp[5];
			scanf("%s", tmp);
			invoke[tmp[0]][tmp[1]] = invoke[tmp[1]][tmp[0]] = tmp[2];
		}
		scanf("%d", &d);
		for (int i = 0; i < d; i++)
		{
			char tmp[5];
			scanf("%s", tmp);
			opp[tmp[0]][tmp[1]] = opp[tmp[1]][tmp[0]] = true;
		}
		scanf("%d", &n);
		cin >> str;
		string ans;
		for (int i = 0; i < str.length(); i++)
		{
			if (ans.length() > 0 && invoke[str[i]][ans[ans.length() - 1]] != '\0')
			{
				ans[ans.length() - 1] = invoke[str[i]][ans[ans.length() - 1]];
			}
			else
			{
				ans += str[i];
			}
			for (int j = 0; j < ans.length() - 1; j++)
			{
				if (opp[ans[j]][ans[ans.length() - 1]] == true)
				{
					ans.clear();
					break;
				}
			}
		}
		printf("Case #%d: ", ++id);
		string out = "[";
		if (ans.length() > 0)
		{
			out += ans[0];
			for (int i = 1; i < ans.length(); i++)
			{
				out += ", ";
				out += ans[i];
			}
		}
		out += "]";
		printf("%s\n", out.data());
	}
	return 0;
}
