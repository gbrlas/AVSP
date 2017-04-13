
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <list>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;

class MyTree
{
public:
	MyTree* Next[26];
	MyTree()
	{
		for(int i=0;i<26;i++)
			Next[i]=0;
	}
};


int L,D,N;
char temp;
vector<vector<char> > All;
int Count;
MyTree Tree;
MyTree* tempPointer;

//


void solve(int index,MyTree* p)
{
	if(index==L)
	{
		Count++;
	}
	else
	{
		for(int i=0;i<All[index].size();i++)
		{
			if(p->Next[All[index][i]-'a']!=0)
				solve(index+1,p->Next[All[index][i]-'a']);
		}
	}
}


int main()
{
	//
	ifstream infile("D:\\A-small-attempt3.in.txt",ios::in);
	ofstream outfile("D:\\result.out.txt",ios::out);
	infile >> L >> D >> N;
	for(int i=0;i<D;i++)
	{
		MyTree* pointer=&Tree;
		for(int j=0;j<L;j++)
		{
			infile >> temp;
			if(pointer->Next[temp-'a']==0)
				pointer->Next[temp-'a']=new MyTree();
			pointer=pointer->Next[temp-'a'];
		}
	}
	//
	for(int i=0;i<N;i++)
	{
		char c;
		int pos=0;
		bool flag=false;
		All.clear();
		All.resize(L);
		Count=0;
		while(1)
		{
			infile >> c;
			if(c=='(')
				flag=true;
			else if(c==')')
				flag=false;
			else
			{
				All[pos].push_back(c);
			}
			//
			if(!flag)
				pos++;
			if(pos==L)
				break;
		}
		//
		solve(0,&Tree);
		outfile << "Case #" << i+1 << ": " << Count << endl;
	}
	return 0;
}