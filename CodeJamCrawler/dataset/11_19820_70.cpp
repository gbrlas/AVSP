#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef struct {
	char a, b, c;
}Tgabung;
typedef struct {
	char a, b;
}Thapus;
Thapus hapus[30];
Tgabung gabung[40];
vector<char> data;
int tc = 0;
inline void solve() {
	int C, D, N;
	int i, j;
	scanf("%d", &C);
	char tmp[105];
	for (i = 0; i < C; i++) {
		scanf("%s", tmp);
		gabung[i].a = tmp[0];
		gabung[i].b = tmp[1];
		gabung[i].c = tmp[2];
	}
	scanf("%d", &D);
	for (i = 0; i < D; i++) {
		scanf("%s", tmp);
		hapus[i].a = tmp[0];
		hapus[i].b = tmp[1];
	}
	scanf("%d", &N);
	scanf("%s", tmp);
	for (i = 0; i < N; i++) {
		data.push_back(tmp[i]);
		if (data.size() > 1) {
			/*
			for (j = 0; j < data.size(); j++)
				printf("%c ", data[j]);
			puts("");
			*/
			for (j = 0; j < C; j++) {
				int last1 = data.size() - 1;
				int last2 = data.size() - 2;
				if ((data[last1] == gabung[j].a && data[last2] == gabung[j].b) || (data[last1] == gabung[j].b && data[last2] == gabung[j].a)) {
					data.pop_back();
					data[last2] = gabung[j].c;
				}
			}
			bool ada[30];
			memset(ada, 0, sizeof ada);
			for (j = 0; j < data.size(); j++)
				ada[data[j] - 'A'] = true;
			for (j = 0; j < D; j++) {
				if (ada[hapus[j].a - 'A'] && ada[hapus[j].b - 'A']) {
					data.clear();
					break;
				}
			}
			/*
			for (j = 0; j < data.size(); j++)
				printf("%c ", data[j]);
			puts("");
			*/
		}
	}
	tc++;
	printf("Case #%d: ", tc);
	printf("[");
	for (i = 0; i < data.size(); i++) {
		printf("%c", data[i]);
		if (i < data.size() - 1)
			printf(", ");
		
	}
	puts("]");
	data.clear();
}

int main() {
	int jtc;
	scanf("%d", &jtc);
	while(jtc--) solve();
	return 0;
}
