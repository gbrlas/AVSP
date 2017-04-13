#include<cstdio>
#include<map>
#include<vector>
#include<deque>

#define trace(x...) 

using namespace std;

int value(char c) {
	if(c == 'Q') return 1;
	if(c == 'W') return 2;
	if(c == 'E') return 3;
	if(c == 'R') return 4;
	if(c == 'A') return 5;
	if(c == 'S') return 6;
	if(c == 'D') return 7;
	if(c == 'F') return 8;
	return 0;
}

int main() {
	int cases, casen = 0;
	int c, d, n;
	char c1, c2, c3;
	scanf("%d",&cases);
	while(casen++ < cases) {
		char comb[9][9];
		bool opp[9][9];
		int conts[9];
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				comb[i][j] = 0;
				opp[i][j] = 0;
			}
			conts[i] = 0;
		}
		scanf("%d",&c);
		for(int i = 0; i < c; i++) {
			scanf(" %c%c%c",&c1,&c2,&c3);
			comb[value(c1)][value(c2)] = c3;
			comb[value(c2)][value(c1)] = c3;
		}
		scanf("%d",&d);
		for(int i = 0; i < d; i++) {
			scanf(" %c%c",&c1,&c2);
			opp[value(c1)][value(c2)] = 1;
			opp[value(c2)][value(c1)] = 1;
		}
		scanf("%d ",&n);
		deque<char> stk;
		for(int i = 0; i < n; i++) {
			scanf("%c",&c1);
			trace(
				printf("#%d: [",casen);
				int ii = 0;
				while(ii < stk.size()) {
					printf("%c",stk[ii++]);
					if(ii < stk.size()) {
						printf(", ");
					}
				}
				printf("] << %c\n",c1);
			)
			if(stk.empty()) {
				stk.push_back(c1);
				conts[value(c1)] += 1;
			} else {
				c2 = comb[value(stk.back())][value(c1)];
				if(c2) {
					conts[value(stk.back())] -= 1;
					stk.pop_back();
					stk.push_back(c2);
				} else {
					bool pooped = false;
					for(int j = 1; j < 9; j++) {
						if(conts[j] && opp[j][value(c1)]) {
							stk = deque<char>();
							pooped = true;
							for(int i = 0; i < 9; i++) {
								conts[i] = 0;
							}
							break;
						}
					}
					if(!pooped) {
						stk.push_back(c1);
						conts[value(c1)] += 1;
					}
				}
			}
		}
		printf("Case #%d: [",casen);
		while(stk.size()) {
			c1 = stk.front();
			stk.pop_front();
			printf("%c",c1);
			if(stk.size()) {
				printf(", ");
			}
		}
		printf("]\n");
	}
}
