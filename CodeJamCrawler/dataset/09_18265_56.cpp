#include "..\..\my_header.h"

class Tree
{
public:
	double weight;
	string feature;
	Tree *has;
	Tree *has_not;

	Tree()
	{
		weight = 0;
		has = has_not = NULL;
	}
};

class Animal
{
public:
	string name;
	str_v features;

	bool has(string &feature)
	{
		for (int i=0 ; i < features.size() ; i++)
			if (features[i] == feature)
				return true;

		return false;
	}
};


class solver
{
public:
	double solve(Tree *root, Animal &animal)
	{
		double p = 1;

		for ( ; ; )
		{
			p = p * root->weight;

			if (root->feature == "")
				return p;

			if (animal.has(root->feature))
				root = root->has;
			else
				root = root->has_not;
		}
	}
};

/*************************************************************************************/

Tree *read_tree(string &str, int &cursor)
{
	Tree *root = new Tree;

	while (str[cursor++] != '(')
		;

	while (isspace(str[cursor]))
		cursor++;

	int ws = cursor;

	while (isdigit(str[cursor]) || str[cursor] == '.')
		cursor++;

	root->weight = to_double(str.substr(ws, cursor-ws));

	while (isspace(str[cursor]))
		cursor++;

	if (str[cursor] == ')')
	{
		cursor++;
		return root;
	}

	int fs = cursor;

	while (!isspace(str[cursor]))
		cursor++;

	root->feature = str.substr(fs, cursor-fs);

	root->has = read_tree(str, cursor);
	assert(str[cursor-1] == ')');
	root->has_not = read_tree(str, cursor);
	assert(str[cursor-1] == ')');

	while (str[cursor++] != ')')
		;

	return root;
}

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int L;
	read1(L);

	string tree_str;
	for (int i=0 ; i < L ; i++)
		tree_str += get_line(ifs) + " ";

	int cursor = 0;
	Tree *root = read_tree(tree_str, cursor);

	int A;
	read1(A);

	vector<Animal> animals(A);
	for (int ia=0 ; ia < A ; ia++)
	{
		str_v tokens = split(get_line(ifs), ' ');
		animals[ia].name = tokens[0];
		for (int it=2 ; it < tokens.size() ; it++)
			animals[ia].features.push_back(tokens[it]);

		assert(to_int(tokens[1]) + 2 == tokens.size());
	}

	//int res = solver().solve(root, animals);

	ofs << "Case #" << case_num << ":" << endl;
	for (int i=0 ; i < animals.size() ; i++)
		ofs << solver().solve(root, animals[i]) << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

	int n = to_int(get_line(ifs));

	//assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
