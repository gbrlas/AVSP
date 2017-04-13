# include <cstdio>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;

struct node
{
	string name;
	vector <node> child;

	node(string s)
	{
		name = s;
		child.clear();
	}

	int isin(string s)
	{
		int i;

		for(i = 0; i < child.size(); i++)
			if(child[i].name == s)
				return i;

		return -1;
	}
};

vector <string> tokenize(char* s)
{
	int i, j;
	char x[200];
	vector <string> v;

	v.clear();

	for(i = 1; s[i]; i++)
	{
		j = 0;
		while(s[i] != '/' && s[i] != '\0')
			x[j++] = s[i++];
		x[j] = '\0';
		v.push_back(string(x));
	}


	return v;
}

int main()
{
	freopen("a-s.in", "r", stdin);
	freopen("a-s.out", "w", stdout);
	int t, tcase, m, n, i, j, cnt;
	char tmp[300];

	scanf("%d", &t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%d %d", &n, &m);
		node root("");

		for(i = 0; i < n; i++)
		{
			memset(tmp, 0, sizeof(tmp));
			scanf("%s", tmp);
			vector <string> tok = tokenize(tmp);
			node* p = &root;

			for(j = 0; j < tok.size(); j++)
			{
				int a = p->isin(tok[j]);
				if(a != -1)
					p = &(p->child[a]);
				else
				{
					p->child.push_back(node(tok[j]));
					p = &(p->child[p->child.size()-1]);
				}
			}

			//for(j = 0; j < tok.size(); j++)
				//printf(" %s\n", tok[j].c_str());
		}


		cnt = 0;

		for(i = 0; i < m; i++)
		{
			memset(tmp, 0, sizeof(tmp));
			scanf("%s", tmp);
			vector <string> tok = tokenize(tmp);
			node* p = &root;

			for(j = 0; j < tok.size(); j++)
			{
				int a = p->isin(tok[j]);
				if(a != -1)
					p = &(p->child[a]);
				else
				{
					p->child.push_back(node(tok[j]));
					cnt++;
					p = &(p->child[p->child.size()-1]);
				}
			}
		}

		printf("Case #%d: %d\n", tcase, cnt);
	}

	return 0;
}