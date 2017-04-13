#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	int tc;
	cin>>tc;
	int count = 1;
	while (tc--)
	{
		double c,f,x;
		double penambah = 2.0;
		cin>>c>>f>>x;
		double ans = x/2.0;
		double waste = 0.0;
		while (true)
		{
			waste = waste + c/penambah;
			penambah += f;
			double temp = waste + (x/penambah);
			//cout<<temp<<endl;
			if (temp < ans)
				ans = temp;
			else
				break;
		}
		cout<<"Case #"<<count++<<": ";
		printf("%.7lf\n", ans);
	}
	return 0;
}

