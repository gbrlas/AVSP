#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <hash_map>



typedef std::pair<int, int> PI;
std::hash_map<int, std::vector<int> > nums;


int shift_num (int x, int s) 
{
	int w = 10;
	for (int i = 1; i < s; ++i) w *= 10;
	int l = x % w, z = 1, c = x / w;
	while (c > 0) {
		c /= 10; z *= 10;
	}
	x /= w;
	x += l * z;
	
	return x;
}

bool repeated (int a, int b) 
{
	if (nums.find (a) == nums.end()) {
		nums[a].push_back (b);
		return false;
	} else {
		auto it = std::find (nums[a].begin(), nums[a].end(), b);
		if (it == nums[a].end()) {
			nums[a].push_back (b);
			return false;
		} else {
			return true;
		}
	}
}

int check (int base, int loop, int limit) 
{
	int p = base, ret = 0;
	for (int i = 1; i <= loop; ++i) {
		p = shift_num (base, i);
		if (p > base && p <= limit) {
			if (!repeated (base, p)) ++ret;
		}
	}

	return ret;
}


int main()
{
	int T; std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		int A, B, res = 0;
		nums.clear();
		std::cin >> A >> B;
		for (int i = A; i <= B; ++i) {
			if (i > 1000000) {
				res += check (i, 6, B);
			} else if (i > 100000) { 
				res += check (i, 5, B);
			} else if (i > 10000) {
				res += check (i, 4, B);
			} else if (i > 1000) {
				res += check (i, 3, B);
			} else if (i > 100) {
				res += check (i, 2, B);
			} else if (i > 10) {
				res += check (i, 1, B);
			}
		}
		std::cout << "Case #" << c << ": " << res << '\n';
	}

	return 0;
}