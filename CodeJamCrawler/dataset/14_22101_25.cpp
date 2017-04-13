#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cstdint>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;

	scanf("%d", &T);
	for(int c = 1; c <= T; ++c)
	{	
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);

		int t = 100000;

		double res = DBL_MAX;
		
		double ttt = 0.0;
		for(int i = 0; i <= t; ++i)
		{
			double currf = (double)i * F + 2.0;

			double rtemp = 0.0;

			if(i != 0)
				ttt += C / ((i-1) * F + 2.0); 

			rtemp += ttt;
			rtemp += X / currf;

			res = min(res, rtemp);
		}

		printf("Case #%d: %.7lf\n", c, res);
	}
}