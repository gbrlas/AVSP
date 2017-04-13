#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstring>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <ctime>
#include <complex>

#define for1(i,a,b) for(i=a;i<=b;i++)
#define for2(i,a,b) for(i=a;i>=b;i--)
//#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define FT first
#define SD second

using namespace std;

typedef long long LL;
typedef pair<int,int> PAIR;

const int maxn=503;
const int inf=1000000000;

int t,n,m,d,ans;
int ay[maxn][maxn];
LL X[maxn][maxn],Y[maxn][maxn],SX[maxn][maxn],SY[maxn][maxn],sum[maxn][maxn];

inline int get(){
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	int v=ch-48;
	ch=getchar();
	while (isdigit(ch)){
		v=v*10+ch-48;
		ch=getchar();
	}
	return v;
}

void work(){
	int i,j;
	for2(ans,min(n,m),3){
		for1(i,1,n-ans+1){
			for1(j,1,m-ans+1){
				LL tmp=sum[i+ans-1][j+ans-1]+sum[i-1][j-1]-sum[i-1][j+ans-1]-sum[i+ans-1][j-1]-ay[i][j]-ay[i][j+ans-1]-ay[i+ans-1][j]-ay[i+ans-1][j+ans-1];
				/*if (i==1 && j==1 && ans==4){
					cout<<!((tmp&1)&& !(ans&1))<<endl;
					cout<<SX[i+ans-1][j+ans-1]+SX[i-1][j-1]-SX[i-1][j+ans-1]-SX[i+ans-1][j-1]-X[i][j]-X[i][j+ans-1]-X[i+ans-1][j]-X[i+ans-1][j+ans-1]<<endl;
					cout<<tmp*(i+ans/2)<<endl;
				}*/
				if (!((tmp&1)&& !(ans&1))&& SX[i+ans-1][j+ans-1]+SX[i-1][j-1]-SX[i-1][j+ans-1]-SX[i+ans-1][j-1]-X[i][j]-X[i][j+ans-1]-X[i+ans-1][j]-X[i+ans-1][j+ans-1]==tmp*(i+ans/2)-((ans&1)^1)*tmp/2
					&& SY[i+ans-1][j+ans-1]+SY[i-1][j-1]-SY[i-1][j+ans-1]-SY[i+ans-1][j-1]-Y[i][j]-Y[i][j+ans-1]-Y[i+ans-1][j]-Y[i+ans-1][j+ans-1]==tmp*(j+ans/2)-((ans&1)^1)*tmp/2){
					return;
				}
			}
		}
	}
	ans=0;
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>t;
	int i,j,k;
	for1(i,1,t){
		cin>>n>>m>>d;
		getchar();
		memset(SX,0,sizeof(SX));
		memset(SY,0,sizeof(SY));
		memset(sum,0,sizeof(sum));
		LL tx,ty,tp;
		for1(j,1,n){
			tx=ty=tp=0;
			for1(k,1,m){
				ay[j][k]=(getchar()-48)+d;
				tp+=ay[j][k];
				X[j][k]=j*LL(ay[j][k]);
				Y[j][k]=k*LL(ay[j][k]);
				tx+=X[j][k];
				ty+=Y[j][k];
				SX[j][k]=SX[j-1][k]+tx;
				SY[j][k]=SY[j-1][k]+ty;
				sum[j][k]=sum[j-1][k]+tp;
			}
			getchar();
		}
		work();
		if (ans==0)printf("Case #%d: IMPOSSIBLE\n",i);else printf("Case #%d: %d\n",i,ans);
	}
}
