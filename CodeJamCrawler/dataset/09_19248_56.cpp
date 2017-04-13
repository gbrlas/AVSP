
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;
//

double result;
vector<string> allFeather;
//

	ifstream infile("D:\\A-small-attempt0.in.txt",ios::in);
	ofstream outfile("D:\\result.out.txt",ios::out);
//

class Node
{
public:
	double weight;
	string name;
	Node* left;
	Node* right;
	Node(double w,string n):weight(w),name(n),left(0),right(0){}
	Node():left(0),right(0){}
};

void Input(Node* &n)
{
	char c;
	char str[30];
	string name;
	double weight;
	infile >> c;
	infile >> str;
	int len=strlen(str);
	if(str[len-1]==')')
	{
		str[len-1]='\0';
		weight=atof(str);
		n=new Node(weight,"");
	}
	else
	{
		weight=atof(str);
		infile >> name;
		n=new Node(weight,name);
		Input(n->left);
		Input(n->right);
		infile >> c;
	}
}

bool finded(string ss,vector<string> v)
{
	bool flag=false;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==ss)
		{
			flag=true;
			break;
		}
	}
	return flag;
}

void Search(Node* n)
{
	result*=n->weight;
	if(n->name!="")
	{
		if(finded(n->name,allFeather))
		{
			Search(n->left);
		}
		else
			Search(n->right);
	}
}

int main()
{
	//
	int N;;
	int prob=1;
	infile >> N;
	infile.ignore();
	while(N--)
	{
		int line;
		infile >> line;
		Node* Root=0;
		Input(Root);
		int animal;
		infile >> animal;
		outfile << "Case #" << prob++ << ": " <<  endl;
		while(animal--)
		{
			result=1;
			allFeather.clear();
			//
			string name;
			infile >> name;
			int feather;
			infile >> feather;
			allFeather.reserve(feather);
			while(feather--)
			{
				string fea;
				infile >> fea;
				allFeather.push_back(fea);				
			}
			//
			Search(Root);
			outfile << fixed << setprecision(7) <<  result << endl;
			//
		}
	}
	return 0;
}