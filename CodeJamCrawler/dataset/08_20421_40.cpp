#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

const int MAXN = 800;

int arr[2][MAXN];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n;
		scanf("%d", &n);
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &arr[k][i]);
			}
		}
		sort(arr[0], arr[0] + n);
		sort(arr[1], arr[1] + n, greater<int>());
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += (long long) arr[0][i] * arr[1][i];
		}
		cout << "Case #" << caseIndex << ": " << ans << endl;
	}
	
	return 0;
}
