#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <memory>

using namespace std;

ifstream fin("a-small-attempt1.in");
ofstream fout("a.out");

int N;
string mix[2000];
int childs[2000][2000];
int bowls[2000];
map<string, int> mixmap;

int findbowls(int x)
{
	for (int i=1; i<=childs[x][0]; i++)
	{
		bowls[childs[x][i]] = findbowls(childs[x][i]);
	}
	int extra = 1;
	int a = 0;
	for (int i=1; i<=childs[x][0]; i++)
	{
		for (int j=i+1; j<=childs[x][0]; j++)
		{
			if (bowls[childs[x][i]] < bowls[childs[x][j]])
			{
				swap(childs[x][i], childs[x][j]);
			}
		}
	}
	if (childs[x][0] == 0) return 1;
	a = bowls[childs[x][1]];
	extra = a;	
	for (int i=2; i<=childs[x][0]; i++)
	{
		a--;
		if (bowls[childs[x][i]] > a)
		{
			extra += bowls[childs[x][i]] - a;
			a = bowls[childs[x][i]];
		}
	}
	a--;
	if (a <= 0) extra++;
	return extra;
}
int main()
{	
	int C;
	fin >> C;
	int cases = 0;
	while (C--)
	{
		fin >> N;
		int numbering = 0;
		mixmap.clear();
		memset(childs, 0, sizeof childs);
		for (int i=0; i<N; i++)
		{
			fin >> mix[i];
			int ni;
			if (mixmap.find(mix[i]) != mixmap.end()) ni = mixmap[mix[i]];
			else mixmap[mix[i]] = ni = numbering++;
			int M;
			fin >> M;
			for (int j=0; j<M; j++)
			{
				string s;
				fin >> s;
				if (isupper(s[0]))
				{
					int nj;
					if (mixmap.find(s) != mixmap.end()) nj = mixmap[s];
					else mixmap[s] = nj = numbering++;
					childs[ni][++childs[ni][0]] = nj;
				}
			}
		}

		memset(bowls, 0, sizeof bowls);
		fout << "Case #" << ++ cases << ": " << findbowls(0) << endl;
	}
	return 0;
}