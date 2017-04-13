#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

int n,m;
char s[16][16];

int p[144];

int P(int i){ return p[i]==i?i:p[i]=P(p[i]); }

struct state{
    short a[12];
    state(){ CL(a,0); }
    void add(int i,int j){
        a[i]|=1<<j;
    }
    bool connected(){
        vector<pii> c;
        REP(i,n)REP(j,m)
            if(a[i]&1<<j)c.pb(pii(i,j));
        REP(i,sz(c))p[i]=i;
        REP(j,sz(c))REP(i,j)
            if(abs(c[i].X-c[j].X)+abs(c[i].Y-c[j].Y)==1)
                p[P(i)]=P(j);
        REP(i,sz(c)) if(P(i)!=P(0)) return false;
        return true;
    }
    bool operator()(int i,int j){ return bool(a[i]&1<<j); }
    void cl(int i,int j){
        a[i]&=~(1<<j);
    }
    void print(){
        REP(i,n){
            REP(j,m)if(operator()(i,j))putchar('X'); else putchar('.');
            cout<<endl;
        }
    }
};

bool operator<(const state&a,const state&b){
    REP(i,12)if(a.a[i]!=b.a[i]) return a.a[i]<b.a[i];
    return false;
}

bool operator==(const state&a,const state&b){
    REP(i,12)if(a.a[i]!=b.a[i]) return false;
    return true;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void Solve(){
    cin>>n>>m;
    state S,T;
    REP(i,n){
        cin>>s[i];
        REP(j,m){
            if(s[i][j]=='o' || s[i][j]=='w')S.add(i,j);
            if(s[i][j]=='x' || s[i][j]=='w')T.add(i,j);
        }
//        cout<<s[i]<<endl;
    }
    set<state> B;
    queue<state> Q;
    Q.push(S); B.insert(S); 
//    S.print();
//    cout<<endl;
//    T.print();
//    cout<<endl;
    for(int step=0;sz(Q);++step)for(int ss=sz(Q);ss;ss--){
        S=Q.front(); Q.pop();
        if(S==T){
            cout<<step<<endl;
            return;
        }
//        S.print(); cout<<endl;
        bool c=S.connected();
        REP(i,n)REP(j,m)if(s[i][j]!='#' && !S(i,j)){
//            cout<<i<<' '<<j<<' '<<s[i][j]<<' '<<S(i,j)<<endl;
            REP(k,4){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && s[x][y]!='#' && S(x,y)){
                    int X=x+dx[k],Y=y+dy[k];
                    if(X>=0 && X<n && Y>=0 && Y<m && s[X][Y]!='#' && !S(X,Y)){
//                        cout<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<X<<' '<<Y<<endl;;
//        S.print(); 
                        S.cl(x,y);
                        S.add(X,Y);
//        S.print(); 
                        if((c || S.connected()) && !B.count(S)){
                            Q.push(S);
                            B.insert(S);
                        }
                        S.add(x,y);
                        S.cl(X,Y);
//        S.print(); cout<<endl;
                    }
                }
            }
        }
    }
    puts("-1");
}

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}
