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
 
using namespace std;
 
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

typedef vector<int> IV;

int do_it()
{
	IV iva;
	IV ivb;	

	int count;
	cin >> count;

	for(int i =0; i < count; i++) {
		int tmp;
		cin >> tmp;
		iva.push_back(tmp);
	}
	
	for(int i =0; i < count; i++) {
		int tmp;
		cin >> tmp;
		ivb.push_back(tmp);
	}

	sort (iva.begin(), iva.end(), greater<int>());
	sort (ivb.begin(), ivb.end(), less<int>());

	int res = 0;
	for (int i = 0; i < count; i++) {
		res += iva[i] * ivb[i];
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n+1; i++)
		printf ("Case #%d: %d\n", i, do_it());
}
