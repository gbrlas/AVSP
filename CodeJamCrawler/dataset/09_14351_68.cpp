#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }

typedef long long int64;
typedef double real;

using namespace std;

struct node{
	real w;
	string feature;
	int l, r;
};

node tree[1 << 20];
char s[1 << 20];
char buff[1 << 20];
int len;
int curr;
int cnt;

int new_node(){
	tree[cnt].l = tree[cnt].r = -1;
	assert(cnt < (1 << 20));
	return cnt++;
}

void skipBlank(){
	while (s[curr] && (isspace(s[curr]))){
		++curr;
	}
}
void skipNumber(){
	while (s[curr] && (isdigit(s[curr]) || s[curr] == '.')){
		++curr;
	}
}
void skipAlpha(){
	while (s[curr] && (isalpha(s[curr]))){
		++curr;
	}
}
int parseTree(){
	skipBlank();
	assert(s[curr] == '(');
	++curr;
	int res = new_node();
	skipBlank();
	sscanf(s + curr, "%lf", &tree[res].w);
	skipNumber();
	skipBlank();
	if (s[curr] == ')'){
		++curr;
		return res;
	}else{
		sscanf(s + curr, "%s", buff);
		tree[res].feature = buff;
		skipAlpha();
		tree[res].l = parseTree();
		tree[res].r = parseTree();
		skipBlank();
		assert(s[curr] == ')');
		++curr;
		return res;
	}
}

int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		printf("Case #%d:\n", _ + 1);
		int l;
		scanf("%d", &l);
		gets(s);
		len = 0;
		for (int i = 0; i < l; i++){
			gets(s + len);
			len += strlen(s + len);
			s[len++] = ' ';
		}
		s[len] = 0;
		curr = 0;
		cnt = 0;
		int root = parseTree();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			set<string> meat;
			string s;
			cin >> s;
			int k;
			scanf("%d", &k);
			for (int j = 0; j < k; j++){
				cin >> s;
				meat.insert(s);
			}
			int curr = root;
			real res = 1.;
			while (1){
				res *= tree[curr].w;
				if (tree[curr].l == -1) break;
				if (meat.find(tree[curr].feature) == meat.end())
					curr = tree[curr].r;
				else 
					curr = tree[curr].l;
			}
			printf("%.6lf\n", res);
		}
	}
	return 0;
}
