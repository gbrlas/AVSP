// DecisionTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "sstream"
using namespace std;

struct node 
{
	double weight;
	string feature;
	struct node* TNode;
	struct node* FNode;
};

char nextChar(stringstream& ss)
{
	char ch;
	ss>>ch;
	ss.putback(ch);
	return ch;
}

void readChild(stringstream &ss, struct node* &cur)
{
	string str;
	while(1)
	{
		if(nextChar(ss)=='(')
		{
			if(cur==NULL) 
			{
				cur=new struct node;
				cur->TNode=NULL;
				cur->FNode=NULL;
				//parse weight;
				char ch;
				stringstream ss1;
				while(ss>>ch)
				{
					if(ch=='(') continue;
					if(!(ch>='0' && ch<='9' || ch=='.')) {ss.putback(ch); break;}
					ss1<<ch;
				}
				ss1>>cur->weight;
			}
			else
			{
				readChild(ss,cur->TNode);
				readChild(ss,cur->FNode);
			}
		}
		else
		{
			
			if(nextChar(ss)==')')
			{
				char ch;			
				ss>>ch;
				return;
			}
			else
			{
				//read feature;
				ss>>cur->feature;
			}
		}
	}
}

int contains(vector<string> &f1, string f)
{
	for(int i=0;i<f1.size();i++)
	{
		if(f1[i] == f)
			return 1;
	}
	return 0;
}

int main()
{
	int N;
	cin>>N;
	for(int tc=0;tc<N;tc++)
	{
		cout<<"Case #"<<tc+1<<":"<<endl;
		int L;
		cin>>L;
		char buf[1024]={};
		cin.getline(buf,1024);
		string str;
		for(int i=0;i<L;i++)
		{
			cin.getline(buf,1024);
			str.append(buf);
		}
		stringstream ss(str);
		string part;
		struct node *root = NULL;
		readChild(ss,root);
		int A;
		cin>>A;
		for(int i=0;i<A;i++)
		{
			string animal;
			cin>>animal;
			int n;
			cin>>n;
			vector<string> features;
			string str;
			for(int j=0;j<n;j++)
			{
				cin>>str;
				features.push_back(str);
			}
			struct node *p = root;
			double ans=1.0;
			while(p)
			{
				if(contains(features,p->feature))
				{
					ans*=p->weight;
					p=p->TNode;
				}
				else
				{
					ans*=p->weight;
					p=p->FNode;
				}
			}
			printf("%.8lf\n",ans);
		}
		//delete root
	}
	return 0;
}

