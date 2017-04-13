#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cassert>

typedef long long int64;
typedef double real;

const int inf = 0x3f3f3f3f;

#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }

using namespace std;


string st[5100];

set<char> meat[32];

int main(){
	int l, d, n;
	scanf("%d%d%d", &l, &d, &n);
	for (int i = 0; i < d; i++)
		cin >> st[i];
	for (int _ = 0; _ < n; ++_){
		for (int i = 0; i < l; i++) meat[i].clear();
		string s;
		cin >> s;
		int curr = 0;
		for (int i = 0; i < l; i++){
			if (isalpha(s[curr])){
				meat[i].insert(s[curr]);
				++curr;
			}else{
				assert(s[curr] == '(');
				for (++curr; s[curr] != ')'; curr++)
					meat[i].insert(s[curr]);
				++curr;
			}
		}
		int cnt = 0;
		for (int i = 0; i < d; i++){
			bool ok = 1;
			for (int t = 0; t < l; t++)
				if (meat[t].find(st[i][t]) == meat[t].end())
					ok = 0;
			if (ok) ++cnt;
		}
		printf("Case #%d: %d\n", _ + 1, cnt);
	}
	return 0;
}
