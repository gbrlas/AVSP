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
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

#define SZ(a) (int)(a).size()
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define INF (int)1e9

#define ll long long
#define vi vector<int>
#define vs vector<string>

using namespace std;


int main()
{
	int T;
	cin >> T;
	
	for(int cas = 1; cas <= T; cas++)
	{
		string num;
		cin >> num;
		
		if(next_permutation(ALL(num)))
			cout << "Case #" << cas << ": " << num << endl;
		else
		{
			num += "0";
			sort(ALL(num));
			
			int cnt = 0, i = 0;
			while(num[0] == '0')
			{
				cnt++;
				num.erase(num.begin());
			}
			num.insert(1, cnt, '0');
			cout << "Case #" << cas << ": " << num << endl;
		}
	}
		
	return 0;
}
