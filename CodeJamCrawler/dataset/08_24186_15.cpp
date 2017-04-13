#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p, k, l;
		std::cin >> p >> k >> l;
		std::vector<int> freq(l);
		for (int j = 0; j < l; ++j)
			std::cin >> freq[j];
		std::sort(freq.begin(), freq.end());
		unsigned long long sum = 0;
		int key = 1;
		int rem = k;
		for (int j = l - 1; j >= 0; --j) {
			if (rem == 0) {
				++key;
				rem = k;
			}
			sum += freq[j] * key;
			--rem;
		}
		std::cout << "Case #" << i << ": " << sum << std::endl;
	}
}
 
