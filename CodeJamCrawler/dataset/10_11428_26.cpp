// Google Code Jam 2010 - Round A - sub round 2 - Question A
// Hila4321 <> gmail <> com
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int counter = 0;
int count;

class Tree{
public:
	string name;
	map<string,Tree*> sons;

	Tree()
	{
	}

	Tree(string n)
	{
		name = n;
	}
	void insert(string p)
	{
		char str[101];
		char way[101];
		strcpy(way,p.c_str());
		char* q = way;
		if (q == NULL || *q == '\0' || *q == '\n' || *q == 10)
			return;
		int i=0;
		q++; // skip the '/'
		while (*q!='/' && q != NULL && *q != '\0' && *q != '\n' && *q != 10  && *q != (-52))
		{
			str[i] = *q;
			i++;
			q++;
		}
		str[i] = '\0';
		if (sons.count(str)==0)
		{
			sons[str] = new Tree(str);
			if (count==1)
				counter ++;
		}
		if (*q=='/') // we have son!
		{
			sons[str]->insert(string(q));
		}
		return;
	}
};

int main()
{
	ifstream input("A-small-attempt0.in");
	ofstream output("A-small-attempt0.out");

	int T;
	input >> T;

	for (int tc=1; tc<=T; tc++)
	{
		int n, m;
		string path;
		input >> n;
		input >> m;
		map <string,int> sort;
		Tree dic;

		counter = 0;
		count = 0;
		for (int i=0; i<n; i++)
		{
			input >> path;
			dic.insert(path);
		}
		for (int i=0; i<m; i++)
		{
			input >> path;
			sort[path]++;
		}
		count = 1;
		for (map<string,int>::iterator it = sort.begin(); it!=sort.end(); it++)
		{
			dic.insert(it->first);
		}
		output <<"Case #" << tc <<": " << counter  << endl;
	}
	return 0;
}