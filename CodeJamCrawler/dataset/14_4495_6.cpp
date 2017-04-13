#include <fstream>

using namespace std;

int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	for (size_t l = 0; l < t; ++l)
	{
		int a[16];
		int b[16];
		int f, s;
		cin >> f;
		for (size_t i = 0; i < 16; ++i)
			cin >> a[i];
		cin >> s;
		for (size_t i = 0; i < 16; ++i)
			cin >> b[i];
		int row1[4], row2[4];
		for (size_t i = 0; i < 4; ++i)
		{
			row1[i] = a[(f - 1) * 4 + i];
			row2[i] = b[(s - 1) * 4 + i];
		}
		int count = 0;
		int res = 0;
		for (size_t i = 0; i < 4; ++i)
		{
			for (size_t j = 0; j < 4; ++j)
			{
				if (row1[j] == row2[i])
				{
					++count;
					res = row1[j];
				}
			}
		}
		cout << "Case #" << (l + 1) << ": ";
		switch (count)
		{
		case 0:
			cout << "Volunteer cheated!";
			break;
		case 1:
			cout << res;
			break;
		default:
			cout << "Bad magician!";
			break;
		}
		cout << endl;
	}
}