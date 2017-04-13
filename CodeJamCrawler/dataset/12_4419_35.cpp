#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	int t, n;
	cin >> t;
	
	for(int qq=1; qq<=t; ++qq){
		int N, W, L;
		pair<int,int> r[1000];
		int x[1000], y[1000];
		
		bool flip=0;
		
		cin >> N >> W >> L;
	//	if(W<L) flip=1;
		
		for(int i=0; i<N; ++i){
			cin >> r[i].first;
			r[i].second = i;
		}
		sort(r, r+N);
		reverse(r, r+N);
		
		int pos = 0;
		bool first=1;
		
		int Y;
		
		while(pos < N){
			int ht = r[pos].first;
			
			if(first){
				x[r[pos].second] = y[r[pos].second] = 0;
				int X = r[pos].first;
				++pos;
				
				while(pos < N){
					int plac = X + r[pos].first;
					if(plac > W) break;
					x[r[pos].second] = plac;
					y[r[pos].second] = 0;
					X = plac + r[pos].first;
					++pos;
				}
				
				Y = ht;
			}
			else{
				x[r[pos].second] = 0;
				y[r[pos].second] = Y + r[pos].first;
				int X = r[pos].first;
				++pos;
				
				while(pos < N){
					int plac = X + r[pos].first;
					if(plac > W) break;
					x[r[pos].second] = plac;
					y[r[pos].second] = Y + r[pos].first;
					X = plac + r[pos].first;
					++pos;
				}
				
				Y += 2*ht;
			}
			
			first=0;
		}
		
		for(int i=0; i<N; ++i){
			if(x[i] > W || y[i] > L){
				cout << "AAA\n";
				system("pause");
			}
		}
		
		printf("Case #%d:", qq);
		for(int i=0; i<N; ++i){
			if(!flip) cout << ' ' << x[i] << ' ' << y[i];
			else cout << ' ' << y[i] << ' ' << x[i];
		}
		cout << '\n';
		
	}
	
	return 0;
}
