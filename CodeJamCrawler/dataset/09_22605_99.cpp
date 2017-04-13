#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define clr(u) memset(u, 0, sizeof u)
int l, d, n;
int res;
int cmp(const void* a, const void* b) {
	char* aa = (char*) a;
	char* bb = (char*) b;
	for(int i = 0; i < l; i++) {
		if(aa[i] != bb[i])
			return aa[i] - bb[i];
	}
}
char word[26][11];
char str[261];
vector<char> com[11];
char cstr[11];
int it;
int main() {
	FILE* in;
	in = fopen("A-small-attempt1.in", "r");
	FILE* out;
	out = fopen("A-small.out", "w");
	fscanf(in, "%d%d%d", &l, &d, &n);
	for(int i = 0; i < d; i++) 
		fscanf(in, "%s", word[i]);
	qsort(word, d, sizeof(word[0]), cmp);
	for(int i = 1; i <= n; i++) {
		fscanf(in, "%s", str);
		for(int j = 0; j < l; j++)
			com[j].clear();
		int j = 0, k = 0, len = strlen(str);
		while(j < len) {
			if(str[j] != '(') {
				com[k].push_back(str[j]);
			} else {
				j++;
				while(str[j] != ')') {
					com[k].push_back(str[j]);
					j++;
				}
			}
			k++; j++;
		}
		res = 0;
		for(int j = 0; j < d; j++) {
			bool flag = true;
			for(int k = 0; k < l; k++) {
				flag = false;
				for(int a = 0; a < com[k].size(); a++)
					if(com[k][a] == word[j][k]) {
						flag = true;
						break;
					}
				if(!flag)
					break;
			}
			if(flag)
				res++;
		}
		fprintf(out, "Case #%d: %d\n", i, res);
	}
}