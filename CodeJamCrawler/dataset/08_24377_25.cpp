#include <map>
#include <string>
#include <iostream>

using namespace std;

bool solve(int P) {
	int s, q;
	map<string, int> es;
	{
		cin >> s;
		{
			string nl; getline(cin, nl);
		}
		for (int i = 0; i < s; ++i) {
			string engine; getline(cin, engine);
			es[engine] = i;
		}
	}
	int *best = new int[s];
	{
		for (int i = 0; i < s; ++i)
			best[i] = 0;
		cin >> q;
		{
			string nl; getline(cin, nl);
		}
		for (int i = 0; i < q; ++i) {
			string engine; getline(cin, engine);
			int e = es[engine];
			int min = q;
			for (int j = 0; j < s; ++j)
				if (j != e)
					if (best[j] < min)
						min = best[j];
			best[e] = min + 1;
		}
	}
	{
		int min = q;
		for (int j = 0; j < s; ++j)
			if (best[j] < min)
				min = best[j];
		cout << "Case #" << P + 1 << ": " << min << endl;
	}
	delete[] best;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		solve(i);
	return 0;
}
