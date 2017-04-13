#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fors(n) for(size_t i = 0 ; i < (n) ;i++)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define scani(n) scanf("%d",&n)
#define scanii(n,m) scanf("%d%d",&n,&m)
#define printi(n) printf("%d\n",n)
#define rep(n) while(n--)
#define set0(n) memset(n,0,sizeof n)

//f->z q==?
char alpha[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,cas=0;
	char G[110];
	scani(t);
	getchar();
	rep(t){
		gets(G);
		printf("Case #%d: ",++cas);
		for(int i = 0 ; char c=G[i];++i){
			if(isalpha(c))
				printf("%c",alpha[c-'a']);
			else printf("%c",c);
		}
		puts("");
	}
	return 0;
}
