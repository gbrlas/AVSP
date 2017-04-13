#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define A first
#define B second
#define pb(x) push_back(x)
#define SIZE(x) x.size()
const int inf = 0x7fffffff;

char cmap[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char str[110];

int main(void) {
	freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	getchar(); 
	for(int tc = 0;tc < T;tc++) {
		gets(str);
		printf("Case #%d: ",tc+1);
		for(int i = 0;i < strlen(str);i++)
			if(str[i] == ' ') printf(" ");
			else printf("%c",cmap[str[i]-'a']);
		puts("");
	}
}
