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

string table[105];
int N;

double WP[105];
double OWP[105];
double OOWP[105];
double RPI[105];

void preprocess()
{
	
}

bool input()
{
	//string line;
	
	s(N);
	for(int i = 0; i < N; i++)
		cin >> table[i];
	
	return true;
}

void solve()
{
	int num, den;
	
	for(int i = 0; i < N; i++)
	{
		num = den = 0;
		WP[i] = 0.0;
		for(int j = 0; j < N; j++)
		{
			num += (table[i][j] == '1');
			den += (table[i][j] != '.');
		}
		WP[i] = ( 1.0 * num )/ den;
	}
	
	double nWP[105];
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			num = den = 0;
			for(int k = 0; k < N; k++) if (k != i)
			{
				num += (table[j][k] == '1');
				den += (table[j][k] != '.');
			}
			nWP[j] = (1.0 * num)/den;
		}
		
		double sum = 0.0;
		den = 0;
		for(int j = 0; j < N; j++)
		{
			if(table[i][j] == '.' ) continue;
			sum += nWP[j];
			den++;
		}
		OWP[i] = sum/den;
	}
	
	for(int i = 0; i < N; i++)
	{
		OOWP[i] = 0.0;
		den = 0;
		for(int j = 0; j < N; j++) if(table[i][j] != '.')
		{
			den++;
			OOWP[i] += OWP[j];
		}
		OOWP[i] /= den;
	}
	
	for(int i = 0; i < N; i++)
	{
		RPI[i] = 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i];
	}
	
	printf("Case #%d:\n", testNum);
	for(int i = 0; i < N; i++)
		printf("%lf\n", RPI[i]);
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
