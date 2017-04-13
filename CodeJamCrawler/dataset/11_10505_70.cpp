#include <cstdio>
#include <utility>

#define trace(x...)

using namespace std;

int main() {
	int cases, casen = 1;
	int n, move, time;
	int onm, bnm, opos, bpos;
	char sht;
	bool moved;
	pair<char,int> moves[100];
	scanf("%d",&cases);
	while(casen++ <= cases) {
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			scanf("%c%c%d",&sht,&moves[i].first,&moves[i].second);
		}
		onm = n, bnm = n, opos = 1, bpos = 1;
		for(int i = 0; i < n; i++) {
			if(moves[i].first == 'O') {
				onm = i;
				break;
			}
		}
		for(int i = 0; i < n; i++) {
			if(moves[i].first == 'B') {
				bnm = i;
				break;
			}
		}
		trace(
			for(int i = 0; i < n; i++) {
				printf("(%c %d) ",moves[i].first,moves[i].second);
			}
			printf("\nonm=%d | bnm=%d\n",onm,bnm);
		)
		move = 0, time = 0;
		while(move < n) {
			moved = false;
			time += 1;
			if(opos < moves[onm].second) {
				opos += 1;
			} else if(opos > moves[onm].second) {
				opos -=1;
			} else if(move == onm) {
				moved = true;
				for(int i = onm+1; i < n; i++) {
					if(moves[i].first == 'O') {
						onm = i;
						break;
					}
				}
			}
			if(bpos < moves[bnm].second) {
				bpos += 1;
			} else if(bpos > moves[bnm].second) {
				bpos -=1;
			} else if(move == bnm) {
				moved = true;
				for(int i = bnm+1; i < n; i++) {
					if(moves[i].first == 'B') {
						bnm = i;
						break;
					}
				}
			}
			if(moved) {
				move += 1;
			}
		}
		printf("Case #%d: %d\n",casen-1,time);
	}
}
