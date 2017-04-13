#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<double>::const_iterator Citer;
int main() {
	int t; cin >> t;
	for (int c = 1; c <= t; c++) {
		int n; cin >> n;
		vector<double> naomi(n),ken(n);
		for (int i = 0; i < n; i++) cin >> naomi[i];
		for (int i = 0; i < n; i++) cin >> ken[i];
		
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		vector<double> ken_copy = ken;
		
		int deceitful=0,honest=0;
		for (Citer it = naomi.begin(); it != naomi.end(); ++it) {
			//honest - report *it
			Citer response = lower_bound(ken.begin(),ken.end(),*it);
			if (response != ken.end()) {//ken can win
				ken.erase(response);
			} else {//naomi wins
				ken.erase(ken.begin());
				honest++;
			}
			
			//deceitful - if you can beat anything, beat it
			if (*it > *ken_copy.begin()) {//can beat something
				Citer tier = lower_bound(ken_copy.begin(),ken_copy.end(),*it);
				tier--;
				ken_copy.erase(tier);
				deceitful++;
			} else {//can't beat anything
				ken_copy.erase(ken_copy.end()-1);
				//lose to the bext
			}
		}
		
		cout << "Case #" << c << ": " << deceitful << " " << honest << endl;
	}
	return 0;
}

//0.186 0.300 0.389 0.557 0.832 0.899 0.907 0.959 0.992
//0.215 0.271 0.341 0.458 0.520 0.521 0.700 0.728 0.916