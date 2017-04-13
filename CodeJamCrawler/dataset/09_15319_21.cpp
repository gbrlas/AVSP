#include<iostream> 
#include<algorithm>
#include<queue>
#include<stack>
#include<numeric>
#include<vector>
#include<sstream>
#include<strstream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<map>
using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
	return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int C;
	cin >> C;
	for(int c=0; c<C; c++)
	{
		int N;
		cin >> N;
		vector<int> x(N), y(N), r(N);

		for(int i=0; i<N; i++)
		{
			cin >> x[i] >> y[i] >> r[i];
		}

		while(x.size()<3)
		{
			x.push_back(x[0]);
			y.push_back(y[0]);
			r.push_back(r[0]);
		}

		double res = 0.0;
		double r1 = max((double)r[0], (dist(x[1], y[1], x[2], y[2])+r[1]+r[2])/2);
		double r2 = max((double)r[1], (dist(x[2], y[2], x[0], y[0])+r[2]+r[0])/2);
		double r3 = max((double)r[2], (dist(x[0], y[0], x[1], y[1])+r[0]+r[1])/2);

		res = min(r1, min(r2, r3));

		cout << "Case #" << c+1 << ": ";
		cout.precision(7);
		cout << res << endl;
	}


	return 0;
}