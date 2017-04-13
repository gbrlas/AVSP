// GCJ_Q_B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n; cin >> n;
	int c = 1;
	int na, nb, t;
	while(n-- && cin >> t >> na >> nb){
		vector < pair<int, int> > a, b;
		int m, s, mm, ss; char ch;
		while(na-- && cin >> m >> ch >> s >> mm >> ch >> ss){
			a.push_back(make_pair(m*60 + s, 1));
			b.push_back(make_pair(mm*60 + ss + t, -1));
		}
		while(nb-- && cin >> m >> ch >> s >> mm >> ch >> ss){
			b.push_back(make_pair(m*60 + s, 1));
			a.push_back(make_pair(mm*60 + ss + t, -1));
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ma = 0, mb = 0, ca = 0, cb = 0;
		for(int i = 0; i < a.size(); i++){
			ca += a[i].second;
			if(ca > ma) ma = ca;
		}
		for(int i = 0; i < b.size(); i++){
			cb += b[i].second;
			if(cb > mb) mb = cb;
		}

		cout << "Case #" << c++ << ": " << ma << " " << mb << endl;
	}


	return 0;
}

