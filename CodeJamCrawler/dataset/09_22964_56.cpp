#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

char s[100000];

typedef struct tagtree {
	double p;
	string st;
	struct tagtree *l;
	struct tagtree *r;
} tree, *ptree;

ptree create(char *&s)
{
	while (*s!='(')
		++s;
	ptree ret = new tree;
	ret->l = ret->r = 0;
	++s;
	while (*s<'0' || *s>'9') ++s;
	sscanf(s, "%lf", &ret->p);
	while (*s>='0' && *s<='9' || *s=='.') ++s;
	while (*s<=' ') ++s;
	if (*s==')')
	{
		++s;
		return ret;
	}
	string tmp = "";
	while (*s>' ')
		tmp += *(s++);
	ret->st = tmp;
	ret->l = create(s);
	ret->r = create(s);
	return ret;
}

void print(ptree tree)
{
	cout << '(' << tree->p;
	if (tree->l)
	{
		cout << ' ' << tree->st << ' ';
		print(tree->l);
		cout << ' ';
		print(tree->r);
	}
	cout << ')';
}

set<string> fes;

double getv(ptree tree)
{
	double aa = 1;
	if (tree->l)
		aa = getv((fes.find(tree->st)!=fes.end())?tree->l:tree->r);
	return tree->p * aa;
}

void process()
{
	static int id = 0;
	printf("Case #%d:\n", ++id);
	int l;
	cin >> l;
	cin.getline(s, sizeof(s));
	char *cur = s;
	for (int i = 0; i < l; ++i)
	{
		cin.getline(cur, 10000);
		while (*cur)++cur;
		*cur = ' ';
		++cur;
	}
	cur = s;
	ptree tree = create(cur);
	//print(tree);
	cin >> l;
	for (int i = 0; i < l; ++i)
	{
		string name;
		cin >> name;
		int n;
		cin >> n;
		fes.clear();
		for (int j = 0; j < n; ++j)
		{
			string tmp;
			cin >> tmp;
			fes.insert(tmp);
		}
		printf("%0.7lf\n", getv(tree));
	}
}

int main()
{
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		process();
	}
	return 0;
}
