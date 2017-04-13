#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>

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
#define set0(n) memset(n,0,sizeof 0)

int n,s,p,points[101];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,cas=0;
	scani(t);
	rep(t){
		int res=0;
		scani(n); scani(s); scani(p);
		fori(n) scani(points[i]);
		fori(n){
			int base = points[i]/3;
			switch(points[i]%3){
				case 0:
					//base,base,base
					//base, base-1, base+1
					if(base>=p)
						res++;
					else if(base+1 >= p && base>0 && s>0){
						res++; s--;
					}
					break;
				case 1:
					//base,base,base+1
					//base-1,base+1,base+1
					if(base >= p || base+1 >= p)
						res++;
					else if(base+1 >= p && s>0){
						res++; s--;
					}
					break;
				case 2:
					//base+1,base+1,base
					//base,base,base+2
					if(base>= p || base+1>=p)
						res++;
					else if(base+2>=p && s>0){
						res++; s--;
					}
			}
		}
		printf("Case #%d: %d\n",++cas,res);
	}
	return 0;
}