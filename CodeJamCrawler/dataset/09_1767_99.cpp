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

typedef long long ll;
typedef pair<int,int> pii;

int W,H;
int a[128][128],F[128][128];
int dy[]={-1,0,0,1},dx[]={0,-1,1,0};

int f(int i,int j){
    int&res=F[i][j];
    if(res<0){
        int d,h=a[i][j];
        for(int k=0;k<4;++k){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0 && x<W && y>=0 && y<H && a[x][y]<h)h=a[x][y],d=k;
        }
        res=f(i+dx[d],j+dy[d]);
    }
    return res;
}

void Solve(){
    cin>>H>>W;
    for(int j=0;j<H;++j)
        for(int i=0;i<W;++i)
            scanf("%d",a[i]+j);
    memset(F,-1,sizeof F);
    for(int j=0,k='a';j<H;++j)
        for(int i=0;i<W;++i){
            bool sink=true;
            for(int k=0;k<4;++k){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 && x<W && y>=0 && y<H && a[x][y]<a[i][j])sink=false;
            }
            if(sink)F[i][j]=k++;
        }
    int m[128];
    memset(m,-1,sizeof m);
    for(int j=0,k='a';j<H;++j,cout<<endl)
        for(int i=0;i<W;++i){
            if(i)putchar(' ');
            int c=f(i,j);
            if(m[c]<0)m[c]=k++;
            putchar(m[c]);
        }
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d:\n",a);
    return 0;
}
