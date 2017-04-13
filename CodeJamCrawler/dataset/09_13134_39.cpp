#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int T, N, len[50], ans, tmp[50];
char buf[50];

int encode(int * len) {
	int ans = 0;
	for (int i = 0; i < N; ++i)
		ans = ans * 10 + (len[i] + 1);
	return ans;
}

void decode(int code, int * len) {
	for (int i = N - 1; i >= 0; --i) {
		len[i] = (code % 10) - 1;
		code /= 10;
	}
}

bool valid() {
	for (int i = 0; i < N; ++i)
		if (len[i] > i)
			return false;
	return true;
}
map<int, int> val;
queue<int> q;

int solve() {
	int init = encode(len);
	val.clear();
	val[init] = 0;
	while (!q.empty())
		q.pop();
	q.push(init);
	while (!q.empty()) {
		int front = q.front(); q.pop();
		decode(front, len);
		if (valid())
			return val[front];
		int step = val[front];
		for (int i = 0; i < N - 1; ++i) {
			swap(len[i], len[i + 1]);
			int newCode = encode(len);
			if (val.find(newCode) == val.end()) {
				val[newCode] = step + 1;
				q.push(newCode);
			}
			swap(len[i], len[i + 1]);
		}
	}
	//printf("sz = %d\n", val.size());
	return -1;
       	/*
	int ans = 0;
	while (true) {
		bool f = false;
		for (int i = 0; i < N - 1; ++i)
			if (len[i] > i && len[i + 1] <= i) {
				swap(len[i], len[i + 1]);
				++ans; f = true;
				break;
			}
		if (!f) {
			bool succ = true;
			for (int i = 0; i < N; ++i)
				if (len[i] > i)
					succ = false;
			if (succ)
				break;
			for (int i = 0; i < N - 1; ++i)
				if (len[i] > i && len[i + 1] < len[i]) {
					swap(len[i], len[i + 1]);
					++ans; f = true;
					break;
			}
		}
		if (!f) {
			bool succ = true;
			for (int i = 0; i < N; ++i)
				if (len[i] > i)
					succ = false;
			if (succ)
				break;
			for (int i = 0; i < N - 1; ++i)
				if (len[i + 1] < len[i]) {
					swap(len[i], len[i + 1]);
					++ans; f = true;
					break;
				}
		}
		if (!f)
			break;
		for (int i = 0; i < N; ++i)
			printf("%d ", len[i]);
		printf("\n");
	}
	for (int i = 0; i < N; ++i)
		if (len[i] > i)
			printf("ERROR!\n");
	return ans;*/
}

int main() {
	scanf("%d", &T);
	for (int tId = 0; tId < T; ++tId) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%s", buf);
			len[i] = N - 1;
			while (len[i] >= 0 && buf[len[i]] == '0')
				--len[i];
		}
		printf("Case #%d: %d\n", tId + 1, solve());
	}
	return 0;
}

