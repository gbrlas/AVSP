#include <iostream>
#include <vector>
using namespace std;

vector <int> mb;
vector <int> vtmp;

char dic[5010][20];
char wd[20][30];

inline void gobitit(char s[], char ln[], int &index) {
	int i = 0;
	if(ln[index] != '(') {
		s[i ++] = ln[index ++];
		s[i] = '\0';
	}
	else {
		index ++;
		while(ln[index] != ')') {
			s[i ++] = ln[index ++];
		}
		s[i] = '\0';
		index ++;
	}
}

inline void pull(char s[], const int &x) {
	int i, j, l = 0, n = mb.size();
	vtmp.clear();
	for(i = 0; i < n; i++) {
		for(j = 0; s[j] != '\0'; j++) {
			if(dic[mb[i]][x] == s[j]) {
				vtmp.push_back(mb[i]);
				break;
			}
		}
	}

	n = vtmp.size();
	mb.clear();
	for(i = 0; i < n; i++) {
		mb.push_back(vtmp[i]);
	}
}

int main()
{
	freopen("ACM.in", "r", stdin);
	freopen("ACM.out", "w", stdout);

	int l, d, n;
	char ln[1000];

	while(scanf("%d %d %d", &l, &d, &n) != EOF) {
		getchar();
		int i, j, k;
		for(i = 0; i < d; i++) {
			gets(dic[i]);
		}

		for(i = 0; i < n; i++) {
			gets(ln);
			int id = 0;

			mb.clear();
			for(j = 0; j < d; j++) {
				mb.push_back(j);
			}

			for(j = 0; j < l; j++) {
				gobitit(wd[j], ln, id);
				pull(wd[j], j);
			}
			printf("Case #%d: %d\n", i + 1, mb.size());
		}
	}

	return 0;
}