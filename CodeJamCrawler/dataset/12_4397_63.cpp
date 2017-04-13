#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

long long x[500];
int n;

void pr(int s){
	int T=s;
	bool f=0;
	for(int i=0; i<n; ++i){
		if(T%2){
			if(f) cout << ' ' << x[i];
			else cout << x[i];
			f=1;
		}
		T >>= 1;
	}
	cout << '\n';
}

int main(){
	int t;
	cin >> t;
	
	for(int qq=1; qq<=t; ++qq){
		printf("Case #%d:\n", qq );
		
		cin >> n;
		
		for(int i=0; i<n; ++i){
			cin >> x[i];
		}
		
		bool imp=1;
		
		map<long long, int> m;
		for(int s=0; s<(1<<n); ++s){
			long long z=0;
			
			int T=s;
			for(int i=0; i<n; ++i){
				if(T%2) z+=x[i];
				T >>= 1;
			}
			
			map<long long, int>::iterator mi = m.find(z);
			
			if(mi != m.end()){
				pr(s);
				pr(mi->second);
				imp=0;
				break;
			}
			
			m[z] = s;
		}
		
		if(imp) cout << "Impossible\n";
		
	}
	
	return 0;
}
