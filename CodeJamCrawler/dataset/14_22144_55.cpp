#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef set<double>::const_iterator Citer;
int main() {
	int t; cin >> t;
	for (int c = 1; c <= t; c++) {
		int n; cin >> n;
		set<double> naomi, ken;
		for (int i = 0; i < n; i++) {double x; cin >> x; naomi.insert(x);}
		for (int i = 0; i < n; i++) {double x; cin >> x; ken.insert(x);}
		
		set<double> ken_copy = ken;
		
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
				Citer tier = ken_copy.end();
				tier--;
				ken_copy.erase(tier);
				//lose to the bext
			}
		}
		
		cout << "Case #" << c << ": " << deceitful << " " << honest << endl;
	}
	return 0;
}

//0.186 0.300 0.389 0.557 0.832 0.899 0.907 0.959 0.992
//0.215 0.271 0.341 0.458 0.520 0.521 0.700 0.728 0.916