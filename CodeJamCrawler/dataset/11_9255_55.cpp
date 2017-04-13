#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define FOR(i,s,n) for(int(i)=(s);(i)<(n);(i)++)
#define DFOR(i,s,n) for(int(i)=(s);(i)>(n);(i)--)
#define SZ(v) (int)(v).size()
#define RESET(v,n) memset((v),(n),sizeof((v)))
#define PII pair<int,int>
#define PFF pair<double,double>
#define eps 1e-8
#define isEQF(f,a) (abs((f)-(a)) < eps)
#define LL long long
#define DEBUG puts("OK")
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
using namespace std;

int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

inline void OPEN(string s) {
	freopen((s+ ".in").c_str(), "r",stdin );
	freopen((s+".out").c_str(), "w",stdout);
}


int main() {
	int n;
	int k = 0;
	scanf("%d", &n);
	while (k++<n){
		
		int seq[2][110];
		int allmove[110];
		int whomove[110];
		int line;
		int now[2] = {0,0};
		
		scanf("%d",&line);
		FOR(i,0,line){
			char who;
			int where;
			
			scanf("%*c%c %d",&who,&where);
			// cout << who << " " << where << " ";
			allmove[i] = where;
			if (who == 'B') whomove[i] = 1;
			else if (who=='O') whomove[i] = 0;
			 //= ((who=='B')?1:0);  // b = 1 o = 0
			// cout << i <<" " <<whomove[i] << endl;
			seq[whomove[i]][now[whomove[i]]++] = where;
		}
		
		int time = 0;
		int pos[2] = {1,1};
		now[0] = 0;
		now[1] = 0;
		
		FOR(i,0,line) {
			// cout << i << endl;
			int who = whomove[i];
			int where = seq[who][now[who]];
			int move = 0;
			// cout << "who = " << who << " where = " << where << " now = " << now[who] << endl;
			// first bot move
			move = where-pos[who];
			
			time += abs(move);
			// cout << who << " from " << pos[who] ;
			pos[who] += move;
			now[who] += 1;
			// cout << " move to " << pos[who] << endl;
			// other bot move <= first bot move
			who = (whomove[i]+1)%2;
			where = seq[who][now[who]];
			// cout << who << " from " << pos[who];
			if (abs(move)<abs(where-pos[who])) {
				if (where-pos[who]<0) move = (abs(move)*-1)-1;
				else move = abs(move)+1;
				// if (move<0) move-=1;
				// else move+=1;
			} else {
				move = where-pos[who];
			}
			pos[who] += move;
			//now[who] += 1;
			// first bot push button
			// cout << " move to " << pos[who] << endl;
			// cout << endl;
			time++;
		}
		
		printf("Case #%d: %d\n",k, time);
	}
	return 0;
}
