#include <vector>
#include <list>
#include <map>
#include <set>
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

#define SZ(a) (int)(a).size()
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define INF (int)1e9

#define ll long long
#define vi vector<int>
#define vs vector<string>

using namespace std;

int memo[101][31];
string ip, wel;

int solve(int p1, int p2)
{
	//cout << p1 << " " << p2 << endl;
	if(p1 < p2)
		return 0;

	if(memo[p1][p2] != -1)
		return memo[p1][p2];

	if(p2 == 0)
	{
		int ret = 0;
		for(int i = 0; i <= p1; i++)
			if(ip[i] == wel[p2])
				ret++;
		return memo[p1][p2] = ret;
	}
	
	if(ip[p1] != wel[p2])
		return memo[p1][p2] = solve(p1 - 1, p2) % 1000;
	else
	{
		//cout << "here";
		memo[p1 - 1][p2] = solve(p1 - 1, p2) % 1000;
		memo[p1 - 1][p2 - 1] = solve(p1 - 1, p2 - 1) % 1000;
		return memo[p1][p2] = (memo[p1 - 1][p2] + memo[p1 - 1][p2 - 1]) % 1000;
	}

}

int main()
{
	int N;
	cin >> N;
	wel = "welcome to code jam";
	cin.ignore();
	
	for(int cas = 1; cas <= N; cas++)
	{
		memset(memo, -1, sizeof(memo));
		char ipp[501];
		
		cin.getline(ipp, 501);
		ip = ipp;
		
		int ret = solve(SZ(ip) - 1, SZ(wel) - 1);
	
		printf("Case #%d: %04d\n", cas, (ret == -1 ? 0 : ret));
	}
	
	return 0;
}
