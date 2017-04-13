// SavingTheUniverse.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

struct node {
	char c;
	node(char ch):c(ch),LT(0),EQ(0),GT(0),n(-1) {}
	~node() {
		if (LT) delete LT;
		if (GT) delete GT;
		if (EQ) delete EQ;
	}
	node *LT,*EQ,*GT;
	int n;
};

#define NB (((100+sizeof(int)-1)/sizeof(int)+7)/8)

int index(node **root, istream &is, int *n) {
	node **a = root;
	for(char c = is.get();c != '\n';) {
		if (!*a) {
			*a = new node(c);
			node &b = **a;
			a = &b.EQ;
			c = is.get();
		} else {
			node &b = **a;
			if(c < b.c) a = &b.LT;
			else if (c > b.c) a = &b.GT;
			else {
				a = &b.EQ;
				c = is.get();
			}
		}
	}
	if (!(*a))*a = new node(0);
	if (-1==(**a).n) (**a).n = (*n)++;
	return (**a).n;
}

bool *engines;
int n_cases;
int n_engines;
int engines_left;
int n_switches;

void reset_engines() {
	for(int i=0;i<n_engines;i++) engines[i] = false;
	engines_left = n_engines;
}

void queue_engine(int i) {
	if (!engines[i]){
		engines_left--;
		if (!engines_left) {
			n_switches++;
			reset_engines();
			engines_left--;
		}
		engines[i]=true;
	}
}


void do_case(int n_case) {
	cin >> n_engines;
	cin.ignore();
	engines = new bool[n_engines];
	reset_engines();
	int n = 0;
	node *root = 0;
	for(int i=0;i<n_engines;i++) {
		index(&root, cin, &n);
	}
	int N;
	n_switches = 0;
	cin >> N;
	cin.ignore();
	for(int i=0;i<N;i++) {
		queue_engine(index(&root,cin,&n));
	}
	cout << "Case #" << n_case << ": " << n_switches << endl;
	if (root) delete root;
	delete[] engines;
}


int main(int argc, char* argv[])
{
	
	cin >> n_cases;
	cin.ignore();
	for(int i=0;i<n_cases;i++) do_case(i+1);
	return 0;
}

