#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>

typedef long long ll;

using namespace std;

int N; // cases

int L; // lines
int A; // animals

vector<string> features;

typedef struct node {
	double w;
	string feat;
	struct node *left, *right; 
} node, *nodep;

node *build_tree(istringstream &iss)
{
	//string subs(s.begin() + idx, s.end());
	iss >> ws;
	char chr1;

	iss >> chr1;
	assert(chr1 == '(');
	
	node *n = new node;
	n->left = NULL;
	n->right = NULL;

	iss >> n->w;
	iss >> ws;
	
	int ch = iss.peek();
	if (ch == ')')
	{
		iss.get();
		return n;
	}
	else
	{
		iss >> n->feat;
		n->left = build_tree(iss);
		n->right = build_tree(iss);
		iss >> ws;
		int ch2 = iss.get();
		assert(ch2 == ')');
	}

	return n;
}

int main()
{

	cin >> N;

	for(int n=0; n<N; n++)
	{
		string tree_str;

		cin >> L;
		for(int l=0; l<L; l++)
		{
			string line;
			getline(cin >> ws, line);
			tree_str.append(line);
			tree_str.append("\r\n");
		}
		istringstream iss(tree_str);

		int idx = 0;

		node *root = build_tree(iss);

		cout << "Case #" << n+1 << ":" << endl;

		cin >> A;
		for(int a=0; a<A; a++)
		{
			features.clear();

			string animal;
			cin >> ws >> animal;
			
			int NF;
			cin >> NF;

			
			for (int nf=0; nf<NF; nf++)
			{
				string feat;
				cin >> ws >> feat;
				features.push_back(feat);
			}

			double prob = 1;
			node * ptr = root;
			while(1)
			{
				prob *= ptr->w;
				if (ptr->feat.empty())
					break;
				bool found = find(features.begin(), features.end(), ptr->feat) != features.end();
				if (found)
				{
					ptr = ptr -> left;
				}
				else
					ptr = ptr -> right;
			}

			cout<<setiosflags( ios::fixed );
			cout.precision(7);
			cout << prob << endl;
		}

	}

	return 0;
}
