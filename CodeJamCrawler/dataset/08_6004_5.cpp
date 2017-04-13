#include <iostream>
#include<fstream>
#include<vector>
#include <string>
using namespace std;
#define MIN(a,b) ((a>b)?(b):(a))
class univ
{
public:
	vector <string> search_engine;
	vector <string> queries;
	int precomputed[1001][101];
	int szse;
	int szq;
	int min_switch (int query, int curr_engine);
};

univ::min_switch(int query, int curr_engine)
{
	if (query == szq)
		return 0;
	if (precomputed[query][curr_engine] != -1)
		return precomputed[query][curr_engine];
	if (queries[query] != search_engine[curr_engine])
	{
		precomputed[query][curr_engine] = min_switch (query + 1 , curr_engine);
		return precomputed[query][curr_engine];
	}
	int ans = 9999999;
	for (int i = 0; i < szse ; i ++)
	{
		if (i == curr_engine)
			continue;
		ans = MIN(ans,min_switch(query,i));
	}
	if (ans == 9999999)
	{
		precomputed[query][curr_engine] = 0;
		return 0;
	}
	precomputed[query][curr_engine] = 1 + ans;
	return precomputed[query][curr_engine];
}


int main()
{
	ifstream fin ("input.in");
	ofstream fout ("output.out");
	int n;
	int ans = 9999999;
	fin >> n;
	vector <univ> v(n);
	for (int i = 0; i < n; i ++)
	{
		//univ a;
		fin >> v[i].szse;
		//v[i].search_engine.resize(szse);
		string s;
		char buff[101];
		fin.getline(buff,100);
		for (int j = 0; j < v[i].szse; j ++)
		{
			fin.getline(buff,100);
			s = buff;
			v[i].search_engine.push_back(s);
		}
		fin >> v[i].szq;
		fin.getline(buff,100);
		//v[i].queries.resize(szq);
		for (int k = 0; k < v[i].szq; k++)
		{
			fin.getline(buff,100);
			s = buff;
			v[i].queries.push_back(s);
		}
		ans = 9999999;
		//Memoize for optimization
		for (int m = 0; m < v[i].szq; m++)
			for (int n = 0; n < v[i].szse; n ++)
				v[i].precomputed[m][n] = -1;
		for (int l = 0; l < v[i].szse; l++)
		{
			ans = MIN(ans,v[i].min_switch(0,l));
		}
		if (ans == 9999999)
			ans = 0;
		fout << "Case #" << i + 1 << ": " <<ans<<endl;
	}
	return 0;
}