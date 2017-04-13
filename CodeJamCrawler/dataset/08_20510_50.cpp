#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ev
{
	int tstamp;
	int s;
	ev(int t, int s)
	{
		tstamp = t;
		this->s = s;
	}
	bool operator<(const ev& e)
	{
		if (tstamp < e.tstamp) return true;
		if (tstamp > e.tstamp) return false;
		return s > e.s;
	}
};

bool less(const ev& e1, const ev& e2)
{
		if (e1.tstamp < e2.tstamp) return true;
		if (e1.tstamp > e2.tstamp) return false;
		return e1.s > e2.s;
}


int main()
{
//	freopen("A-large.in", "rt", stdin);
	int tc;
	cin >> tc;
	int n, na, nb;
	int tr;
	for (int t = 0; t < tc; t++)
	{
		cin >> tr >> na >> nb;
		int h1, m1, h2, m2;
		vector<ev> A, B;
		for (int i = 0; i < na; i++) {
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			A.push_back(ev(h1 * 60 + m1, -1));
			B.push_back(ev(h2 * 60 + m2 + tr, 1));
		}
		for (int i = 0; i < nb; i++) {
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			B.push_back(ev(h1 * 60 + m1, -1));
			A.push_back(ev(h2 * 60 + m2 + tr, 1));
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int ra = 0, rb = 0;
		int curr = 0;
		for (int i = 0; i < A.size(); i++)
		{
			curr += A[i].s;
			if (curr < 0) {
				ra++;
				curr++;
			}
		}
		curr = 0;
		for (int i = 0; i < B.size(); i++)
		{
			curr += B[i].s;
			if (curr < 0) {
				rb++;
				curr++;
			}
		}
		cout << "Case #" << t + 1 << ": " << ra << " " << rb << endl;
	}
}