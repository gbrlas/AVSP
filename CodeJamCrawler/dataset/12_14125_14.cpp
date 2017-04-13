#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>

using namespace std;

template<int N>
int FirstBit(const bitset<N> &s, bool value)
{
	for(int i = 0; i < N; ++i)
		if(s[i] == value)
			return i;

	return -1;
}

template<class T>
struct array2d
{
	vector<T> data;
	int rows, columns;

	array2d() {}

	array2d(int size):rows(size), columns(size)
	{
		data.resize(rows * columns);
	}

	array2d(int _rows, int _columns):rows(_rows), columns(_columns)
	{
		data.resize(rows * columns);
	}

	typename vector<T>::iterator operator[](int r)
	{
		return data.begin() + r * columns;
	}
};

void SolveCase()
{
	int N;
	cin >> N;
	vector<int> d(N), l(N);
	for(int i = 0; i < N; ++i)
		cin >> d[i] >> l[i];
	int D;
	cin >> D;

	d.push_back(D);
	vector<int> mins(N + 1);
	mins[N] = 0;
	for(int i = N - 1; i >= 0; --i)
	{
		int m = -1;
		for(int j = i + 1; j <= N; ++j)
			if(d[i] + l[i] >= d[j] && mins[j] >= 0 && d[j] - d[i] >= mins[j])
			{
				int mm = d[j] - d[i];
				if(m == -1 || mm < m)
					m = mm;
			}

		mins[i] = m;
	}

	if(mins[0] != -1 && d[0] >= mins[0])
		cout << "YES";
	else
		cout << "NO";
}

void main()
{
	int testCases;
	cin >> testCases;
	for(int i = 0; i < testCases; ++i)
	{
		cout << "Case #" << (i + 1) << ": ";
		SolveCase();
		cout << endl;
	}
}