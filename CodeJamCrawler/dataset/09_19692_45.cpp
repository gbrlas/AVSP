#include <set>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

struct node
{
	double v;
	string name;
	node *left, *right;
};

node *root;
vector<string> nn;

void Build(string &s, node *t, int L, int R)
{
	while(s[L] == ' ' || s[L] == '\n')
		L++;
	while(s[R - 1] == ' ' || s[R - 1] == '\n')
		R--;
	L++;
	R--;
	t->right = 0;
	t->left = 0;
	istringstream is(s.substr(L, R - L));
	is >> t->v;
	while(L < R && (s[L] == ' ' || s[L] == '\n' || s[L] >= '0' && s[L] <= '9' || s[L] == '.'))
		L++;
	if(L != R)
	{
		istringstream ist(s.substr(L, R - L));
		ist >> t->name;
		L += t->name.size();
		while(s[L] != '(')
			L++;
		int r = 1;
		int p = L + 1;
		while(r != 0)
		{
			if(s[p] == ')')
				r--;
			else if(s[p] == '(')
				r++;
			p++;
		}
		t->left = new node;
		t->right = new node;
		Build(s, t->left, L, p);
		Build(s, t->right, p + 1, R);
	}
}

void Solve()
{
	char tmp[1024];
	root = new node;
	int m;
	cin >> m;
	string ttt = "";
	cin.getline(tmp, 1024);
	for(int i = 0; i < m; i++)
	{
		cin.getline(tmp, 1024);
		ttt += string(tmp);
	}
	Build(ttt, root, 0, ttt.size());
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		nn.clear();
		cin >> ttt;
		int tt;
		cin >> tt;
		for(int j = 0; j < tt; j++)
		{
			cin >> ttt;
			nn.push_back(ttt);
		}
		double p = 1;
		node *t = root;
		while(t)
		{
			p *= t->v;
			bool f = 0;
			for(int j = 0; j < nn.size(); j++)
				if(nn[j] == t->name)
				{
					f = 1;
					break;
				}
			if(f)
				t = t->left;
			else
				t = t->right;
		}
		cout << fixed << setprecision(7) << p << endl;
	}
}

void Clear(node *v)
{
	if(v)
	{
		Clear(v->left);
		Clear(v->right);
		delete v;
	}
}

int main()
{
#ifndef _DEBUG
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int t = 1; t <= n; t++)
	{
		cout << "Case #" << t << ":" << endl;
		Solve();
		Clear(root);
	}
	return 0;
}