#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int lz;
	scanf("%d", &lz);
	for ( int test = 1; test <= lz; test++){
		int l, t, n, c;
		scanf("%d %d %d %d", &l, &t, &n, &c);
		vector<int> dist(c);
		for ( int i = 0; i < c; i++) scanf("%d", &dist[i]);
		
		ll sum = 0;
		vector<int> elim;
		for ( int i = 0; i < n; i++){
			if ( sum >= t ){
				elim.push_back(dist[i%c]);
			}
			else if ( sum < t && sum + 2*dist[i%c] >= t )
			{
				elim.push_back(((sum+2*dist[i%c]) - t)/2);
			}
			
			sum += 2*dist[i%c]; 
		}
		
		sort(elim.rbegin(), elim.rend());
		//printf("sum: %lld\n", sum);
		int take = min(l, (int)elim.size());
		for ( int i =0; i < take; i++){
			sum -= elim[i];
			//printf("eliminating: %d\n", elim[i]);
		}
		
		printf("Case #%d: %lld\n", test, sum);
	}
	return 0;
}
