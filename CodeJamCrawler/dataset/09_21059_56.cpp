#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>


using namespace std;

struct node
{
	double weight;
	string key;
	node* l;
	node* r;
	~node()
	{
		if (l != 0) delete l;
		if (r != 0) delete r;
	} 
};


node* root;

const char* scan(node* n, const char* in)
{
	int i = 0;
	while (in[i] != '(') i++;
	sscanf(in + i + 1, "%lf", &n->weight);
	i++;
	while (in[i] != ')' && !(in[i] >= 'a' && in[i] <= 'z')) i++;
	if (in[i] == ')') 
	{
		n->l = 0; 
		n->r = 0;
		return in + i + 1;
	}
	else 
	{
		int j = i;
		n->key = "";
		while (in[j] >= 'a' && in[j] <= 'z') { n->key += in[j]; j++; }
		n->l = new node();
		n->r = new node();
		in = scan(n->l, in + j);
		in = scan(n->r, in);
		while (*in != ')') in++;
		return in;
	}

}

int main()
{
	int tc, t = 0;
	char tmp[2048];
	for (cin >> tc; t < tc; t++)
	{
		int n;
		cin >> n;
		cin.getline(tmp, 2048);
		string S;
		for (int i = 0; i < n; i++)
		{
			memset(tmp, 0, sizeof(tmp));
			cin.getline(tmp, 2048);
			S += string(tmp);
		}
		node *root = new node();
		scan(root, S.c_str());
		int q;
		cin >> q;
		cout << "Case #" << t + 1 << ": " << endl;
		for (int qi = 0; qi < q; qi++) {
			string name;
			cin >> name;
			int cnt;
			cin >> cnt;
			map<string, int> m;
			for (int i = 0; i < cnt; i++)
			{
				string sss;
				cin >> sss;
				m[sss] = 1;
			}
			double res = 1.0;
			node *curr = root;
			while (curr != 0)
			{
				res *= curr->weight;
				if (curr->key == "") break;
				if (m[curr->key] == 1)
				{
					curr = curr->l;
				}
				else 
				{
					curr = curr->r;
				}
			}
			printf("%.8lf\n", res);
		}
		delete root;
	}
	return 0;
}

