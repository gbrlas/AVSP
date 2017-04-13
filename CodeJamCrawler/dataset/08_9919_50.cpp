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
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


pair<int, int> getans(deque<pair<int, int> > &atob, deque<pair<int, int> > &btoa, int turn){
	int reta = 0;
	int retb = 0;

	sort(atob.begin(), atob.end());
	sort(btoa.begin(), btoa.end());

	int nwaitinga = 0;
	int nwaitingb = 0;
	map<int, int> readyata;
	map<int, int> readyatb;
	
	for(int t = 0; t < 3600; t++) {
		// first process arrived trains
		nwaitinga += readyata[t];
		nwaitingb += readyatb[t];
	
		while(atob.size() && atob.front().first == t){ // train needs to depart from a at time t
			pair<int, int> top = atob.front();
			atob.pop_front();
			nwaitinga--;
			if(nwaitinga < 0) reta = max(reta, abs(nwaitinga));
			readyatb[top.second+turn]++;
		}
		
		while(btoa.size() && btoa.front().first == t){ // train needs to depart from b at time t
			pair<int, int> top = btoa.front();
			btoa.pop_front();
			nwaitingb--;
			if(nwaitingb < 0) retb = max(retb, abs(nwaitingb));
			readyata[top.second+turn]++;
		}
	}
	
	
	return make_pair(reta, retb);
}


int main() {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	for(int cnt = 0; cnt < N; cnt++){
		int turn;
		getline(cin, s);
		turn = atoi(s.c_str());
		
		int na, nb;
		getline(cin, s);
		stringstream ss;
		ss << s;
		ss >> na >> nb;
		
		deque<pair<int, int> > atob;
		for(int i = 0; i < na; i++){
			getline(cin, s);
			int a, b, c, d;
			a = (s[0]-'0')*10 + (s[1]-'0');
			b = (s[3]-'0')*10 + (s[4]-'0');
			c = (s[6]-'0')*10 + (s[7]-'0');
			d = (s[9]-'0')*10 + (s[10]-'0');
			
			atob.push_back(make_pair(a*60+b, c*60+d));
		}
				
		deque<pair<int, int> > btoa;
		for(int i = 0; i < nb; i++){
			getline(cin, s);
			int a, b, c, d;
			a = (s[0]-'0')*10 + (s[1]-'0');
			b = (s[3]-'0')*10 + (s[4]-'0');
			c = (s[6]-'0')*10 + (s[7]-'0');
			d = (s[9]-'0')*10 + (s[10]-'0');
			
			btoa.push_back(make_pair(a*60+b, c*60+d));
		}
		pair<int, int> ans = getans(atob, btoa, turn);
		cout << "Case #" << (cnt+1)<<": " << ans.first << " " << ans.second << endl;
	}

}





