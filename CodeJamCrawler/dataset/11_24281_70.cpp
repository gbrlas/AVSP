#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int T; cin >> T;
	for(int No = 1; No <= T; No++)
	{
		int N; cin >> N;
		int xsum = 0;
		int sum = 0;
		int _min = 10000000;
		for(int i = 0; i < N; i++)
		{
			int tmp; cin >> tmp;
			xsum ^= tmp;
			sum += tmp;
			_min = min(_min, tmp);
		}
		cout << "Case #" << No << ": ";
		if(xsum == 0)
			cout << sum - _min << endl;
		else
			cout << "NO" << endl;
	}
}
