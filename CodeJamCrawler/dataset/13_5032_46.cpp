#include <iostream>

using namespace std;

int main(){
	int cases;
	long long r, t;
	
	cin >> cases;
	for(int q=1; q<=cases; ++q){
		cin >> r >> t;
		cout << "Case #" << q << ": ";
		
		int rings=0;
		while(1){
			if(t < 2*r + 1){
				break;
			}
			t -= 2*r + 1;
			r += 2;
			++rings;
		}
		
		cout << rings << '\n';
	}
	
	return 0;
}
