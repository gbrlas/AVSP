#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define INF 10000000

using namespace std;

int calc (int x, int &y) {

	int count = 0;
	while (y <= x) {
		if (y == 1) {
			return (INF);
		}
		y += y - 1;
		count++;
	}
	return (count);
}

int main()
{
	int i, j, k, t, p, l, m, n, x, y, z;
	freopen ("text.in", "r", stdin);
	freopen ("output.txt", "w", stdout); 

	cin >> p;

	for (k = 1; k <= p; k++) {
	
	cin >> t;
	cin >> n;

	vector <int> v;

	for (i = 0; i < n; i++) {
		cin >> m;
		v.push_back (m);
	}

	sort (v.begin(), v.end());

	//for (i = 0; i < n; i++) {
	//	cout << v[i] << "\t";
	//}
	
	i = 0;
	int count = 0;
	int max = INF;
	
	while (i < n) {
		//cout << "t = " << t << endl;
		if (v[i] < t) {
			t += v[i];
		}
		else {
			j = calc (v[i], t);
			//if (j > n - i) {
				//cout << "Case #" << k << ": " << count + n - i << endl;
			//	a[i] = count + n - i;
				//return 0;
			//}
			//else {
			if (j < n - i) {
				if (max >  count + j + n - i - 1) {
					max = count + j + n - i - 1;
				}
			}
			else {
				if (max >  count + n - i) {
					max = count + n - i;
				}
			}
			count += j;
			t += v[i];
			//}
		}
		i++;
	}

	if (max > count) {
		max = count;
	}

	cout << "Case #" << k << ": " << max << endl;

	}

	return 0;
}

