#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

bool canDivide(int* hand, int n, int l)
{
	multiset<pair<bool, int> > cards;
	multiset<pair<bool, int> >::iterator c;
	int i;
	for(i = 0; i < n; i++) cards.insert(make_pair(false, hand[i]));
	while(!cards.empty())
	{
		if (cards.begin() -> first) return true;
		int num = cards.begin() -> second;
		cards.erase(cards.begin());
		for(int j = 1; j < l; j++)
		{
			++num;
			c = cards.find(make_pair(false, num));
			if (c != cards.end()) cards.erase(c);
			else {
				c = cards.find(make_pair(true, num));
				if (c != cards.end()) cards.erase(c);
				else return false;
			}
		}
		while(true)
		{
			++num;
			c = cards.find(make_pair(false, num));
			if (c == cards.end()) break;
			cards.erase(c);
			cards.insert(make_pair(true, num));
		}
	}

	return true;
}

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	int T, number = 0;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int* hand = new int[N];
		for(int i = 0; i < N; i++) cin >> hand[i];
		int l = 0, r = N + 1, x;
		while (l < r - 1) 
		{
			x = (l + r) >> 1;
			if (canDivide(hand, N, x)) l = x; else r = x;
		}
		cout << "Case #" << ++number << ": " << l << endl;
	}

	return 0;
}