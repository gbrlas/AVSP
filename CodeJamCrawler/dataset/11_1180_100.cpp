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

const int N = 105;
struct Node{
	char str[2];
	int val;
}node[N];

int grid[N][N];
int n;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,nc = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n++;
		for(i = 1;i<n;i++){
			scanf("%s%d",node[i].str,&node[i].val);
		}
		memset(grid,-1,sizeof(grid));
		for(i = 1;i<n;i++){
			grid[0][i] = node[i].val;
			for(j = i+1;j<n;j++){
				if(node[i].str[0]!=node[j].str[0]){
					grid[i][j] = 1;
				}else{
					grid[i][j] = abs(node[i].val-node[j].val)+1;
				}
			}
		}
		for(k = 0;k<n;k++){
			for(i = 0;i<n;i++){
				for(j = 0;j<n;j++){
					if(grid[i][k]!=-1 && grid[k][j]!=-1){
						if(grid[i][j]==-1 || grid[i][j]<grid[i][k]+grid[k][j]){
							grid[i][j] = grid[i][k]+grid[k][j];
						}
					}
				}
			}
		}
		int ans = grid[0][n-1];
		printf("Case #%d: %d\n",++nc,ans);
	}
	return 0;
}