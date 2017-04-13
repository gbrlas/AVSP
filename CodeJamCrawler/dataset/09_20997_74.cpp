#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

const int MAXN = 40;

char mat[MAXN][MAXN + 1];

int main() {
	int caseNum;
	cin >> caseNum;
	int arr[MAXN];
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
			arr[i] = 0;
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == '1') {
					arr[i] = j;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int j;
			for (j = i; arr[j] > i; j++);
			for (int k = j; k > i; k--) {
				swap(arr[k], arr[k - 1]);
				ans++;
			}
		}
		cout << "Case #" << caseIndex << ": " << ans << endl;
	}

	return 0;
}
