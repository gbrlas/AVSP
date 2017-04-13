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
	for (int k=1; k<=tests; k++)
	{
		int turn;
		int na, nb;
		int inH, inM, start, end;
		char tmp;

		vector<pair<int, int> > fromA, fromB;

		cin >> turn >> na >> nb;
		for (int i=0; i<na + nb; i++)
		{
			cin >> inH >> tmp >> inM;
			start = inH * 60 + inM;

			cin >> inH >> tmp >> inM;
			end = inH * 60 + inM + turn;

			if (i < na)
				fromA.push_back(make_pair(start, end));
			else
				fromB.push_back(make_pair(start, end));
		}

		sort(fromA.begin(), fromA.end());
		sort(fromB.begin(), fromB.end());

		int sa = 0, sb = 0;
		multiset<int> arrA, arrB;
		arrA.insert(999999);
		arrB.insert(999999);

		int indA = 0, indB = 0;
		while (indA < na || indB < nb)
		{
			bool a;

			if (indA < na && indB < nb)
			{
				if (fromA[indA].first < fromB[indB].first)
					a = true;
				else
					a = false;
			}
			else if (indA < na)
				a = true;
			else
				a = false;

			if (a)
			{
				if (*arrA.begin() <= fromA[indA].first)
					arrA.erase(arrA.begin());
				else
					sa++;

				arrB.insert(fromA[indA].second);
				indA++;
			}
			else
			{
				if (*arrB.begin() <= fromB[indB].first)
					arrB.erase(arrB.begin());
				else
					sb++;

				arrA.insert(fromB[indB].second);
				indB++;
			}
		}

		cout << "Case #" << k << ": " << sa << " " << sb << endl;
	}

	return 0;
}