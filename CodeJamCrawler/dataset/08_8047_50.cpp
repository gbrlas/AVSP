#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef vector<int> vi; 
typedef vector<string> vs;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define rep(i, n) for(int i = 0; i < n; ++i) 
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it) 
#define INT_INF 0x7FFFFFFF 

main() {
	int N;
	int saida = 1;
	scanf("%d", &N);
	vector<string > v;
	
	while(saida <= N) {
		int T;
		scanf("%d", &T);
		char dum;
		scanf("%c", &dum);
		rep(i,T) {
			string s = "";
			char buff;
			scanf("%c", &buff);
			
		//	if ( buff == '\n') {
		//		i--;
		//		continue;
		//	}
				
			while(buff != '\n') {
				s += buff;
				scanf("%c", &buff);
			}
			//printf("string lida: %s\n", s.c_str());
			v.pb(s);
		}
		//printf("\n\nacabaram strings\n\n");
		scanf("%d", &T);
		//printf("\n\n novo T: %d", T);
		vector<int> hits(v.size());
		int hit = 0;
		int switches = 0;
		string s;
		scanf("%c", &dum);
		rep(i,T) {
			char buff;
			scanf("%c", &buff);
			
			s="";
			//if ( buff == '\n') {
			//	i--;
			//	continue;
			//}
			
			while(buff != '\n') {
				s+=buff;
				scanf("%c", &buff);
			}
			
			rep(j, v.size()) {
				if (s == v[j]) {
					//printf("\n\ns==v[j]  %s\n\n", v[j].c_str());
					if (hits[j] != 1) hit++;
					hits[j] = 1;
					
					break;
				}
			}
			
			
			if (hit == v.size()) {
				switches++;
				rep(j,hits.size()) {
					hits[j] = 0;
				}
				hit = 0;
				//printf("switchou %d\n", i);
				rep(j, v.size()) {
					if (s == v[j]) {
						//printf("\n\ns==v[j]  %s\n\n", v[j].c_str());
						if (hits[j] != 1) hit++;
						hits[j] = 1;
						
						break;
					}
				}
			}
		}
		//if (hit > 0) switches++;
		
		printf("Case #%d: %d\n", saida++, switches);
		v.clear();
	}
	
}


// Powered by FileEdit
// Powered by moj 4.1 [modified TZTester]
// Powered by CodeProcessor

 