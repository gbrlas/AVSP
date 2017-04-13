#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int caseNum;
	cin >> caseNum;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int p, q;
		cin >> p >> q;
		vector<int> arr(q);
		for (int i = 0; i < q; i++) {
			cin >> arr[i];
			arr[i]--;
		}
		sort(arr.begin(), arr.end());
		int ans = p * q;
		do {
			int cur = 0;
			for (int i = 0; i < q; i++) {
				int left = -1, right = p;
				for (int j = 0; j < i; j++) {
					if (arr[j] < arr[i]) {
						left = max(left, arr[j]);
					} else if (arr[j] > arr[i]) {
						right = min(right, arr[j]);
					}
				}
				cur += arr[i] - left - 1;
				cur += right - arr[i] - 1;
			}
			ans = min(ans, cur);
		} while (next_permutation(arr.begin(), arr.end()));
		cout << "Case #" << caseIndex << ": " << ans << endl;
	}

	return 0;
}
