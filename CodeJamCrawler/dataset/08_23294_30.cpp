#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>


using namespace std;

int main()
{
	int tests;

	cin >> tests;
	for (int l=1; l<=tests; l++)
	{
		int K, n;

		cin >> K >> n;

		vector<int> indices(n);
		for (int i=0; i<n; i++)
			cin >> indices[i];

		vector<int> pos(K);
		for (int i=0; i<K; i++)
			pos[i] = i;

		vector<int> cards(K);

		int cur = 0, remain = K;
		for (int i=1; i<=K; i++)
		{
			cards[pos[(cur + i - 1) % remain]] = i;
			pos.erase(pos.begin() + (cur + i - 1) % remain);
			cur = (cur + i - 1) % remain;
			remain--;
		}

		cout << "Case #" << l << ": ";
		for (int i=0; i<indices.size(); i++)
			cout << cards[indices[i] - 1] << " ";
		cout << endl;
	}

	return 0;
}