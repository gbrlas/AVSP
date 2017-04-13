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
char word[5001][16];
char str[401];
vector<char> com[16];
int main() {
	FILE* in;
	in = fopen("A-large.in", "r");
	FILE* out;
	out = fopen("A-large.out", "w");
	fscanf(in, "%d%d%d", &l, &d, &n);
	for(int i = 0; i < d; i++) 
		fscanf(in, "%s", word[i]);
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