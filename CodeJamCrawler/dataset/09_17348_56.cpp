#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

using namespace std;
#define PROBLEM "B"
#define SCALE "large"
#define IN_FILE PROBLEM"-"SCALE".in"
#define OUT_FILE PROBLEM"-"SCALE".out"

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main()
{
	freopen(IN_FILE, "r", stdin);
	freopen(OUT_FILE, "w", stdout);

	int i,j,k,l,m,n;
	cin>>n;
	rep(i,n)
	{
		string num;
		cin>>num;
		num = string("0")+num;
		next_permutation(num.begin(),num.end());
		rep(j,num.size()) {
			if(num[j]!='0') break;
		}
		if(j==num.size()) j--;
		printf("Case #%d: %s\n", i+1, num.c_str()+j);
	}
	return 0;
}
