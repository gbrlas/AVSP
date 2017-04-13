#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool check(vector <long long> &v, vector <int> &perm) {
	int stat = 0;
	int maxid = -1;

	for (int i = 0; i < v.size(); i++) {
		if (maxid == -1 || v[perm[maxid] - 1] < v[perm[i] - 1]) {
			maxid = i;
		}
	}

	for (int i = 1; i < maxid; i++) {
		if (v[perm[i] - 1] < v[perm[i - 1] - 1]) {
			return false;
		}
	}

	for (int i = maxid + 1; i < v.size(); i++) {
		if (v[perm[i] - 1] > v[perm[i - 1] - 1]) {
			return false;
		}
	}
	return true;
}

long long get_res(vector <int> &perm) {
	int N = perm.size();
	long long res = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (perm[j] > perm[i]) {
				res++;
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		cerr << perm[i] << " ";
	}
	cerr << endl << res << endl;*/
	return res;
}

int main(int argc, char *argv[])
{
    int T = 0;
	
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("B-small.out", "w+", stdout);
   
	cin >> T;
	
	for (int cas = 1; cas <= T; cas++){
		int N = 0;
		vector <long long> v;
		vector <int> perm;
		cin >> N;

		for (int i = 0; i < N; i++) {
			long long t = 0;
			cin >> t;

			v.push_back(t);
			perm.push_back(i + 1);
		}

		long long res = 2147483647;
		do {
			if (check(v, perm)) {
				long long tmp = get_res(perm);
				res = std::min(res, tmp);
			}
		} while (next_permutation(perm.begin(), perm.end()));

		cout << "Case #" << cas << ": " << res << endl;
	}
    return 0;
}
