#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

string line;

struct tree{
	double weight;
	string feature;
	struct tree *yes;
	struct tree *no;
};

bool isPar(const char &c){ return (c == ')' ||c == '(');}

tree* readTree(int &L){
	tree *tr = new tree;
	double w = -2.0;
	stringstream str;

	bool useful = false;
	do{
		getline(cin, line); --L;
		replace_if(line.begin(), line.end(), isPar, ' ');
		for(string::iterator itr = line.begin(); itr != line.end(); ++itr){
			if(!isspace(*itr)){
				useful = true;
				break;
			}
		}
	}while(!useful);

	str << line;
	str >> w;

	tr->weight = w;
	string feat;
	str >> feat;
	if(feat.empty()){
		tr->feature = feat;
		tr->yes = NULL;
		tr->no = NULL;
		return tr;
	}
	else{
		tr->feature = feat;
		tr->yes = readTree(L);
		tr->no = readTree(L);
		return tr;
	}
}

void parseProp(tree *tr, const set<string> &feat, double &prop){
	prop *= tr->weight;
	if(tr->feature.empty())
		return;

	if(feat.find(tr->feature) == feat.end())
		parseProp(tr->no, feat, prop);
	else
		parseProp(tr->yes, feat, prop);
}

int main(int argc, char* argv[]){
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);

	int N=0;
	scanf("%d\n", &N);

	for(int c = 0; c < N; ++c){
		int L = 0;
		scanf("%d\n", &L);
		
		tree *decTree = readTree(L);
		for(int l = 0; l < L; ++l){
			char buff[1000];
			gets(buff);
		}
		
		printf("Case #%d:\n", c+1);
		int A = 0;
		scanf("%d\n", &A);

		double prop = 1.0;
		for(int a = 0; a < A; ++a){
			set<string> features;
			getline(cin, line);
			stringstream str(line);
			string buff;
			int n = 0;
			str >> buff;
			str >> n;

			for(int i = 0; i < n; ++i){
				str >> buff;
				features.insert(buff);
			}
			
			double prop = 1.0;
			parseProp(decTree, features, prop);
			
			printf("%.7f\n", prop);

		}

	}

	return 0;
}