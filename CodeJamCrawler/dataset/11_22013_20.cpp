#include <assert.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <set>

using namespace std;

bool isInteger(double d)
{
	if ((d - int(d)) < 0.000001 || (int(d+1) - d) < 0.000001)
		return true;
	else
		return false;
}


int main() {
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": ";
		int 	N, PD, PG;
		cin	>> N >> PD >> PG;
		assert(N > 0 && PG >= 0 && PG <= 100 && PD<= 100 && PD >= 0);
		bool	possible = false;
		int i;
		if (PG == 100 && PD < 100) {
					possible = false;
		} else if (PD == 0) {
			possible = true;
		} else if ( PG == 0) {
			possible = false;
		} else {
			double	rpd = PD / 100.0;
			for (i=1; i<= int (N*rpd + 0.000001); i++) {
				if (isInteger(i/rpd)) {
					possible = true;
//					cout << i << ", " << i/rpd << ". ";
					break;
				}
			}
		}
		cout << (possible ? "Possible" : "Broken") << endl;
	}
}
