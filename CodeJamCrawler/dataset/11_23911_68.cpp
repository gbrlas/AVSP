#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<queue>
using namespace std;

int n,m,d;
const int N = 505;
int w[N][N];

double eps = 1e-8;

struct pt{
	double a,b;
	pt(double x=0, double y=0):a(x),b(y){}
	pt operator + (pt p){
		return pt(a+p.a, b+p.b);
	}
	pt operator - (pt p){
		return pt(a-p.a, b-p.b);
	}
	pt operator * (double x){
		return pt(a*x, b*x);
	}
};
pt sum[N][N];
pt pts[N][N];
double mass[N][N];

inline double ab(double x){
	if(x<0) return -x;
	return x;
}

char buf[N];
void solve(){
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1; i<=n; i++){
		scanf("%s",buf+1);
		//printf("buf %s\n",buf+1);
		for(int j=1; j<=m; j++) {
			w[i][j]=buf[j]-'0';
		}
	}
	for(int i=0; i<=n; i++) mass[i][0] = 0;
	for(int j=0; j<=m; j++) mass[0][j] = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			pts[i][j] = pt(i*w[i][j], j*w[i][j]);

			sum[i][j]= sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1] + pts[i][j];

			mass[i][j] = mass[i-1][j]+mass[i][j-1]-mass[i-1][j-1]+w[i][j];
			//printf("%d %d) adding %d\n",i,j,w[i][j]);
		}
	}

	/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ", w[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			printf("%.1lf ", mass[i][j]);
		}
		printf("\n");
	}
	*/
	for(int k=min(n,m); k>=3; k--){
		for(int i=1; i+k-1<=n; i++){
			for(int j=1; j+k-1<=m; j++){
				//printf("trying %d %d, k %d\n",i,j,k);
				pt s = sum[i+k-1][j+k-1] - sum[i-1][j+k-1] - sum[i+k-1][j-1] + sum[i-1][j-1];
				s = s - pts[i][j+k-1] - pts[i][j] - pts[i+k-1][j+k-1] - pts[i+k-1][j];

				double act_mass = mass[i+k-1][j+k-1] - mass[i-1][j+k-1] - mass[i+k-1][j-1]
					+ mass[i-1][j-1];
				act_mass = act_mass - w[i][j] - w[i+k-1][j] - w[i][j+k-1] - w[i+k-1][j+k-1];

				pt sr = pt(i+k/2.-0.5, j+k/2.-0.5);
				pt res = s - sr*act_mass;
				//printf("srodek %lf %lf\n", sr.a, sr.b);
				//printf("act mass %d\n",act_mass);

				//printf("s %lf %lf\n",s.a,s.b);
				//printf("res %lf %lf\n",res.a,res.b);
				
				if(ab(res.a)<eps && ab(res.b)<eps){
					printf("%d\n",k);
					return;
				}
			}
		}
	}
	printf("IMPOSSIBLE\n");
}

main(){
	int T;
	scanf("%d",&T);
	for(int testcase=1; testcase<=T; testcase++){
		printf("Case #%d: ",testcase);
		solve();
	}
	return 0;
}
