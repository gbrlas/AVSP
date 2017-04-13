#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define M 26
int a[105], b[105];
char c[105];
vector<string> v;
bool multiply_and_check (int len) {
	
	memset(b, 0, sizeof(b));
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			b[i+j] += a[i]*a[j];
		}
	}
	int max_len = len+len-1;
	for (int i = 0; i < max_len; ++i) {
		if (b[i] < 10) continue;
		b[i+1] += b[i]/10;
		b[i] %= 10;
		if (i+1 == max_len) ++max_len;
	}
	/*for (int i = 0; i < max_len; ++i) {
		printf("%d", b[i]);
	}
	printf("\n");
	*/memset(c, 0, sizeof(c));
	for (int i = 0; i < max_len; ++i) {
		if (b[i] != b[max_len-i-1]) return 0;
		c[i] = b[i] + '0';
	}
	/*for (int i = 0; i < len; ++i) {
		printf("%d", a[i]);
	}
	printf(" ");
	
	printf("%s\n", c);
	*/v.push_back(string(c));
	return 1;
}
bool check (int depth) {
	for (int i = 0; i < depth; ++i) {
		a[depth+i] = a[depth-1-i];
	}
	bool has = multiply_and_check(depth*2);
	for (int i = 0; i < depth-1; ++i) {
		a[depth+i] = a[depth-2-i];
	}
	has |= multiply_and_check(depth*2-1);
	return has;
}
void permute (int depth = 0) {
	if (depth) {
		if (!check(depth)) return;
	}
	if (depth == M) return;
	for (int i = 0; i <= 2; ++i) {
		if (depth + i == 0) continue;
		a[depth] = i;
		permute(depth+1);
	}
	if (depth < 1) {
		a[depth] = 3;
		permute(depth+1);
	}
	return;
}
bool cmp (string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else {
		int l = a.length();
		for (int i = 0; i < l; ++i) {
			if (a[i] != b[i]) return a[i] < b[i];
		}
		return false;
	}
}
char str[105], str_a[105], str_b[105];
int n;
int main () {
	permute(0);
	//FILE* f = fopen("num.txt", "w");
	//printf("%d\n", v.size());
	//fprintf(f, "%d\n", v.size());
	sort(v.begin(), v.end(), cmp);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", str_a, str_b);
		int a = lower_bound(v.begin(), v.end(), string(str_a), cmp)-v.begin()-1;
		int b = upper_bound(v.begin(), v.end(), string(str_b), cmp)-v.begin()-1;
		printf("Case #%d: %d\n", i+1, b-a);
	}
	/*for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		fprintf(f, "%s\n", (*it).c_str());
	}
	fclose(f);*/
}