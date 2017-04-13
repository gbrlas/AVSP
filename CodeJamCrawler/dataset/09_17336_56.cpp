#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <cassert>

using namespace std;
#define PROBLEM "A"
#define SCALE "small"
#define IN_FILE PROBLEM"-"SCALE".in"
#define OUT_FILE PROBLEM"-"SCALE".out"

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef struct node {
	double p;
	string f;
	struct node *p1, *p2;
} Node;

Node *root;

enum Token {OPEN, CLOSE, NUMBER, STRING, NONE};
double number;
string str;
Token next_token(istream &is)
{
	char c = is.get();
	while(c==' ' || c=='\r'|| c=='\n') c=is.get();
	if(c=='(') return OPEN;
	else if(c==')') return CLOSE;
	else if(c>='0' && c<='9') {
		is.unget();
		is>>number;
		return NUMBER;
	} else if(isalpha(c)) {
		is.unget();
		is>>str;
		return STRING;
	}
	return NONE;
}

Node * read(istream &is)
{
	Node *p = new Node;
	p->p1=p->p2=0;

	Token t;
	assert(next_token(is)==OPEN);
	assert(next_token(is)==NUMBER);
	p->p = number;
	t = next_token(is);
	if(t==STRING) {
		p->f=str;
		p->p1 = read(is);
		p->p2 = read(is);
		assert(next_token(is)==CLOSE);
	} else {
		assert(t==CLOSE);
	}
	return p;
}

double calc(const vector<string> &v, Node *node, double p)
{
	p*=node->p;
	if(node->p1 && node->p2) {
		if(find(v.begin(), v.end(), node->f)!=v.end()) node=node->p1;
		else node=node->p2;
		p = calc(v, node, p);
	}
	return p;
}

int main()
{
	freopen(IN_FILE, "r", stdin);
	freopen(OUT_FILE, "w", stdout);

	int i,j,k,l,m,n;
	cin>>n;
	rep(i,n)
	{
		string tree,line;
		cin>>m; getline(cin,line);
		rep(j,m) {
			getline(cin,line);
			tree+=" ";
			tree+=line;
		}
		istringstream is(tree);
		root=read(is);

		printf("Case #%d:\n", i+1);

		string feature;
		cin>>l; getline(cin,line);
		rep(j,l) {
			getline(cin,line);
			istringstream is(line);
			is>>feature>>m;

			vector<string> vf;
			rep(k,m) {
				is>>feature;
				vf.push_back(feature);
			}
			printf("%.8f\n", calc(vf, root, 1.0));
		}
	}
	return 0;
}
