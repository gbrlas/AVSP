#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <utility>

using namespace std;


#define llong long long 
const double pi = acos(-1.0);

const int N = 505;
char str[N][N];
int R,C,D,grid[N][N];
int row[N][N],col[N][N];
int rr[N][N],cc[N][N];

int solve(){
	int i,j,k;
	for(i = 0;i<R;i++){
		for(j = 0;j<C;j++){
			if(j==0)row[i][j] = grid[i][j]*j;
			else row[i][j] = grid[i][j]*j+row[i][j-1];
			
			if(i==0)col[i][j] = grid[i][j]*i;
			else col[i][j] = grid[i][j]*i+col[i-1][j];

			if(j==0)rr[i][j] = grid[i][j];
			else rr[i][j] = grid[i][j]+rr[i][j-1];

			if(i==0)cc[i][j] = grid[i][j];
			else cc[i][j] = grid[i][j]+cc[i-1][j];
		}
	}

	k = min(R,C);
	for(;k>=3;k--){
		for(i = 0;i+k<=R;i++){
			int t0 = 0,t10 = 0,t11 = 0,t2;
			for(j = 0;j<k;j++){
				t0 += rr[i+j][k-1];

				t10 += row[i+j][k-1];
				t11 += col[i+k-1][j];
				if(i>0)t11 -= col[i-1][j];
			}
			for(j = k-1;;j++){
				int tmp10 = j+(j-k+1);
				int tmp11 = i+(i+k-1);
				tmp10 *= (t0-grid[i][j-k+1]-grid[i][j]-grid[i+k-1][j-k+1]-grid[i+k-1][j]);
				tmp11 *= (t0-grid[i][j-k+1]-grid[i][j]-grid[i+k-1][j-k+1]-grid[i+k-1][j]);
				int tmp0 = t10,tmp1 = t11;
				//tmp0 -= grid[i][j-k+1]*(i+j-k+1)+grid[i][j]*(i+j)+grid[i+k-1][j-k+1]*(i+j)+grid[i+k-1][j]*(i+k-1+j);
				tmp1 -= grid[i][j-k+1]*(i)+grid[i][j]*(i)+grid[i+k-1][j-k+1]*(i+k-1)+grid[i+k-1][j]*(i+k-1);
				tmp0 -= grid[i][j-k+1]*(j-k+1)+grid[i][j]*(j)+grid[i+k-1][j-k+1]*(j-k+1)+grid[i+k-1][j]*(j);
				if(tmp10==2*tmp0 && tmp11==2*tmp1){
					return k;
				}
				if(j==C-1)break;

				t0 += cc[i+k-1][j+1];
				if(i>0)t0 -= cc[i-1][j+1];
				t2 = cc[i+k-1][j-k+1];
				if(i>0)t2 -= cc[i-1][j-k+1];
				t0 -= t2;
				
				t11 += col[i+k-1][j+1];
				if(i>0)t11 -= col[i-1][j+1];
				t11 -= col[i+k-1][j-k+1];
				if(i>0)t11 += col[i-1][j-k+1];

				t2 = cc[i+k-1][j+1];
				if(i>0)t2 -= cc[i-1][j+1];
				t10 += t2*(j+1);
				t2 = cc[i+k-1][j-k+1];
				if(i>0)t2 -= cc[i-1][j-k+1];
				t10 -= t2*(j-k+1);
			}
		}
	}
	return -1;
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,nc = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&R,&C,&D);
		for(i = 0;i<R;i++){
			scanf("%s",str[i]);
			for(j = 0;j<C;j++){
				grid[i][j] = str[i][j]-'0';
			}
		}
		int ans = solve();
		if(ans==-1)printf("Case #%d: IMPOSSIBLE\n",++nc);
		else printf("Case #%d: %d\n",++nc,ans);
	}
	return 0;
}