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
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair

int totalCases, testNum;
int N, W, L;
int R[6006];

vector<pair <int, int> > order;

void preprocess()
{
	
}

bool input()
{
	s(N);
	s(W);
	s(L);
	for(int i = 0; i < N; i++)
		s(R[i]);
	
	return true;
}

void solve()
{
	printf("Case #%d: ", testNum);
	int x[6006];
	int y[6006];
	
	order.clear();
	for(int i = 0; i < N; i++)
		order.push_back(mp(R[i], i));
	
	sort(order.rbegin(), order.rend());
	
	int Y, i, prevX, nxtX;
	prevX = -order[0].first;
	int X;
	i = 0, Y = -order[0].first;
	while(i < N)
	{
		X = prevX + order[i].first;
		assert(X <= W);
		nxtX = X + order[i].first;
		while(i < N && Y + order[i].first <= L)
		{
			int R = order[i].first;
			y[order[i].second] = Y + R;
			x[order[i].second] = X;
			i++;
			Y += 2 * R;
		}
		if(i >= N)
			break;
		Y = -order[i].first;
		prevX = nxtX;
	}
	
	for(int i = 0; i < N; i++)
		printf("%d %d ", x[i], y[i]);
	printf("\n");
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
