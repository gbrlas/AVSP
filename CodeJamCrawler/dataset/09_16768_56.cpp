/* Piotr Zielinski, Uniwersytet Jagiellonski */

#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it,V) for( __typeof(V.begin()) it = V.begin(); it != V.end(); ++it)
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(),x.end()

typedef long long ll;

struct node {
	string feature;
	double p;
	node *left, *right;
	node(): left(NULL), right(NULL) {}
};

string wyrazenie;

char buf[500];

node *root;

inline bool is_digit(char x) {
	return x >= '0' && x <= '9';
}

inline string dawaj_next(int &skad) {
	int latacz = skad;
	string res;
	while(wyrazenie[latacz] == ' ') ++latacz;
	while(wyrazenie[latacz] != ' ') res = res + (char)wyrazenie[latacz++];
	skad = latacz;
	return res;
}

node* parsuj(int beg) {
	node *nowy = new node();
	string nastepny = dawaj_next(beg);
	//printf("Nastepny1: %s\n", nastepny.c_str());
	nastepny = dawaj_next(beg);
	//printf("Nastepny2: %s\n", nastepny.c_str());
	istringstream is(nastepny);
	double p;
	is >> p;
	nowy->p = p;
	nastepny = dawaj_next(beg);
	//printf("Tuz po liczbie: %s\n", nastepny.c_str());
	if(nastepny[0] != ')') {
		nowy->feature = nastepny;
		//printf("Nowy ficzer: %s\n", nastepny.c_str());
		// odpalic dla reszty
		nastepny = dawaj_next(beg);
		//printf("Nawias: %s\n", nastepny.c_str());
		int latacz = beg+1;
		int otwartych = 1;
		while(otwartych > 0) {
			if(wyrazenie[latacz] == '(') ++otwartych;
			else if(wyrazenie[latacz] == ')') --otwartych;
			++latacz;
		}
		nowy->left = parsuj(beg-1);
		nowy->right = parsuj(latacz);
	}
	return nowy;
}

void clean(node *x) {
	if(x == NULL) return;
	clean(x->left);
	clean(x->right);
	delete x;
}

double szukaj(node *root, set<string> &cechy) {
	//printf("MNOZNIK: %lf\n", root->p);
	if(root->feature == "") return root->p;
	if(cechy.count(root->feature)) return root->p * szukaj(root->left, cechy);
	return root->p * szukaj(root->right, cechy);
}

void testcase() {
	int lines;
	scanf("%d", &lines);
	getchar();
	//printf("LINES: %d\n", lines);
	wyrazenie = "";
	while(lines--) {
		gets(buf);
		string dwa = buf;
		//printf("Wczytalem: %s\n", dwa.c_str());
		wyrazenie = wyrazenie + " " + dwa;
	}
	//printf("Po wczytaniu\n");
	for(int i = 0; i < wyrazenie.size(); ++i) 
		if(wyrazenie[i] == '(' || wyrazenie[i] == ')') {
			wyrazenie = wyrazenie.substr(0,i) + " " + wyrazenie.substr(i,1) + " " + wyrazenie.substr(i+1);
			++i;
			}
	//printf("WYRAZENIE: %s\n", wyrazenie.c_str());
	root = parsuj(0);
	//printf("KONIEC\n");
	int a;
	scanf("%d", &a);
	REP(i,a) {
		scanf("%s", buf);
		int n;
		scanf("%d", &n);
		set<string> cechy;
		REP(j,n) {
			scanf("%s", buf);
			string c = buf;
			cechy.insert(c);
		}
		printf("%lf\n", szukaj(root,cechy));
	}
	clean(root);
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	for(int i = 1; i <= t; ++i) {
		printf("Case #%d:\n", i);
		testcase();
	}
	return 0;
}