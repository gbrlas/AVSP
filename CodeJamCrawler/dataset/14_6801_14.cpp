#include <vector>
#include <list>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
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
#include <string.h>

using namespace std;
#define mp make_pair
#define pp push_back
#define Sort(x) sort(x.begin(), x.end())
#define rep(i, x, y) for(int i = x; i < y; i++)
#define Rep(i, x, y) for(int i = x; i <= y; i++)
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long
#define all(v) v.begin(),v.end()
#define ii pair<int, int>
#define mem(x,v) memset(x,v,sizeof(x))


int main()
{
	freopen("out.o","w",stdout);
	freopen("in.i","r",stdin);

	int testC;
	cin>>testC;

	rep(t,0,testC)
	{
		double C,F,X,rate=2;
		cin>>C>>F>>X;
		double prev_res =1e8, new_res = X/rate,tmp=0;
		while(prev_res-new_res> 1e-8)
		{
			prev_res = new_res;
			tmp+= 1/rate;
			rate+=F;
			new_res = X/rate;
			new_res+= C*tmp;
		}
		printf("Case #%d: %.7f\n",t+1,prev_res);
	}
}