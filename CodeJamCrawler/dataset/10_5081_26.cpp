#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, n) for(int (i) = 0; (i) < (int) (n); (i)++)

class tree
{
public:
	string currentNodeStr;
	vector<tree*> childNodes;
};

int main(int argc, char *argv)
{
	ifstream input("A-small-attempt0.in");
	ofstream output("A-small.out");
	int T;
	input>>T;
	FOR(cases, T)
	{
		int N,M;
		input>>N>>M;
		vector<tree*> trees;
		FOR(i,N)
		{
			string line;
			input>>line;
			vector<string> dirs;
			vector<int> index;
			FOR(j, line.size())
			{
				if(line[j] == '/')
				{
					index.push_back(j);
				}
			}
			int j = 0;
			tree *currentTree;
			for(; j < index.size() - 1; j++)
			{
				string currentDir = line.substr(index[j]+1,index[j+1]-index[j]-1);
				//dirs.push_back(currentDir);
				if(j == 0)
				{
					bool flag = false;
					FOR(k, trees.size())
					{
						if(trees[k]->currentNodeStr == currentDir)
						{
							currentTree = trees[k];
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						currentTree = new tree;
						currentTree->currentNodeStr = currentDir;
						trees.push_back(currentTree);
					}
				}
				else
				{
					bool flag = false;
					FOR(k, currentTree->childNodes.size())
					{
						if(currentTree->childNodes[k]->currentNodeStr == currentDir)
						{
							currentTree = currentTree->childNodes[k];
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						tree *tmp = new tree;
						tmp->currentNodeStr = currentDir;
						currentTree->childNodes.push_back(tmp);
						currentTree = tmp;
					}					
				}
			}
			string currentDir = line.substr(index[index.size()-1]+1, line.size()-1-index[index.size()-1]);
			if(j == 0)
			{
				bool flag = false;
				FOR(k, trees.size())
				{
					if(trees[k]->currentNodeStr == currentDir)
					{
						currentTree = trees[k];
						flag = true;
						break;
					}
				}
				if(flag == false)
				{
					currentTree = new tree;
					currentTree->currentNodeStr = currentDir;
					trees.push_back(currentTree);
				}
			}
			else
			{
				bool flag = false;
				FOR(k, currentTree->childNodes.size())
				{
					if(currentTree->childNodes[k]->currentNodeStr == currentDir)
					{
						currentTree = currentTree->childNodes[k];
						flag = true;
						break;
					}
				}
				if(flag == false)
				{
					tree *tmp = new tree;
					tmp->currentNodeStr = currentDir;
					currentTree->childNodes.push_back(tmp);
					currentTree = tmp;
				}					
			}
		}
		int mkDirTimes = 0;
		FOR(i,M)
		{
			string line;
			input>>line;
			vector<string> dirs;
			vector<int> index;
			FOR(j, line.size())
			{
				if(line[j] == '/')
				{
					index.push_back(j);
				}
			}
			int j = 0;
			tree *currentTree;
			for(; j < index.size() - 1; j++)
			{
				string currentDir = line.substr(index[j]+1,index[j+1]-index[j]-1);
				//dirs.push_back(currentDir);
				if(j == 0)
				{
					bool flag = false;
					FOR(k, trees.size())
					{
						if(trees[k]->currentNodeStr == currentDir)
						{
							currentTree = trees[k];
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						currentTree = new tree;
						currentTree->currentNodeStr = currentDir;
						trees.push_back(currentTree);
						mkDirTimes++;
					}
				}
				else
				{
					bool flag = false;
					FOR(k, currentTree->childNodes.size())
					{
						if(currentTree->childNodes[k]->currentNodeStr == currentDir)
						{
							currentTree = currentTree->childNodes[k];
							flag = true;
							break;
						}
					}
					if(flag == false)
					{
						tree *tmp = new tree;
						tmp->currentNodeStr = currentDir;
						currentTree->childNodes.push_back(tmp);
						currentTree = tmp;
						mkDirTimes++;
					}					
				}
			}
			string currentDir = line.substr(index[index.size()-1]+1, line.size()-1-index[index.size()-1]);
			if(j == 0)
			{
				bool flag = false;
				FOR(k, trees.size())
				{
					if(trees[k]->currentNodeStr == currentDir)
					{
						currentTree = trees[k];
						flag = true;
						break;
					}
				}
				if(flag == false)
				{
					currentTree = new tree;
					currentTree->currentNodeStr = currentDir;
					trees.push_back(currentTree);
					mkDirTimes++;
				}
			}
			else
			{
				bool flag = false;
				FOR(k, currentTree->childNodes.size())
				{
					if(currentTree->childNodes[k]->currentNodeStr == currentDir)
					{
						currentTree = currentTree->childNodes[k];
						flag = true;
						break;
					}
				}
				if(flag == false)
				{
					tree *tmp = new tree;
					tmp->currentNodeStr = currentDir;
					currentTree->childNodes.push_back(tmp);
					currentTree = tmp;
					mkDirTimes++;
				}					
			}
		}		
		output<<"Case #"<<cases+1<<": "<<mkDirTimes<<endl;
	}
}