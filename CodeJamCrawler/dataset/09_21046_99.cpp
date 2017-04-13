#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct TreeItem
{
	string letter;
	map<char, TreeItem*> items;
};

TreeItem root;

void init_tree()
{
	root.letter = "";
}

void add_string(string s)
{
	TreeItem *current = &root;
	for (int i = 0; i < s.size(); i++)
	{
		if (current->items.find(s[i]) == current->items.end())
		{
			TreeItem *item = new TreeItem();
			item->letter = s[i];
			current->items[s[i]] = item;
			current = item;
		}
		else 
		{
			current = current->items[s[i]];
		}
	}
}

bool path_exists(string s)
{
	TreeItem *current = &root;
	for (int i = 0; i < s.size(); i++)
	{
		if (current->items.find(s[i]) == current->items.end())
		{
			return false;
		}
		else 
		{
			current = current->items[s[i]];
		}
	}
	return true;
}

int l, d, n;

pair<string, string> next_token(string s)
{
	pair<string, string> res;
	if (s[0] == '(')
	{
		res.first = s.substr(1, s.find(')') - 1);
		res.second = s.substr(s.find(')') + 1);
	}
	else {
		res.first = s.substr(0, 1);
		res.second = s.substr(1);
	}
	return res;
}

int calc(string s, TreeItem* node)
{
	if (s == "") return 1;
	pair<string, string> ns = next_token(s);
	int res = 0;
	for (int i = 0; i < ns.first.size(); i++)
	{
		if (node->items.find(ns.first[i]) == node->items.end())
		{
			continue;
		}
		else 
		{
			res += calc(ns.second, node->items[ns.first[i]]);
		}
	}
	return res;
}

int calc(string s)
{
	return calc(s, &root);
}

int main()
{
	cin >> l >> d >> n;
	init_tree();
	for (int i = 0; i < d; i++)
	{
		string s;
		cin >> s;
		add_string(s);
	}
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cout << "Case #" << i + 1 << ": " << calc(s) << endl;
	}
	return 0;
}