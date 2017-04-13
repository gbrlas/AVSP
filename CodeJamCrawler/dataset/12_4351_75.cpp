#include <iostream>

using namespace std;

bool f(int sum, int best, bool spec){
	for(int i=best; i<=10; ++i){
		for(int j=0; j<=i; ++j){
			for(int k=0; k<=j; ++k){
				if(i+j+k != sum) continue;
				if(spec && i-k != 2) continue;
				if(!spec && i-k >= 2) continue;
				
				return 1;
			}
		}
	}
	
	return 0;
}

int main(){
	int t;
	cin >> t;
	
	for(int q=1; q<=t; ++q){
		cout << "Case #" << q << ": ";
		
		int n, s, p;
		int spec=0, unspec=0, both=0;
		
		cin >> n >> s >> p;
		for(int i=0; i<n; ++i){
			int x;
			
			cin >> x;
			bool S = f(x, p, 1), U = f(x, p, 0);
			
			if(S && U) ++both;
			else if(S) ++spec;
			else if(U) ++unspec;
		}
		
		cout << unspec + both + min(spec, s) << '\n';
	}
	
	return 0;
}
