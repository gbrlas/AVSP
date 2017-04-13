#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, k, r;
int g[1100];
long long ac[1100];
int cont[1010];

bool read(){
	scanf("%d%d%d",&r, &k, &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &g[i]);
}

int caso = 1;
void process(){
	long long sum = 0;
	int pos = 0;
	
	for(int i = 0; i < n; i++)
		ac[i] = -1;
	int t = 0;
	
	while(r > 0 && ac[pos] == -1){
		ac[pos] = sum;
		cont[pos] = t;
		long long at = 0;
		int posi = pos;
		while(at + g[pos] <= k){
			at += g[pos];
			pos++;
			if(pos == n)pos = 0;
			
			if(pos == posi)break;
		}
		sum += at;
		r--;
		t++;
	}
	if(r > 0){
		sum += (sum - ac[pos])*(r/(t - cont[pos]));
		r %= (t - cont[pos]);
		while(r > 0){
			long long at = 0;
			int posi = pos;
			while(at + g[pos] <= k){
				at += g[pos];
				pos++;
				if(pos == n)pos = 0;
				
				if(pos == posi)break;
			}
			sum += at;
			r--;			
		}
	}
	printf("Case #%d: %I64d\n", caso++, sum);
}

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		read();
		process();
	}
	
	return 0;
}