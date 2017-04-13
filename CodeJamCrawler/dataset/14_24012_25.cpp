#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define mp make_pair

const int MAX = (int)1e5 + 5; 
double T[MAX];

int main()
{
	int t;
	scanf("%d", &t);
	
	for(int test = 1; test <= t; test++)
	{
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);

		T[0] = 0;
		double ans = (X / 2.0);

		for(int i = 1; i <= (int)X; i++)
		{
			T[i] = T[i-1]  + (C / (F *(i-1) + 2.0));

			ans = min(ans, T[i] + (X / (F*i  + 2.0))); 
		}

		printf("Case #%d: ", test);
		printf("%.7lf\n", ans);
	}

		
	return 0;
}