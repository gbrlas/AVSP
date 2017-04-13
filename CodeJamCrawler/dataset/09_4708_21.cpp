#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

using namespace std;


struct tree
{
	double weight;
	string feature;
	tree * first;
	tree * second;
};

tree * root;
int T, N, L, A;
string s, t;
//tree ::= (weight [feature tree tree])
//weight is a real number between 0 and 1, inclusive
//feature is a string of 1 or more lower case English letters

void getTree(tree * node)
{
	char c;
	double w;

	cin >> c >> w;

	node ->weight = w;
	node ->first = NULL;
	node ->second = NULL;
	node ->feature = "";

	cin >> c;

	if(c != ')') // new tree
	{
		cin.putback(c);
		cin >> node ->feature;
		node ->first = new tree;
		node ->second = new tree;

		getTree( node ->first);
		getTree( node ->second);
		cin >> c;
	}	
}
string animal;
set <string> features;

double prob(tree * node)
{
	double p = node ->weight;

	if( node ->first != NULL)
	{
		if(features.count(node->feature))
			p *= prob(node ->first);
		else
			p *= prob(node ->second);
	}

	return p;
}
int main()
{
	//ifstream cin("A1.in");
	ofstream cout("res.txt");
	cout.setf( ios::fixed);
	cout.precision(7);
	cin >> T;
	string tmp;
	int casenum = 1;

	while(T--)
	{
		cin >> L;
		t = "";
		

		root = new tree;
		getTree(root);

		cin >> A;

		cout << "Case #" << casenum++ <<":" << endl;
		while(A--)
		{
			
features.clear();
			cin >> animal >> N;

			for(int x = 0; x < N; x++)
			{
				cin >> s;
				features.insert(s);
			}

			cout << prob(root) << endl;

		}

	}

	cout.close();
	
	return 0;
}