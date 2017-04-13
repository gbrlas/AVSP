#include <iostream>

using namespace std;

int main()
{
	int T, f1, f2, a[4][4], b[4][4], x = 1;
	cin >> T;
	while (T--) {
		cin >> f1;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> a[i][j];

		cin >> f2;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> b[i][j];

		int count = 0, num = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (a[f1-1][i] == b[f2-1][j]) {
					count++;
					num = a[f1-1][i];
				}

		if (count == 1)
			cout << "Case #" << x << ": " << num << endl;
		if (count > 1)
			cout << "Case #" << x << ": " << "Bad magician!" << endl;
		if (count == 0)
			cout << "Case #" << x << ": " << "Volunteer cheated!" << endl;
		x++;
	}

	return 0;
}
