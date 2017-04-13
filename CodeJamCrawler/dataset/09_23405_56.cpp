#include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


char buf[10240];
set<string> features;

char tree[100000];

int L, A, nUsed, n;

double dfs(int pos)
{
	int i;
	double cur = 1.0;
	for (i = pos; tree[i] && tree[i] != '(' && tree[i] != ')'; ++i);
	if (!tree[i]) cur;
	else if (tree[i] == '(')
	{
		double temp = 0.0, help = 0.1;
		for (++i; !isdigit(tree[i]); ++i);
		if (tree[i] == '1') temp = 1.0;
		for (++i; tree[i] && tree[i] != '.'; ++i);
		for (++i; tree[i] && isdigit(tree[i]); ++i)
		{
			temp += help * static_cast<int>(tree[i] - '0');
			help *= 0.1;
		}
		cur *= temp;
		for (;tree[i] && tree[i]!=')' && !isalpha(tree[i]); ++i);
		if (tree[i] == ')') return cur;
		string tempf = "";
		for (; tree[i] && isalpha(tree[i]); ++i) tempf += tree[i];
		if (features.find(tempf) != features.end()) cur *= dfs(i);
		else
		{
			int ll = 1;
			for (; tree[i]!=')' && tree[i]!='('; ++i);
			if (tree[i]==')') return cur;
			for (++i; tree[i]; ++i)
			{
				if (!ll)
				{
					cur *= dfs(i);
					break;
				}
				else if(tree[i]=='(') ++ll;
				else if (tree[i]==')') --ll;
				else {}
			}
		}
	}
	
	return cur;
}

double solve()
{
	return dfs(0);
}
int main()
{
	freopen("E:\\GCJ\\A-small.in", "r", stdin);
	freopen("E:\\GCJ\\A-small.out", "w", stdout);
	int nCase = 0;
	fgets(buf, 1023, stdin);
	//gets(buf);
	nCase = atoi(buf);

	for (int cnt = 1; cnt <= nCase; ++cnt)
	{
		
		printf("Case #%d:\n", cnt);
		fgets(buf, 1023, stdin);
		//gets(buf);
		L = atoi(buf);
		memset(tree, 0, sizeof tree);
		for (int i =0; i < L; ++i)
		{
			fgets(buf, 1023, stdin);
		//	gets(buf);
			strcat(tree,buf);
		}
		fgets(buf, 1023, stdin);
		//gets(buf);
		A = atoi(buf);
		for (int i = 0; i < A; ++i)
		{
			features.clear();
			fgets(buf, 1023, stdin);
			//gets(buf);
			string temp;
			istringstream iss(buf);
			iss >> temp >> n;
			while(n--) 
			{
				iss >> temp;
				features.insert(temp);
			}
			double res = solve();
			printf("%.7f\n", res);
		}
	}
	return 0;
}

