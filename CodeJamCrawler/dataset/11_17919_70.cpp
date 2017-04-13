/*
 	Team Proof
	IIT Delhi
 
	C++ Template
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))

int totalCases, testNum;

int N;
vector <int> orange, blue;
pair <char, int> inp[105];

int finish[105];

void preprocess()
{
	
}

bool input()
{
	orange.clear(); orange.push_back(1);
	blue.clear(); blue.push_back(1);
	
	string x;
	int y;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		inp[i] = make_pair(x[0], y);
		if(inp[i].first == 'O')
			orange.push_back(y);
		else 
			blue.push_back(y);
	}
	orange.push_back(10000);
	blue.push_back(10000);
	
	return true;
}

void solve()
{
	int prev = 0;
	
	int minO, minB;
	minO = orange[1] - orange[0];
	minB = blue[1] - blue[0];
	
	int octr = 1, bctr = 1;
	
	for(int i = 0; i < N; i++)
	{
		if(inp[i].first == 'O')
		{
			prev = max(prev + 1, minO + 1);
			minO = prev + abs(orange[octr+1] - orange[octr]);
			octr++;
		}
		else 
		{
			prev = max(prev + 1, minB + 1);
			minB = prev + abs(blue[bctr+1] - blue[bctr]);
			bctr++;
		}
	}
	printf("Case #%d: %d\n", testNum, prev);
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
