#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <fstream>
#include <string>
//#include <windows.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define repk(i,k,n) for(int i = k; i < n; i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define clearqueue(x) while(!x.empty()) x.pop();
#define clearvector(arr,n) rep(i,n)arr[i].clear();

int po[32];
void calcPow(){
	po[0] = 1;
	rep(i,30)
		po[i+1] = po[i] * 2;
}

int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");
//	ios_base::sync_with_stdio(0);
//	long long begin = GetTickCount();
//	long long end = GetTickCount();
//	include <window.h>
	int casenum = 1;

	int t, n, b, oloc, bloc, rsec, till, diff, tillb, tillo;
	char c, prev = 0;
	cin >> t;
	while(t--){
		cin >> n;

		oloc = bloc = 1;
		rsec = till = tillb = tillo = 0;
		rep(i,n){
			cin >> c >> b;

			if(c == 'O'){
				if(prev != c) rsec = till - tillo;
				else rsec = 0;
				diff = abs(oloc - b) + 1;
				oloc = b;
				till += max(1, diff-rsec);
				tillo = till;
				prev = c;
			} else {
				if(prev != c) rsec = till - tillb;
				else rsec = 0;
				diff = abs(bloc - b) + 1;
				bloc = b;
				till += max(1, diff-rsec);
				tillb = till;
				prev = c;
			}
		}
		cout << "Case #" << casenum++ << ": " << till << endl;
	}


}



