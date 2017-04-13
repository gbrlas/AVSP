
// {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
// }}}

const int lmx=103,bmx=103;
char T[lmx][bmx],tl[lmx];
int L;
int y,x;

inline void pass_white(){
    int xo,yo;
    for(;;){
        xo=x,yo=y;
        while (x < tl[y] && T[y][x]==' ') x++;
        while((x == tl[y] && T[y][x]=='\n' || (!T[y][x])) && y < L){ y++; x=0;}
        if(y==L) break;
        if(xo==x && yo==y) break;
    }
}

char buf[bmx];

struct tree{
    LD val;
    string f;
    tree *l,*r;
    tree(){
        assert(y<=L);
        pass_white();
        x++; pass_white();
        int m=0;
        sscanf(T[y]+x,"%Lf%n",&val,&m);
        x+=m; pass_white();
        if(T[y][x] == ')'){
            x++;
            pass_white();
        }   
        else{
            int m=0;
            sscanf(T[y]+x,"%s%n",buf,&m);
            x+=m; pass_white();
            f=buf;
            l=new tree();
            r=new tree();
            pass_white();
            x++;
            pass_white();

        }
    }
};
set<string> S;

int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        y=x=0;

        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        scanf("%d\n",&L);
        REP(y,L) {gets(T[y]); tl[y]=strlen(T[y]);}
        tree *root=new tree();        
        fprintf(stderr," Drzewo zbudowane\n");
        int m;
        scanf("%d",&m);
        printf("Case #%d:\n",zz+1);
        while(m--){
            S.clear();
            scanf("%s",buf);
            int k;
            scanf("%d",&k);
            while(k--){
                scanf("%s",buf);
                S.insert(buf);
            }
            tree *now= root;
            LD res=1;
            for(;;){
                res*=now->val;
                if(now->f == "") break;
                if(S.find(now->f) == S.end()) now=now->r;
                else now=now->l;
            }
            printf("%.7Lf\n",res);
        }
    }
    return 0;
}
