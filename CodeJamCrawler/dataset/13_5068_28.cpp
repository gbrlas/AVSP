#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

int main(){
	int cases;
	cin >> cases;

	for(int qq=1; qq<=cases; ++qq){
		cout << "Case #" << qq << ": ";
		ll N, P;
		cin >> N >> P;

		ll rk=0, g=(1<<N)-1, o=(1<<N)-1;
		for(int i=0; i<N; ++i){
			rk += 1 << (N-i-1);
			if(rk >= P){
				g = (1<<i+1) - 2;
		//		cout << g << '\n';
				break;
			}
		}

		rk = 0;
		ll x=0;
		for(int i=0; i<N; ++i){
			rk += (1<<i);
			if(rk >= P){
				o = x;
				break;
			}
			
			x += 1 << (N-i-1);
		}

		cout << g << ' ' << o;
		cout << '\n';
	}
	return 0;
}