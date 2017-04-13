#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cassert>
#include<iomanip>
#include<map>
#include<cstdlib>
using namespace std;

struct node {
	string *attribute;
	double weight;
	vector<node> subnodes;
};

int processAnimal(node &parent, map<string, int> &features, double weight)
{
	if(parent.weight >= 0)
	{
		weight *= parent.weight;
		if(parent.attribute == NULL)
		{
			cout << fixed << setprecision(7) << weight << endl;
			return 0;
		}
	}
	// check if animal has this feature
	int hasFeature = 0;
	if(parent.weight < 0 || (parent.attribute != NULL && features[*parent.attribute] == 1))
	{
		hasFeature = 1;
	}
	int rval = 1;
	if(hasFeature)
	{
		assert(parent.subnodes.size() >= 1);
		rval = processAnimal(parent.subnodes[0], features, weight);
	}
	else
	{
		assert(parent.subnodes.size() >= 2);
		rval = processAnimal(parent.subnodes[1], features, weight);
	}
	return rval;
}

void printTree(node &parent, int depth)
{
	for(int c=0; c < depth*2; c++)
	{
		cerr << " ";
	}
	if(parent.attribute != NULL)
	{
		cerr << *parent.attribute << " ";
	}
	cerr << parent.weight << endl;
	for(int i = 0; i < parent.subnodes.size(); i++)
	{
		printTree(parent.subnodes[i], depth + 1);
	}
}
void parseSubtree(node &parent, stringstream &input)
{
	//cerr << "entering parseSubtree " << endl;
	stringstream ps;
	node me;
	me.attribute = NULL;
	char c;
	while (input.get(c))
	{
		if(c == '(')
		{
			parseSubtree(me, input);
		}
		else if(c == ')')
		{
			ps >> me.weight;
			ps >> ws;
			string *possat = new string;
			if(ps >> *possat)
			{
				me.attribute = possat;
			}
			parent.subnodes.push_back(me);
			return;
		}
		else
		{
			ps << c;
		}
	}
}

int main()
{
	int numCases;
	cin >> numCases >> ws;
	for(int n = 0; n < numCases; n++)
	{
		int numLines;
		cin >> numLines >> ws;
		stringstream treestr;
		for(int l = 0; l < numLines; l++)
		{
			string s;
			getline(cin, s);
			treestr << s << endl;
		}
		node pseudoroot;
		pseudoroot.attribute = NULL;
		pseudoroot.weight = -1;
		char c;
		treestr >> c;
		assert(c == '(');
		parseSubtree(pseudoroot, treestr);
		// print tree
		printTree(pseudoroot, 0);
		int numAnimals;
		cin >> numAnimals;
		cout << "Case #" << (n + 1) << ":" << endl;
		for(int a = 0; a < numAnimals; a++)
		{
			string animalName;
			int numFeatures;
			map<string, int> features;
			cin >> animalName >> numFeatures;
			for(int f = 0; f < numFeatures; f++)
			{
				string fn;
				cin >> fn;
				features[fn] = 1;
			}
			cerr << "got animal " << animalName << " " << numFeatures << " features" << endl;
			// process animal
			processAnimal(pseudoroot, features, 1);
		}
	}
}
