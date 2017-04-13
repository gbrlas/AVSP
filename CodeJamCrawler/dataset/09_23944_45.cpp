#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct node
{
	double weight;
	string feature;
	vector<node> children;
};


node gen_tree(istream& in) {
	node root;

	char ch;

	in >> ch; // (
	in >> root.weight;

	in >> ch;
	if (ch != ')') {
		in.putback(ch);
		in >> root.feature;
		root.children.push_back(gen_tree(in));
		root.children.push_back(gen_tree(in));
		in >> ch;
	}

	return root;
}

double find_prob(set<string>& features, node& tree, double p) {
	p *= tree.weight;
	if (tree.feature != "") {
		if (features.find(tree.feature) != features.end())
			return find_prob(features, tree.children[0], p);
		else
			return find_prob(features, tree.children[1], p);
	}
	else
		return p;
}

int main()
{
	ifstream in("A.in");
	ofstream out("A.out");

	int tests;
	in >> tests;
	for (int i=1; i<=tests; i++)
	{
		string tree, temp;
		int tree_lines;
		in >> tree_lines;
		getline(in, tree);

		tree = "";
		while (tree_lines--)
		{
			getline(in, temp);
			tree += temp;
		}

		stringstream sin(tree);
		node bin_tree = gen_tree(sin);

		out << "Case #" << i << ":" << endl;
		int animals;
		in >> animals;
		while (animals--) {
			int features;
			in >> temp >> features;
			
			set<string> feats;
			while (features--) {
				in >> temp;
				feats.insert(temp);
			}

			out << fixed << find_prob(feats, bin_tree, 1.0) << endl;
		}
	}

	return 0;
}
