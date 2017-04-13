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

const int INF = (int)1e8;



int main()
{
	int T;
	cin >> T;

	for(int test = 1; test <= T; test++)
	{
		int A, B , K;
		cin >>  A >> B >> K;

		int cnt = 0;
		for(int i = 0; i < A; i++)
			for(int j = 0; j < B; j++)
				if((i&j) < K)
					cnt++;

		cout <<  "Case #" << test << ": "; 
	
		cout << cnt << "\n";
		
	}


	return 0;
}