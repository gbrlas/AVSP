#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>

using namespace std;

int pd[510][20];
char text[510];
string pattern = "welcome to code jam";

int go(int pos, int p){
	if(p == 19){
		return 1;
	}
	if(text[pos] == 0){
		return 0;
	}
	int t = 0;
	if(pd[pos][p] != -1){
		return pd[pos][p];
	}
	if(text[pos] == pattern[p]){
		t = go(pos+1,p+1);
	}
	t += go(pos+1,p);
	t %= 10000;
	pd[pos][p] = t;
	return t;
}

int main(){
	
	freopen("data.in","r", stdin);
	freopen("data.out","w", stdout);
	int casos;
	
	scanf("%d", &casos);
	gets(text);
	for(int i = 1; i <= casos; i++){
		printf("Case #%d: ", i);
		gets(text);
		memset(pd,-1,sizeof(pd));
		printf("%04d\n", go(0,0));
	}
	
	
	return 0;
}
