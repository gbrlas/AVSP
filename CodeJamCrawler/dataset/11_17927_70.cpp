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

int C, D, N;
vector <string> builds;
vector <pair <char, char> > des;
string inp;

int ans [105];
int top;

void preprocess()
{
	
}

bool input()
{
	builds.clear();
	des.clear();
	
	s(C);
	string x, y;
	for(int i = 0; i < C; i++)
	{	
		cin >> x;
		builds.push_back(x);
		y = "";
		y.push_back(x[1]);
		y.push_back(x[0]);
		y.push_back(x[2]);
		builds.push_back(y);
	}
	
	s(D);
	for (int i = 0; i < D; i++)
	{
		cin >> x;
		//cout << "Read " << x << endl;
		des.push_back(make_pair(x[0], x[1]));
		des.push_back(make_pair(x[1], x[0]));
	}
	
	s(N);
	cin >> inp;
	
	return true;
}

bool dest(char a, char b)
{
	for(int i = 0, l = des.size(); i < l; i++)
		if(a == des[i].first && b == des[i].second)
			return true;
	return false;
}

int conv(char a, char b)
{
	int ret, lim;
	for(ret = 0, lim = builds.size(); ret < lim; ret++)
		if(a == builds[ret][0] && b == builds[ret][1])
			return ret;
	return ret;
}

void solve()
{
	top = 0;
	for(int i = 0; i < N; i++)
	{
		//cout << "Scanning " << inp[i] << endl;
		ans[top++] = inp[i];
		if(top > 1)
		{
			char a = ans[top-1];
			char b = ans[top-2];
			
			int val = conv(a, b);
			if(val < builds.size())
			{
				//cout << "Converting" << endl;
				top--; top--;
				ans[top++] = builds[val][2];
			}
			else 
			{
				for(int j = 0; j < top-1; j++)
				{
					b = ans[j];
					if(dest(a, b))
					{
						top = 0;
						break;
					}
				}
			}
		}
	}
	
	printf("Case #%d: [", testNum);
	for(int i = 0; i < top; i++)
		printf("%c%c%c", ans[i], (i == top-1? ']': ','), (i == top-1? '\n': ' '));
	if( top == 0 )
		printf("]\n");
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
