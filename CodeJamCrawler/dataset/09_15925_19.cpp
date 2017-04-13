#include <stdio.h>
#include <math.h> 
#include <iostream>
#include <sstream> 
#include <set> 
#include <map> 
#include <vector> 
#include <list> 
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string GetLine()
{
		string line; 
        do 
        { 
			getline(cin,line); 
        } 
        while(line==""); 
		return line;
}

template<typename F, typename S>
void  ReadPair(const string& aLine, F& aFirst, S& aSecond)
{
		int pos=aLine.find(':'); 
		stringstream first(aLine.substr(0,pos));
		first>>aFirst;
		stringstream second(aLine.substr(pos+1));
		second>>aSecond;
}

string result;

struct Node
{
	~Node(){delete truenode;delete falsenode;}
	Node(string& desc) {
		leaf = false;
		truenode=falsenode=0;
        int pos1=desc.find_first_of('(');
		int pos2=desc.find_last_of(')');
		description=desc.substr(pos1+1, pos2-pos1-1);
        stringstream feat(description);
		feat >> value;
		if (description.find_first_of('(') == string::npos) {
			leaf = true;
		}
		else {
			feat >> feature;
            
			int pos1 = description.find_first_of('(');
			int pos2 = pos1;
			int pos3 = pos1;
			do {

				pos2 = description.find_first_of(')', pos2+1);
				pos3 = description.find_first_of('(', pos3+1);
				if (pos3==string::npos || pos3>pos2) {
					truenode = new Node(description.substr(pos1, pos2-pos1+1));
					break;
				}
			}
			while(1);

			pos1 = description.find_first_of('(', pos2);
			pos2 = pos1;
			pos3 = pos1;
			do {

				pos2 = description.find_first_of(')', pos2+1);
				pos3 = description.find_first_of('(', pos3+1);
				if (pos3==string::npos || pos3>pos2) {
					falsenode = new Node(description.substr(pos1, pos2-pos1+1));
					break;
				}
			}
			while(1);
		}
	}
   string description;
   double value;
   string feature;
   Node* truenode;
   Node* falsenode;
   bool leaf;
};


Node ReadTree()
{
	int N;
   cin>>N;
   string tree;
   for(int i = 0; i < N; ++i) {
	   tree+=GetLine();
   }
   return Node(tree);
}

double Traverse(Node& root, set<string> ft)
{
   double p = 1;
   p*=root.value;
   if (root.leaf) {
	   return p;
   }
   if (ft.find(root.feature) != ft.end()) {
	   p *= Traverse(*root.truenode, ft);
   }
   else {
	   p *= Traverse(*root.falsenode, ft);
   }
   return p;
}


void ReadAnimals(Node& root)
{
	int N;
   cin>>N;
   for(int i = 0; i < N; ++i) {
       string animal;
	   cin >> animal;
	   int feats;
	   cin >> feats;
	   set<string> ft;
	   for (int j = 0; j < feats; ++j) {
           string f;
		   cin >> f;
		   ft.insert(f);
	   }
	   cout << setprecision(7) << fixed << Traverse(root, ft) << endl;

   }
}

void PrintResult(int i)
{//printf("Case #%d: %.7lf\n", i,CheapestWay);
		cout<<"Case #"<<i<<":"<<endl;
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int T;
	cin>>T;

	for(int i=1;i<=T;++i)
	{
		PrintResult(i);
		Node n = ReadTree();
		ReadAnimals(n);
	}
	return 0;
}
