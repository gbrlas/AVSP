#include <iostream>
#include <set>
using namespace std;

set<int> read_row(int row_num)
{
	for (int i = 0; i < row_num - 1; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
	}
	set<int> res;
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		res.insert(a);
	}
	for (int i = 0; i < 4 - row_num; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
	}
	return res;
}

void test(int n)
{
	int row1_n, row2_n;
	cin >> row1_n;
	set<int> row1{read_row(row1_n)};
	cin >> row2_n;
	set<int> row2{read_row(row2_n)};
	int cnt = 0, result;
	for(auto & val : row1)
		if (row2.find(val) != row2.end())
		{
			cnt++;
			result = val;
		}
	cout << "Case #" << n << ": ";
	if (cnt == 0) cout << "Volunteer cheated!\n";
	else if (cnt == 1) cout << result << endl;
	else cout << "Bad magician!\n";
}

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
		test(i);
}