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
#define maxn 100
int i,j,r,n,m,k;

int p[maxn][maxn];

int di[4][2]={
  1,0,0,1,1,1,1,-1
};

int main(){
    freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int ii,nn;
    scanf("%d",&nn);
    for(ii=1;ii<=nn;ii++){
        memset(p,0,sizeof(p));
        printf("Case #%d: ",ii);
        scanf("%d %d",&n,&m);
        char temp;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++){
            scanf(" %c",&temp);
            if(temp=='.')p[i][j]=1;
            if(temp=='R')p[i][j]=2;
            if(temp=='B')p[i][j]=4;
        }
        int last;
        for(i=1;i<=n;i++){
            last=n;
            for(j=n;j;j--)if(p[i][j]>1){
                r=p[i][j];
                p[i][j]=1;
                p[i][last]=r;
                last--;
            }
        }
        int x,y;
        int ans=0;
//        for(i=1;i<=n;i++){
//            for(j=1;j<=n;j++)printf("%d",p[i][j]);
//                    printf("\n");
//        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)if(p[i][j]>1){
                
                for(r=0;r<4;r++){
                    x=i,y=j;
                    for(k=1;k<m;k++){
                        x+=di[r][0];
                        y+=di[r][1];
                        if(p[x][y]!=p[i][j])break;
                    }
                    if(k==m){
                        ans|=p[i][j];
//                        printf("%d %d",p[i][j],ans);
                        break;
                    }
                }
            }
        }
        if(ans==0){
            printf("Neither\n");
        }
        if(ans==2){
            printf("Red\n");
        }
        if(ans==4){
            printf("Blue\n");
        }
        if(ans==6){
            printf("Both\n");
        }
        
    }

}
