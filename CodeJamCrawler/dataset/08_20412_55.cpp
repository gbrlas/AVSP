#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Node {
public:
	int time;
	int station;
	bool isLeave;

	Node() {}
	Node(int time, int station, bool isLeave) : time(time), station(station), isLeave(isLeave) {}

	inline bool operator < (const Node & other) const {
		if (time == other.time) {
			return isLeave < other.isLeave;
		} else {
			return time < other.time;
		}
	}
};

inline int readTime() {
	int hh, mm;
	scanf("%d", &hh);
	while (getchar() != ':');
	scanf("%d", &mm);
	return hh * 60 + mm;
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int t;
		int na, nb;
		scanf("%d", &t);
		scanf("%d%d", &na, &nb);
		vector<Node> seq;
		seq.reserve((na + nb) * 2);
		for (int i = 0; i < na; i++) {
			int from = readTime();
			int to = readTime();
			seq.push_back(Node(from, 0, true));
			seq.push_back(Node(to + t, 1, false));
		}
		for (int i = 0; i < nb; i++) {
			int from = readTime();
			int to = readTime();
			seq.push_back(Node(from, 1, true));
			seq.push_back(Node(to + t, 0, false));
		}
		sort(seq.begin(), seq.end());
		int cnts[2] = {0, 0};
		int ans[2] = {0, 0};
		for (size_t i = 0; i < seq.size(); i++) {
			if (seq[i].isLeave) {
				if (cnts[seq[i].station] == 0) {
					ans[seq[i].station]++;
				} else {
					cnts[seq[i].station]--;
				}
			} else {
				cnts[seq[i].station]++;
			}
		}
		printf("Case #%d: %d %d\n", caseIndex, ans[0], ans[1]);
	}
	
	return 0;
}
