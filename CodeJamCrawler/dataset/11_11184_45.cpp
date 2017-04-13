#include <stdio.h>
#define ABS(a) ((a)>0?(a):(-(a)))
#define MIN(a,b) ((a)<(b)?(a):(b))
int n, in1[200];
char in0[200];
int ret;
int o, b;

void next(int i) {
	int j = i, min;
	for(; j < n; ++j) {
		if(in0[j] != in0[i]) break;
	}
	if(in0[i] == 'O') {
		min = ABS(in1[i] - o);
		o = in1[i];
	} else {
		min = ABS(in1[i] - b);
		b = in1[i];
	}
	min += 1;
	ret += min;
	if(j != n) {
		if(in0[j] == 'O') {
			min = MIN(min, ABS(in1[j] - o));
			if(in1[j] > o) o += min;
			else o -= min;
		} else {
			min = MIN(min, ABS(in1[j] - b));
			if(in1[j] > b) b += min;
			else b -= min;
		}
	}
}

int solve() {
	ret = 0;
	o = 1, b = 1;
	for(int i = 0; i < n; ++i) {
		//printf("%d %d %d %c %d\n", ret, o, b, in0[i], in1[i]);
		next(i);
	}
	return ret;
}
int main() {
	int t;
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%s %d", in0 + i, in1 + i);
		printf("Case #%d: %d\n", tt + 1, solve());
	}
	return 0;
}
/*
99
4 O 2 B 1 B 2 O 4
3 O 5 O 8 B 100
2 B 2 B 1
*/
