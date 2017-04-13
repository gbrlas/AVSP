#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<math.h>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert> 
#include <list>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i=0;i<n;i++)
#define fr2(i, a, n) for(i=a;i<n;i++)
#define mem(a, n) memset(a, n, sizeof(a))
int main() {
	int i, j, k;
	int l, d, n;
	scanf("%d %d %d", &l, &d, &n);
	vector <string> v;
	fr(i, d) {
		char a[10000];
		scanf("%s", a);
		string s;
		s = a;
		v.pb(s);
	}
	fr(k, n) {
		char a[10000];
		scanf("%s", a);
		string s = a;
		int ls = s.sz;
		bool present[20][28];
		mem(present, 0);
		int id = 0;
		fr(i, l) {
			//if(id==ls)
			//	break;
			if(s[id]=='(') {
				for(j=id+1;s[j]!=')' && j<ls;j++)
					present[i][s[j]-97] = 1;
				id = j + 1;
			}
			else {
				present[i][s[id]-97] = 1;
				id++;	
			}
		}
		int c = 0;
		fr(i, v.sz) {
		
			bool f = true;
			fr(j, v[i].sz) {
				if(present[j][v[i][j]-97]==0) {
					f = 0;
					break;
				}
			}
			if(f)
				c++;
		}
		printf("Case #%d: %d\n", k+1, c);
	}
	
		
}
