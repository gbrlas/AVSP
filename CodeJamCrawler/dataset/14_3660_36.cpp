#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <complex> 
#include <string>
#include <vector> 
#include <list>
#include <deque> 
#include <stack> 
#include <queue> 
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm> 
#include <numeric> 
#include <typeinfo> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <climits> 
#include <ctime>
using namespace std;

typedef __int64 ll;
typedef pair<int,int> P;

int t,r,c,m;
bool f;

int fie[9][9];
int res[9][9];
bool open[9][9];
int cc;

void ume(int x,int y){
	cc++;
	open[x][y]=true;
	bool flag=true;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(x+j<0 || x+j>=c || y+i<0 || y+i>=r)continue;
			if(fie[x+j][y+i]==1)flag=false;
		}
	}
	if(flag){
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(x+j<0 || x+j>=c || y+i<0 || y+i>=r)continue;
				if(!open[x+j][y+i] && fie[x+j][y+i]==0)ume(x+j,y+i);
			}
		}
	}
}

void dfs(int num,int cnt){
	if(f)return;
	if(cnt>m)return;
	if(num==r*c){
		if(cnt!=m)return;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(fie[j][i]==0){
					memset(open,false,sizeof(open));
					cc=0;
					ume(j,i);
					if(cc+m==r*c){
						f=true;
						for(int k=0;k<r;k++){
							for(int l=0;l<c;l++){
								res[l][k]=fie[l][k];
							}
						}
						res[j][i]=2;
						return;
					}
				}
			}
		}
		return;
	}
	fie[num%c][num/c]=0;
	dfs(num+1,cnt);
	fie[num%c][num/c]=1;
	dfs(num+1,cnt+1);
}

int main(void){
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		scanf("%d%d%d",&r,&c,&m);
		f=false;
		dfs(0,0);
		printf("Case #%d:\n",test);
		if(!f)printf("Impossible\n");
		else{
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(res[j][i]==0)printf(".");
					if(res[j][i]==1)printf("*");
					if(res[j][i]==2)printf("c");
				}
				printf("\n");
			}
		}
	}
	return 0;
}