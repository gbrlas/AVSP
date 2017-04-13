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

#define X   first
#define Y   second

int f[15555];

void Add(int x,int s){
    for(x+=7000;x;x/=2)f[x]+=s;
}

int Sum(int x,int y){
    int res=0;
    for(x+=7000,y+=7000-1;x<=y;x=(x+1)/2,y=(y-1)/2){
        if(x&1)res+=f[x];
        if(~y&1)res+=f[y];
    }
    return res;
}

struct TT{
    int x,y,z;
    TT(int x,int y,int z):x(x),y(y),z(z){}
    TT(){}
};

bool operator<(const TT&a,const TT&b){ return a.x<b.x; }

typedef pair<int,int> pii;

int dx[]={+1,0,-1,0};
int dy[]={0,+1,0,-1};
int dir=0;

vector<int> cx[6666],cy[6666];

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int T,tc=0;
    for(cin>>T;tc++<T;){
        for(int i=0;i<6666;++i)cx[i].clear(),cy[i].clear();
        printf("Case #%d: ",tc);
        int L;cin>>L;
        string s;
        for(int i=0;i<L;++i){
            string p;int k;
            cin>>p>>k;
            for(;k>0;--k)s+=p;
        }
        vector<pii> p;
        int dir=0,x=3333,y=3333;
        for(int i=0;i<s.size();++i){
            p.push_back(pii(x,y));
            switch(s[i]){
                case 'F':
                    x+=dx[dir],
                    y+=dy[dir];
                    break;
                case 'L':dir=(dir+3)%4;break;
                case 'R':dir=(dir+1)%4;break;
            }
        }
        p.push_back(pii(x,y));
        p.erase(unique(p.begin(),p.end()),p.end());
        for(int i=0;i+1<p.size();++i){
            if(p[i].X==p[i+1].X){
                int z=p[i].Y<?p[i+1].Y;
                cx[z].push_back(p[i].X);
            }else {
                int z=p[i].X<?p[i+1].X;
                cy[z].push_back(p[i].Y);
            }
        }
        int res=0;
        vector<TT> e;
        for(int i=0;i<6666;++i){
            sort(cx[i].begin(),cx[i].end());
            sort(cy[i].begin(),cy[i].end());
            for(int j=1;j+1<cx[i].size();j+=2)
                res+=cx[i][j+1]-cx[i][j];
            for(int j=1;j+1<cy[i].size();j+=2)
                res+=cy[i][j+1]-cy[i][j],
                e.push_back(TT(cy[i][j],i,+1)),
                e.push_back(TT(cy[i][j+1],i,-1));
        }
        memset(f,0,sizeof f);
        sort(e.begin(),e.end());
        int q=0;
        for(int i=0;i<e.size();++i){
            x=e[i].x,y=e[i].y,dir=e[i].z;
            for(;q<x;++q)
                for(int j=1;j+1<cx[q].size();j+=2)
                    res-=Sum(cx[q][j],cx[q][j+1]);
            Add(y,dir);
        }
        for(;q<6666;++q)
            for(int j=1;j+1<cx[q].size();j+=2)
                res-=Sum(cx[q][j],cx[q][j+1]);
        cout<<res<<endl;
    }
    return 0;
}
