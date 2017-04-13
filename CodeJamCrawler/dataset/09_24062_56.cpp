#include <algorithm> 
#include <cassert>
#include <cctype> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <iostream>
#include <map> 
#include <set> 
#include <string> 
#include <sstream>
#include <queue> 
#include <vector> 
using namespace std;


class node;
int N, A, L;
vector <string> trs, an;
vector <double> res;
vector <node> tree;
string T;

void read()
{
	char buf[1000];
	scanf("%d", &L);
	gets(buf);
	trs.clear();
	an.clear();
	for (int i=0; i<L; i++)
	{
		gets(buf);
		trs.push_back(buf);
	}
	scanf("%d", &A);
	gets(buf);
	for (int i=0; i<A; i++)
	{
		gets(buf);
		an.push_back(buf);
	}
	res.clear();
}

class node
{
public:
	double p;
	string feature;
	int s1;
	int s2;

	node() {feature=""; p=1;s1=-1; s2=-1;}
	void set(double pp, string f,  int s11, int s22)
	{
		p=pp; feature = f; s1=s11; s2=s22;
	}
};


int make_tree(int i, int pos)
{
	int j=pos+1;
	double w;
	string num="";
	while (T[j]==' ') j++;
	while ((T[j]>='0' && T[j]<='9') || (T[j]=='.'))
	{
		num+=T[j];
		j++;
	}
	char t[1000];
//	for (int k=0; k<num.size(); k++)
//		t[k]=num[k];
//	t[num.size()]='\n';
	sscanf(num.c_str(), "%lf", &w);
	tree[i].p=w;
	while (T[j]==' ') j++;
	if (T[j]!=')')
	{
	//	j++;
		num="";
		while (T[j]!=' ')
		{
			num += T[j];
			j++;
		}
		tree[i].feature=num;
		node tn;
		tree.push_back(tn);
		while (T[j] ==' ')
			j++;
		tree[i].s1=tree.size()-1;
		j = make_tree(tree.size()-1, j);
		while (T[j] ==' ')
			j++;
		node tn1;
		tree.push_back(tn1);
		tree[i].s2=tree.size()-1;
		j = make_tree(tree.size()-1, j);
		while (T[j]==' ') j++;
	}
	return j+1;
}

vector <string> Split(const string& s, string sep)
{
	string tmp = ""; 
	vector <string> Res; 
	for(int i=0;i<s.length();++i)
	{
		if(sep.find(s[i])==string::npos)
			tmp+=s[i];
		else if(!tmp.empty())
		{
			Res.push_back(tmp);
			tmp="";
		}
	}
	if(!tmp.empty())
		Res.push_back(tmp);
	return Res;
}

void dec(string ani)
{
	vector <string> tmp;
	set <string> fs;
	tmp = Split(ani, " \n");
	for (int i=2; i<tmp.size(); i++)
		fs.insert(tmp[i]);
	double resu=1.;
	int nod=0;
	string f;
	while (true)
	{
		resu *= tree[nod].p;
		f = tree[nod].feature;
		if (f=="")
			break;
		else if (fs.find(f) != fs.end())
			nod = tree[nod].s1;
		else 
			nod = tree[nod].s2;
	}
	res.push_back(resu);
}




void solve(string s)
{
	T="";
	for (int i=0; i<trs.size(); i++)
		T += trs[i]+' ';
	tree.clear();
	tree.resize(1);
	int i=0;
	while (T[i]!='(') i++;

	make_tree(0,i);
	for (int j=0; j<an.size(); j++)
		dec(an[j]);
}

void write(int i)
{

	printf("Case #%d:\n", i);
	for (int j=0; j<res.size()-1; j++)
		printf("%lf\n", res[j]);
	printf("%lf", res[res.size()-1]);
	if (i!=N)
		printf("\n");

}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	char buf[1000];
	string s;


	scanf("%d", &N);
	gets(buf);
	for (int i=0; i<N; i++)
	{
		read();	
		solve(s);
		write(i+1);
	}
	return 0;
}
