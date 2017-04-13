#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <numeric>
#include <iterator>

#define foreach(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

using namespace std;

int main() {
	int nn;
	cin >> nn;
	
	for(size_t ii = 0; ii < nn; ++ii)
	{
		int N, M, A;
		cin >> N >> M >> A;
		
		cout << "Case #" << ii+1 << ": ";

		if (N * M < A) {
			cout << "IMPOSSIBLE" << endl;
			goto next;
		}

		int t;
		for(size_t i = 0; i <= N; ++i)
		{
			for(size_t j = 0; j <= M; ++j)
			{
				for(size_t k = 0; k <= N; ++k)
				{
					for(size_t l = 0; l <= M; ++l)
					{
						t = i*l - j*k;
						if(t == A || t == -A) {
							cout << "0 0 " << i << " " << j << " " << k << " " << l << endl;
							goto next;
						}
					}
				}
			}
		}
		
		next: 1;
	}
}