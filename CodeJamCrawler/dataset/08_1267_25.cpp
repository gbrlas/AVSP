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

const int Mod = 10007;

int dx[]={1,2};
int dy[]={2,1};

int f[111][111];
bool b[111][111];
int h,w,R;

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int T,tc=0;
    for(cin>>T;tc++<T;){
        printf("Case #%d: ",tc);
        memset(b,0,sizeof b);
        memset(f,0,sizeof f);
        cin>>h>>w>>R;
        f[1][1]=1;
        for(int i=0;i<R;++i){
            int x,y;
            cin>>x>>y;
            b[x][y]=true;
        }
        for(int i=1;i<=h;++i)
            for(int j=1;j<=w;++j){
                if(!b[i][j])
                    for(int k=0;k<2;++k){
                        int x=i-dx[k],y=j-dy[k];
                        if(x>0 && y>0)f[i][j]=(f[i][j]+f[x][y])%Mod;
                    }
            }
        cout<<f[h][w]<<endl;
    }
    return 0;
}
