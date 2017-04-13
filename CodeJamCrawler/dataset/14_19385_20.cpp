#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class arc {
public:
	int size;
	bool label;

	arc(int _s) {
		size = _s;
		label = true;
	}
};

bool operator < (const arc &a, const arc &b) {
	return a.size < b.size;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	cin >> T;
	
	for (int cas = 1; cas <= T; cas++) {
		int N = 0, M = 0;
		cin >> N >> M;
		vector <arc> v;
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			cin >> tmp;
			v.push_back(arc(tmp));
		}

		sort(v.begin(), v.end());

		int res = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (v[i].label == true) {
				v[i].label = false;
				res++;

				for (int j = N - 1; j >= 0; j--) {
					if (v[j].label == true && v[i].size + v[j].size <= M) {
						v[j].label = false;
						break;
					}
				}
			}
		}

		v.clear();

		cout << "Case #" << cas << ": " << res << endl;
	}
    return 0;
}
