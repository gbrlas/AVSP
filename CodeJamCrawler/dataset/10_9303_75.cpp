#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>

using namespace std;
#define maxn 103
int i,j,r,n,m,k,D,I;

int p[maxn][300];

int q[maxn];

int myabs(int a){return a>0?a:-a;}

void fix(int a,int& b){
    if(a<b)b=a;
}

int mul(int a,int b){
    if(a==0)return 0;
    if(a%b==0)return a/b-1;
    return a/b;
}


int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int ii,nn;
    scanf("%d",&nn);
    for(ii=1;ii<=nn;ii++){
        
        printf("Case #%d: ",ii);
        scanf("%d %d %d %d",&D,&I,&m,&n);
        for(i=1;i<=n;i++)scanf("%d",&q[i]);
        memset(p,-1,sizeof(p));
        for(i=1;i<=n;i++){
            for(j=0;j<=255;j++){
                p[i][j]=(i-1)*D+myabs(j-q[i]);
            }
            if(i>1)for(j=0;j<=255;j++)if(p[i-1][j]>=0){

                //delete i
                fix(p[i-1][j]+D,p[i][j]);

                
                for(r=0;r<=255;r++){

                    //delete then insert

                    //insert before i then modify
                    if(m>0)
                    fix(p[i-1][j]+I*mul(myabs(j-r),m)+myabs(q[i]-r),p[i][r]);
                    

                    //modify
                    if(myabs(r-j)<=m){
                        fix(p[i-1][j]+myabs(q[i]-r),p[i][r]);
                    }
                }
                
            }
        }
        int ans=-1;
        for(i=0;i<=255;i++)if(ans<0||p[n][i]<ans)ans=p[n][i];
                printf("%d\n",ans);
        
    }

}
