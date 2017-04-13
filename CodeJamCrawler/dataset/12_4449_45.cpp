/*
Title: A
Data: 2012-4-14
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define InputFileName		"A-small-attempt1.in"
#define OutputFileName		"A-small-attempt1.out"

using namespace std;

const int MaxT = 100, MaxN = 10000;

string a("abcdefghijklmnopqrstuvwxyz");
int TestCase, n;
string S[MaxT], Ans[MaxT];
string w[MaxN];
vector<string> List;

void Initialize()
{
	//abcdefghijklmnopqrstuvwxyz   
	List.push_back(string("there"));
	//List.push_back(string("these"));
	List.push_back(string("good"));
	//List.push_back(string("took"));
	List.push_back(string("every"));
	List.push_back(string("succeed"));
	List.push_back(string("success"));
	List.push_back(string("opinion"));
	List.push_back(string("queue"));
	List.push_back(string("language"));
	List.push_back(string("believe"));
	List.push_back(string("impossible"));
	List.push_back(string("see"));
	//List.push_back(string("zoo"));
	List.push_back(string("three"));
	List.push_back(string("seven"));
	List.push_back(string("eleven"));
	List.push_back(string("twelve"));
	List.push_back(string("suggest"));
	List.push_back(string("suggestion"));
	List.push_back(string("knowledge"));
	List.push_back(string("knowledges"));
	List.push_back(string("happy"));
	//List.push_back(string("speed"));
	//List.push_back(string("fleet"));
	List.push_back(string("google"));
	List.push_back(string("extreme"));
	List.push_back(string("extremely"));
	List.push_back(string("fleeting"));
	List.push_back(string("japanese"));
}

inline bool Analyze(string x, string y)
{
	if (x.length() != y.length())
		return 0;
	for (int i = 0; x[i]; ++i)
		for (int j = i+1; x[j]; ++j)
			if (! (x[i] == x[j] && y[i] == y[j] || x[i] != x[j] && y[i] != y[j]))
				return 0;
	for (int i = 0; x[i]; ++i)
		a[x[i]-'a'] = y[i];
	return 1;
}

void Translate()
{
	for (int i = 1; i <= TestCase; ++i)
		for (int j = 0; S[i][j]; ++j)
			if (S[i][j] != ' ')
				for (int k = 0; a[k]; ++k)
					if (a[k] == S[i][j])
					{
						Ans[i][j] = (char)k+'a';
						break;
					}
}

void Print()
{
	for (char i = 'a'; i <= 'z'; ++i)
		cout << i;
	cout << endl;
	for (int i = 0; i < 26; ++i)
		cout << a[i];
	cout << endl << endl;
	for (int i = 1; i <= TestCase; ++i)
		cout << "Case #" << i << ": " << Ans[i] << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	Initialize();
	cin >> TestCase;
	getline(cin, S[0]);
	for (int T = 1; T <= TestCase; ++T)
	{
		getline(cin, S[T]);
		Ans[T] = S[T];
	}
	string All("");
	for (int T = 1; T <= TestCase; ++T)
		All += S[T]+string(" ");
	for (istringstream ssin(All); ssin >> w[n]; ++n);
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < List.size(); ++j)
			Analyze(w[i], List[j]);
	a = string("ynficwlbkuomxsevzpdrjgthaq");
	Translate();
	Print();
	return 0;
}
