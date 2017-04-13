#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define A first
#define B second
#define pb(x) push_back(x)
#define SIZE(x) x.size()
const int inf = 0x7fffffff;

string ctostr(char c) {
	stringstream ss; ss << c; return ss.str();
}

map<string,bool> M;

int main(void) {
	freopen("output.txt","w",stdout);
	string numa, numb;
	int t; scanf("%d",&t);
	for(int tc = 0;tc < t;tc++) {
		int cnt = 0;
		bool f = 0;
		int A, B; scanf("%d %d",&A,&B);
		for(int a = A;a <= B;a++) {
			int ta = a, tb = b;
			numa=""; numb="";
			while(ta) {	numa += ctostr(ta%10+'0'); ta /= 10;	}
			reverse(numa.begin(),numa.end());
			
			for(int i = 1;i < SIZE(numa);i++) {
//					cout << numa << " " << numa.substr(0,i)+numa.substr(i,SIZE(numa)-i+1) << endl;
				int chk = sti(numa.substr(i,SIZE(numa)-i+1)+numa.substr(0,i));
				if(a < chk && A<=chk && chk <= B && !) {
					cnt++; break;
				}
			}
		}	
		printf("Case #%d: %d\n",tc+1,cnt);
	}
	return 0;
}
