#include<cstdio>
#include<algorithm>

#define MAX 100100

using namespace std;

int n, casos, res, j, cap;
int v[MAX], vis[MAX];

int main(){
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		res = 0;
		scanf(" %d %d", &n, &cap);
		// mapa.clear();
		for(int i=0;i<n;i++){
			scanf(" %d", &v[i]);
			// if(mapa.count(v[i]) == 0) mapa[v[i]] = 0;
			// mapa[v[i]]++;
		}
		for(int i=0;i<n;i++) vis[i] = 0;
		sort(&v[0], &v[n]);
		
		j = n-1;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				while(j > i && (vis[j] == 1 || v[i]+v[j] > cap)) j--;
				if(j > i && vis[j] == 0 && v[i]+v[j] <= cap){
					vis[j] = vis[i] = 1;
					res++;
				}
				else{
					vis[i] = 1;
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", inst, res);
	}
	return 0;
}