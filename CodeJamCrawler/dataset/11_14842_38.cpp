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

const int maxn=1003;
const int inf=1000000000;

int t,S,R,N;
double L,T;
struct cla{
	int x,y,v;
}ay[maxn];

inline bool cmp1(const cla &a,const cla &b){
	return a.v<b.v;
}

inline bool cmp2(const cla &a,const cla &b){
	return a.x<b.x;
}

inline double count(double L,double v){
	double t=min(L/double(R+v),T);
	T-=t;
	return (t+(L-t*(R+v))/double(S+v));
}

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

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>t;
	int i;
	for1(i,1,t){
		cin>>L>>S>>R>>T>>N;
		int j;
		for1(j,1,N){
			ay[j].x=get();
			ay[j].y=get();
			ay[j].v=get();
			L-=ay[j].y-ay[j].x;
		}
		sort(ay+1,ay+N+1,cmp1);
		double ans=count(L,0);
		for1(j,1,N){
			ans+=count(ay[j].y-ay[j].x,ay[j].v);
		}
		printf("Case #%d: %.10lf\n",i,ans);
	}
}
