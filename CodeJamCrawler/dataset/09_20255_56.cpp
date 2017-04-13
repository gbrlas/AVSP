#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

typedef long double num;

struct node
{
	num p;
	string f;
	node *l, *r;

	node(num p, const string& f= "", node* l=NULL, node* r=NULL) : p(p), f(f), l(l), r(r) {}
	~node() { delete l; delete r; }
};

node* read(istream& cin)
{
	num p;
	char c;
	cin>>c>>p>>c;
	//clog<<p<<' '<<c<<endl;
	if(c == ')') return new node(p);
	cin.putback(c);
	string f;
	cin>>f;
	bool closed = false;
	if(f[f.size()-1] == ')') closed = true, f.erase(f.size()-1);
	node* l = read(cin);
	node* r = read(cin);
	if(!closed) cin>>c;
	return new node(p, f, l, r);
}

struct animal
{
	string name;
	set<string> attr;
};
istream& operator>>(istream& cin, animal& x)
{
	int n;
	string s;
	cin>>x.name>>n;
	x.attr.clear();
	while(n--) cin>>s, x.attr.insert(s);
	return cin;
}

num go(const animal& a, const node* const r)
{
	if(!r) return 1;
	num ret = r->p;
	if(r->f.size())
	{
		if(a.attr.count(r->f)) ret *= go(a, r->l);
		else ret *= go(a, r->r);
	}
	return ret;
}

int main()
{
	//ifstream cin("A-small-attempt0.in");
	//ofstream cout("out.txt");
	int T, L;
	cin>>T;
	int na;
	animal an;
	cout.setf(ios::fixed);
	cout.precision(7);
	for(int run = 1; run <= T; ++run)
	{
		cout<<"Case #"<<run<<':'<<endl;
		cin>>L;
		node* r = read(cin);
		cin>>na;
		while(na--)
		{
			cin>>an;
			cout<<go(an, r)<<endl;
		}
		delete r;
	}
}
