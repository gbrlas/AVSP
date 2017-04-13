#include<cstdio>
#include<algorithm>

#define MAX 1024
#define ERR 1e-9

using namespace std;

int n, x, y, casos;
int vis[MAX];
double w[MAX], k[MAX];

bool cmp(const double &a, const double &b){
	return a+ERR < b;
}

int ganha(double a){
	for(int i=0;i<n;i++){
		if(!vis[i] && cmp(a, k[i])){
			vis[i] = 1;
			return 0;
		}
	}
	return 1;
}

int main(){
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		printf("Case #%d: ", inst);
		scanf(" %d", &n);
		for(int i=0;i<n;i++) scanf(" %lf", &w[i]);
		for(int i=0;i<n;i++) scanf(" %lf", &k[i]);
		for(int i=0;i<n;i++) vis[i] = 0;
		sort(&w[0], &w[n], cmp);
		sort(&k[0], &k[n], cmp);
		
		// printf("\n");
		// for(int i=0;i<n;i++) printf(" %lf", w[i]); printf("\n");
		// for(int i=0;i<n;i++) printf(" %lf", k[i]); printf("\n");
		
		x = y = 0;
		for(int i=0;i<n;i++) x += ganha(w[i]);		
		for(int i=0;i<n;i++) if(cmp(k[y], w[i])) y++;
		printf("%d %d\n", y, x);
	}
	return 0;
}