#include <cstdio>
#include <vector>
using namespace std;

const int mod = 1000000007;

int pow(int a, int b)
{
	int ret = 1;
	for(int i = 0; i < b; ++i)
		ret *= a;
	return ret;
}

int count_prefix(vector<char> &a, vector<char> &b)
{
	int l = min(a.size(), b.size());
	for(int i = 0; i < l; ++i) {
		if(a[i] != b[i])
			return i;
	}
	return l;
}

int calc_cost(vector<vector<char> > &s, vector<int> &as, int n)
{
	int m = s.size();
	int cost = 0;

	for(int server = 0; server < n; ++server) {
		int count = 0;
		for(int pivot = 0; pivot < m; ++pivot) {

			if(as[pivot] != server) continue;

			int l = s[pivot].size();
			int c = l;

			for(int i = 0; i < pivot; ++i) {
				if(as[i] != server) continue;
				c = min(c, l - count_prefix(s[pivot], s[i]));
			}

			cost += c;
			count += 1;
		}
		if(count > 0) cost += 1;
	}

	return cost;
}

int main()
{
	int test_case_num;

	scanf("%d", &test_case_num);

	for(int test_case = 0; test_case < test_case_num; ++test_case) {

		int m, n;
		int max_part;
		vector<int> as;
		vector<vector<char> > s;
		int ans_cost = 0, ans_count = 0;

		scanf("%d%d", &m, &n);
		max_part = pow(n, m);
		s.resize(m);
		for(int i = 0; i < m; ++i) {
			char buf[128];
			scanf("%s", buf);
			for(int j = 0; buf[j] != '\0'; ++j)
				s[i].push_back(buf[j]);
		}

		for(int part = 0; part < max_part; ++part) {

			as.resize(m);
			for(int i = 0; i < m; ++i)
				as[i] = (part / pow(n, i)) % n;
			int cost = calc_cost(s, as, n);
			if(ans_cost < cost) {
				ans_cost = cost;
				ans_count = 1;
			} else if(ans_cost == cost) {
				ans_count += 1;
			}
		}

		printf("Case #%d: %d %d\n", test_case + 1, ans_cost, ans_count);
	}

	return 0;
}