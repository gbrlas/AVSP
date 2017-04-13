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

int n,m,a;

int det(int a,int b,int c,int d){ return a*d-b*c; }

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int tc=0,T;
    for(cin>>T;tc++<T;){
        printf("Case #%d: ",tc);
        cin>>n>>m>>a;
        for(int x1=-n;x1<=n;++x1)
            for(int x2=x1;x2<=n && (x2-x1)<=n;++x2)
                for(int y1=-m;y1<=m;++y1)
                    for(int y2=y1;y2<=m && (y2-y1)<=m;++y2){
                        int s=det(x1,x2,y1,y2);
                        if(s<0)s=-s;
                        if(s==a){
                            int x[]={0,x1,x2};
                            int y[]={0,y1,y2};
                            for(int i=0;i<3;++i){
                                if(x[i]<0){
                                    int dx=-x[i];
                                    for(int k=0;k<3;++k)
                                        x[k]+=dx;
                                }
                                if(y[i]<0){
                                    int dy=-y[i];
                                    for(int k=0;k<3;++k)
                                        y[k]+=dy;
                                }
                            }
                            printf("%d %d %d %d %d %d\n",x[0],y[0],x[1],y[1],x[2],y[2]);
                            goto C;
                        }
                    }
        puts("IMPOSSIBLE");
C:;
    }
    return 0;
}
