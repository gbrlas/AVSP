#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("A-large.in");
int L,D,N;
vector<int> category[15][26];
string words[5000];
int counter[5000];

void build_category()
{
	for(int i=0;i<D;i++) {
		string &str = words[i];
		for(int j=0;j<L;j++) {
			category[j][str[j]-'a'].push_back(i);
		}
	}
}

void do_count(int l, char c)
{
	vector<int> &v = category[l][c-'a'];
	for(int i=0;i<v.size();i++) {
		counter[v[i]]++;
	}
}

void analyze(string &pattern)
{
	int l = 0;
	for(int i=0;i<pattern.length();i++) {
		if(pattern[i]=='(') {
			while(pattern[++i]!=')')
				do_count(l, pattern[i]);
		} else {
			do_count(l, pattern[i]);
		}
		++l;
	}
}

int main()
{
	fin>>L>>D>>N;
	for(int i=0;i<D;i++)
	{
		fin>>words[i];
	}
	build_category();
	for(int i=1;i<=N;i++)
	{
		memset(counter,0,sizeof(counter));
		string pattern;
		fin>>pattern;
		analyze(pattern);
		printf("Case #%d: %d\n", i, count(counter, counter+D, L));
	}
	return 0;
}