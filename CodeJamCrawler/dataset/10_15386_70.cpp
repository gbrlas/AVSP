#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

struct Tree
{
	string name;
	vector<Tree*> next;
};

int kst = 0;

void modify(Tree *root, vector<string> path, int now)
{
	if(now==path.size())
		return;
	bool flag = false;
	for(int i=0;i<root->next.size();i++)
		if(path[now].compare(root->next[i]->name)==0)
		{
			flag = true;
			modify(root->next[i],path,now+1);
		}
	if(!flag)
	{
		root->next.push_back(new Tree);
		root->next[root->next.size()-1]->name = path[now];
		kst++;
		modify(root->next[root->next.size()-1],path,now+1);
	}
}		

int main()
{
	string s;
	freopen("A-small.in","r",stdin);
	freopen("result.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++)
	{
		int N,M;
		Tree *Main = new Tree;
		Main->name = "";
		scanf("%d%d",&N,&M);
		
		for(int i=0;i<N;i++)
		{
			cin >>s;
			vector<string> path;
			string temp;
			for(int i=1;i<s.size();i++)
			{
				if(s[i]=='/')
					path.push_back(temp);
				else
					temp.push_back(s[i]);
			}
			path.push_back(temp);
			modify(Main, path, 0);
		}
		kst = 0;
		for(int i=0;i<M;i++)
		{
			cin >>s;
			vector<string> path;
			string temp;
			for(int i=1;i<s.size();i++)
			{
				if(s[i]=='/')
					path.push_back(temp);
				else
					temp.push_back(s[i]);
			}
			path.push_back(temp);
			modify(Main, path, 0);
		}
		printf("Case #%d: %d\n",z+1,kst);
	}
	return 0;
}