#include <vector>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <assert.h>
 
using namespace std;
 
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

typedef vector<int> IV;

int do_it()
{
	int P, K, L;
	cin >> P >> K >> L;
	IV freqv;

	for (int i = 0; i < L; i++) {
		int tmp;
		cin >> tmp;
		freqv.push_back(tmp);
	}

	sort (freqv.begin(), freqv.end(), greater<int>());

	vector< vector<int> > key;
	key.resize(K);

	for (int i = 0; i < key.size(); i++)
		key[i].clear();
	
	assert (key.size() == K);
	
	int kid = 0;
	for (int i = 0; i < L; i++, kid=(kid+1) % K) {
		if (key[kid].size() >= P) {
			continue;
		}
		key[kid].push_back(freqv[i]);
	}

	int res = 0;
	for (int i = 0; i < K; i++) {
		//cout << "Key:" << i << ": ";
		for (int j = 0; j < key[i].size(); j++) {
			//cout << key[i][j] << " ";
			res += key[i][j] * (j+1);
		}
		//cout << endl;
	}

	for (int i = 0; i < L; i++) {
		//cout << freqv[i] << " " ;
	}
	//cout << endl;
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n+1; i++)
		printf ("Case #%d: %d\n", i, do_it());
}
