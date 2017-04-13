#include <iostream>
using namespace std;

int main(int, char **){
	int t, x, a, b, k, r, i, j;
	cin >> t;
	for (x = 1; x <= t; ++x){
		cin >> a >> b >> k;
		if(a < k || b < k)
			r = a * b;
		else{
			r = k * (a + b - k);
			for(i = k; i < a; i ++)
				for(j = k; j < b; j ++)
					if((int)(i & j) < k)
						r ++;
		}
		cout << "Case #" << x << ": " << r << endl;
	}

	return 0;
}
