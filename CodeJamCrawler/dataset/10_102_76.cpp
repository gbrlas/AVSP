#include <iostream>

using namespace std;

int main(){
	int n, t, k;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cin >> n >> k;
		int y = (1 << n);
		++k ;
		cout << "Case #" << i << ": ";
		if (k % y == 0)
			cout << "ON" << endl;
		else
			cout << "OFF" << endl;			
	}
}