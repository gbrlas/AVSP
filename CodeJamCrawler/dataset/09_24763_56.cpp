#include <iostream>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <iomanip>

using namespace std;

struct Tree {
    Tree() {
	parent = NULL;
	feature = "";
	subtree1 = NULL;
	subtree2 = NULL;
    }
    Tree *parent;
    double weight;
    string feature;
    Tree *subtree1, *subtree2;
};

inline static int string_to_int(const string &str) {
    stringstream ss(str);
    int n;
    ss >> n;
    return n;
}
                

Tree *build_tree(string s) {
    bool recs = true;
    size_t start = 0;
    string feldolg = "";
    if(s.find('(') == string::npos) {
	size_t i = 0;
	for(; i < s.length(); i++)
	    if(s[i] != ' ')
		break;
	feldolg = s.substr(i);
	recs = false;
    } else {
	start = s.find('(');
	feldolg = s.substr(0, start);
    }

    Tree *ret = new Tree();

    size_t szp = feldolg.find(' ');
    if(szp == string::npos) {
//	sscanf(feldolg.c_str(), "%e", &(ret->weight));
	ret->weight = boost::lexical_cast<double>(feldolg);

    } else {
	ret->weight = boost::lexical_cast<double>(feldolg.substr(0, szp));
	//sscanf(feldolg.substr(0, szp).c_str(), "%f", &(ret->weight));
	ret->feature = feldolg.substr(szp+1);
    }

    bool first = true;
    if(recs)
	while(start < s.length()) {
	    size_t nyit = s.find('(', start);
	
	    int depth = 0;
	    for(size_t pos = nyit + 1; pos < s.length(); pos++) {
//		cout << "depth: " << depth << ", pos: " << pos << ", char: " << s[pos] << endl;
		if(s[pos] == '(')
		    depth++;
		else if(s[pos] == ')') {
		    if(depth > 0)
			depth--;
		    else {
			if(first) {
			    ret->subtree1 = build_tree(s.substr(nyit + 1, pos - nyit - 1));
			    ret->subtree1->parent = ret;
			    first = false;
			} else {
			    ret->subtree2 = build_tree(s.substr(nyit + 1, pos - nyit - 1));
			    ret->subtree2->parent = ret;
			}
			start = pos+1;
			break;
		    }
		}
	    }
	}
    return ret;
}

void print_tree(Tree *t, int depth) {
    if(t == NULL)
	return;

    for(int i = 0; i < depth; i++)
	cout << "\t\t";
    cout << "weight: " << t->weight << endl;
    if(t->feature.length() > 0) {
	for(int i = 0; i < depth; i++)
	    cout << "\t\t";
	cout << "feature: " << t->feature << endl;
    }
    print_tree(t->subtree1, depth+1);
    print_tree(t->subtree2, depth+1);
}

int main() {
    unsigned int testcases;
    cin >> testcases;

    for(unsigned int tc = 1; tc <= testcases; tc++) {
	cout << "Case #" << tc << ":" << endl;
	unsigned int nlines;
	cin >> nlines;
	string line;
	getline(cin, line);
	
	string tree = "";
	for(unsigned int l = 0; l < nlines; l++) {
	    getline(cin, line);
	    size_t pos = line.find('(');
	    if(pos != string::npos)
		tree += line.substr(pos);
	    else {
		pos = line.find(')');
		if(pos != string::npos)
		    tree += line.substr(pos);
		else
		    tree += line;
	    }
	}
	Tree *t = build_tree(tree.substr(1, tree.length() - 2));
//	print_tree(t, 0);
	
	unsigned int nanimals;
	cin >> nanimals;
	getline(cin, line);
	for(unsigned int l = 0; l < nanimals; l++) {
	    
	    getline(cin, line);
	    vector<string> fvec;
	    boost::split(fvec, line, boost::is_any_of(" "));
	    
	    double p = 1.0;
	    Tree *node = t;
	    while(true) {
		p = p*node->weight;
		if(node->subtree1 == NULL)
		    break;

		bool onfirst = false;
		for(int i = 0; i < string_to_int(fvec.at(1)); i++)
		    if(node->feature.compare(fvec.at(2+i)) == 0) {
			onfirst = true;
			break;
		    }
		
		if(onfirst)
		    node = node->subtree1;
		else {
		    node = node->subtree2;
		}
		    
	    }
	    cout.precision(7);
	    cout << fixed << p << endl;
//	    printf("%f\n", p);
	}
    }
    return EXIT_SUCCESS;
}
